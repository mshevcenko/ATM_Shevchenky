#include <algorithm>

#include "ATM.h"

#include "Bank.h"

#include "OverflowService.h"
#include "OverflowCreditService.h"
#include "Transfer.h"
#include "TransferDaemon.h"
#include "WithdrawalService.h"

#include "autil.h"
#include "MoneyStorage.h"

ATM::ATM(const Bank& bank) : _currentAccount(nullptr), _id(0), _bankId(bank.id()) {
	_currencyStorage = std::map<Currency, uint32_t>();
	for (int i = 0; i < SIZE_OF_BILLS_ARRAY; i++) {
		_currencyStorage.insert(std::make_pair(BILLS[i], 0));
	}
	
}

ATM::ATM(const size_t& bankId) : ATM(0, bankId) { }
ATM::ATM(const size_t& id, const size_t& bankId) : _id(id), _bankId(bankId), _currentAccount(nullptr){
	_currencyStorage = std::map<Currency, uint32_t>();
	for (int i = 0; i < SIZE_OF_BILLS_ARRAY; i++) {
		_currencyStorage.insert(std::make_pair(BILLS[i], 0));
	}
}

ATM::ATM(const size_t& id, const size_t& bankId, const map<Currency, unsigned int>& currencyStorage) : _id(id), _bankId(bankId), _currencyStorage(currencyStorage) {}
ATM::ATM(const ATM& ss) : _id(ss._id), _bankId(ss._bankId), _currencyStorage(ss._currencyStorage), _currentCardNumber(ss._currentCardNumber), _currentAccount(nullptr) {}

ATM::~ATM(){
	if (_currentAccount != nullptr) {
		delete _currentAccount;
		_currentAccount = 0;
	}
}


void ATM::clearCurrencyStorage()
{
	for (int i = 0; i < SIZE_OF_BILLS_ARRAY; i++) {
		_currencyStorage[BILLS[i]] = 0;
	}
}

void ATM::updateUsingMoneyStorage(vector<MoneyStorage> msv)
{
	clearCurrencyStorage();
	
	for (std::vector<MoneyStorage>::iterator it = msv.begin(); it != msv.end(); ++it) {
		_currencyStorage[(*it).denomination()] = (*it).amount();
	}
}

bool ATM::isExpired(const string& cardNumber)
{
	Card* ccP = Toolbox::getToolbox().g_CardDao().getByNumber(cardNumber);
	if (ccP == nullptr) {
		return true;
	}
	bool rr = ccP->isExpiredBeforeDate(Toolbox::getCurrentDate());
	delete ccP;

	return rr;
}

bool ATM::insertCard(const string& cardNumber, const string& pinCode)
{
	exit();
	_currentAccount = Bank::getAccountByCredentials(cardNumber, pinCode);
	if (_currentAccount == nullptr) {
		return false;
	}
	_currentCardNumber = cardNumber;
	return true;
}

void ATM::doTransferService(Transfer ss)
{
	Bank::proceedTransfer(ss);
}

void ATM::doWithdrawalService(WithdrawalService ss)
{
	Bank::proceedWithdrawalService(ss);
}

void ATM::exit() {
	if (_currentAccount != nullptr) {
		delete _currentAccount;
	}
	_currentAccount = nullptr;
	_currentCardNumber = "";
}

bool ATM::checkPinCode(const string& pin)
{
	return Bank::checkCredentials(currentCardNumber(), pin);
}

bool ATM::changeCreditLimit(double newCreditLimit)
{
	currentAccount().changeCreditLimit(newCreditLimit);
	return Toolbox::getToolbox().g_AccountDao().edit(currentAccount());
}

vector<pair<Currency, unsigned int>> ATM::withdraw(const size_t ammount)
{
	size_t ammountRemainToGive = ammount;
	vector<pair<Currency, unsigned int>> res = vector<pair<Currency, unsigned int>>();

	for (int i = 0; i < SIZE_OF_BILLS_ARRAY; i++) {
		uint32_t billsAmount = ammountRemainToGive / BILLS[i];
		billsAmount = min(billsAmount, this->_currencyStorage[BILLS[i]]);
		res.push_back(pair<Currency, uint32_t>(BILLS[i], billsAmount));
		ammountRemainToGive -= BILLS[i] * billsAmount;
	}

	if (ammountRemainToGive == 0) {
		//do provide money
		WithdrawalService ws(currentCardNumber(), ammount, id());
		if (Bank::proceedWithdrawalService(ws) == 1) {
			for (int i = 0; i < SIZE_OF_BILLS_ARRAY; i++) {
				this->_currencyStorage[BILLS[i]] -= res.at(i).second; //maybe reverse order
			}
			return res;
		}
	}

	return vector<pair<Currency, unsigned int>>();
}

bool ATM::createOverflowService(OverflowService& service)
{
	service.setFrom(currentCardNumber());
	bool res = Card::checkIfCardIsValid(service.from());
	res &= Card::checkIfCardIsValid(service.to());
	if (res) {
		if (Toolbox::getToolbox().g_OverflowServiceDao().create(service)) {
			Bank::proceedOverflowService(service);
			return true;
		}
	}
	return false;
}

bool ATM::createOverflowCreditService(OverflowCreditService service)
{
	service.setFrom(currentCardNumber());
	bool res = Card::checkIfCardIsValid(service.from());
	res &= Card::checkIfCardIsValid(service.to());
	if (res) {
		if (Toolbox::getToolbox().g_OverflowCreditServiceDao().create(service)) {
			Bank::proceedOverflowCreditService(service);
			return true;
		}
	}
	return false;
}

bool ATM::hasOverflowService()
{
	vector<OverflowService> owss = Toolbox::getToolbox().g_OverflowServiceDao().getByFrom(currentCardNumber());
	if (owss.size() > 0) {
		return true;
	}
	return false;
}

OverflowService ATM::getOverflowService()
{
	vector<OverflowService> owss = Toolbox::getToolbox().g_OverflowServiceDao().getByFrom(currentCardNumber());
	return owss.front();
}

vector<OverflowCreditService> ATM::getOverflowCreditServices()
{
	return Toolbox::getToolbox().g_OverflowCreditServiceDao().getByFrom(currentCardNumber());
}

bool ATM::deleteOverflowService(const OverflowService& service)
{
	return Toolbox::getToolbox().g_OverflowServiceDao().remove(service);
}

bool ATM::deleteOverflowCreditService(const OverflowCreditService& service)
{
	return Toolbox::getToolbox().g_OverflowCreditServiceDao().remove(service);
}

vector<Transfer> ATM::getTransfers()
{
	vector<Transfer> out = Toolbox::getToolbox().g_TransferDao().getByFrom(currentCardNumber());
	vector<Transfer> in = Toolbox::getToolbox().g_TransferDao().getByTo(currentCardNumber());
	
	for (std::vector<Transfer>::iterator it = in.begin(); it != in.end(); ++it) {
		(*it).setAmount(Bank::calculateFeeRecive((*it).amount()));
	}

	//std::sort(out.begin(), out.end(), Transfer::dateCmpR); //maybe not needed
	//std::sort(in.begin(), in.end(), Transfer::dateCmpR); //maybe not needed

	//vector<Transfer> res = vector<Transfer>(out.size() + in.size());
	//std::merge(out.begin(), out.end(), in.begin(), in.end(), res.begin(), Transfer::dateCmp);
	std::move(out.begin(), out.end(), std::back_inserter(in));
	std::sort(in.begin(), in.end(), Transfer::dateCmpR);

	return in;
}

vector<WithdrawalService> ATM::getWithdrawalServices()
{
	vector<WithdrawalService> ss = Toolbox::getToolbox().g_WithdrawalServiceDao().getByFrom(currentCardNumber());
	std::sort(ss.begin(), ss.end(), WithdrawalService::dateCmpR);
	return ss;
}

bool ATM::createTransfer(Transfer transfer)
{
	transfer.setFrom(currentCardNumber());
	bool res = Card::checkIfCardIsValid(transfer.from());
	res &= Card::checkIfCardIsValid(transfer.to());
	if (res) {
		return Bank::proceedTransfer(transfer) == 1;
	}
	return false;
}

bool ATM::createTransferDaemon(TransferDaemon transferDaemon)
{
	transferDaemon.setFrom(currentCardNumber());
	bool res = Card::checkIfCardIsValid(transferDaemon.from());
	res &= Card::checkIfCardIsValid(transferDaemon.to());
	if (res) {
		if (Toolbox::getToolbox().g_TransferDaemonDao().create(transferDaemon)) {
			Bank::proceedTransferDaemon(transferDaemon);
			return true;
		}
	}
	return false;
}

double ATM::getCommission()
{
	return g_FEE;
}

double ATM::calculateFeeSend(double money)
{
	return Bank::calculateFeeSend(money);
}

double ATM::calculateFeeReceived(double money)
{
	return Bank::calculateFeeRecive(money);
}

vector<TransferDaemon> ATM::getTransferDaemons()
{
	return Toolbox::getToolbox().g_TransferDaemonDao().getByFrom(currentCardNumber());
}

bool ATM::editTransferDaemon(const TransferDaemon& transferDaemon)
{
	bool res = Card::checkIfCardIsValid(transferDaemon.from());
	res &= Card::checkIfCardIsValid(transferDaemon.to());
	if (res) {
		return Toolbox::getToolbox().g_TransferDaemonDao().edit(transferDaemon);
	}
	return false;
}

bool ATM::deleteTransferDaemon(const TransferDaemon& transferDaemon)
{
	return Toolbox::getToolbox().g_TransferDaemonDao().remove(transferDaemon);
}

bool ATM::createCardAndAccount(const string& cardNumber, const string& pinCode, double balance, time_t expiryDate, const size_t bankId)
{
	Account acc = Account(0, 0, balance, bankId);
	Card card = Card(cardNumber, pinCode, 0, expiryDate, Card::Credit);
	return Toolbox::getToolbox().g_BankDao().addAccountAndCardByBankId(bankId, acc, card);

	/*Account acc = Account(0, 0, balance, bankId);
	if (g_AccountDao.create(acc)) {
		size_t accid = Toolbox::getLastCreatedAccountId(bankId);
		Card card = Card(cardNumber, pinCode, accid, expiryDate, Card::Credit);
		if (g_CardDao.create(card)) {
			return true;
		}
		else {
			g_AccountDao.remove(Account(accid));
		}
	}*/
	return false;
}

void ATM::nextDay()
{
	Bank::triggerNextDayForBank(bankId());
}

double ATM::getBalance()
{
	return _currentAccount->balance();
}

double ATM::getCreditLimit()
{
	return _currentAccount->creditLimit();
}

time_t ATM::getExpiryDate()
{
	Card *cc = Toolbox::getToolbox().g_CardDao().getByAccount(currentAccount());
	time_t res = 0;
	if (cc != nullptr) {
		res = cc->expiryDate();
		delete cc;
	}
	return res;
}

void ATM::updateData()
{
	if (_currentAccount != nullptr) {
		delete _currentAccount;
	}
	_currentAccount = Toolbox::getToolbox().g_AccountDao().getByCardNumber(_currentCardNumber);
}

void ATM::saveToDB()
{
	editAtmWithMoneyStorage(*this);
}

void ATM::doIncasators()
{
	Bank* bank = Toolbox::getToolbox().g_BankDao().getById(bankId());
	if (bank == nullptr) {
		return;
	}
	bank->doIncasators();
	auto msv = Toolbox::getToolbox().g_MoneyStorageDao().getAllByAtmId(id());
	updateUsingMoneyStorage(msv);
	delete bank;
}




ATM* ATM::getAtmWithMoneyStorage(const size_t id) {
	ATM* atm = Toolbox::getToolbox().g_AtmDao().getById(id);
	if (atm == nullptr) {
		return nullptr;
	}
	vector<MoneyStorage> msv = Toolbox::getToolbox().g_MoneyStorageDao().getAllByAtmId(id);
	atm->updateUsingMoneyStorage(msv);
	return atm;
}

bool ATM::createAtmWithMoneyStorage(const ATM& atmData) {
	return createAtmWithMoneyStorage(atmData, atmData.currencyStorage());
}

bool ATM::createAtmWithMoneyStorage(const ATM& atmData, const map<Currency, unsigned int>& currencyStorage) {
	if (!Toolbox::getToolbox().g_AtmDao().create(atmData)) {
		return false;
	}
	//g_AtmDao.getAllByBankId();
	size_t aid = Toolbox::getLastCreatedAtmIdByBank(atmData.bankId());

	bool isCreatedCurrency = true;
	for (auto it = currencyStorage.begin(); it != currencyStorage.end() && isCreatedCurrency; ++it) {
		MoneyStorage bill = MoneyStorage(MoneyStorage::Denomination((*it).first), (*it).second, aid);
		isCreatedCurrency = Toolbox::getToolbox().g_MoneyStorageDao().create(bill);
	}
	if (!isCreatedCurrency) {
		auto moneyTodelete = Toolbox::getToolbox().g_MoneyStorageDao().getAllByAtmId(aid);
		for (auto it = moneyTodelete.begin(); it != moneyTodelete.end(); ++it) {
			Toolbox::getToolbox().g_MoneyStorageDao().remove(*it);
		}
		Toolbox::getToolbox().g_AtmDao().remove(ATM(aid, 0));
	}
	return isCreatedCurrency;
}

bool ATM::deleteAtmWithMoneyStorage(const size_t& aid) {
	bool deletedAllMoney = true;
	auto moneyTodelete = Toolbox::getToolbox().g_MoneyStorageDao().getAllByAtmId(aid);
	for (auto it = moneyTodelete.begin(); it != moneyTodelete.end() && deletedAllMoney; ++it) {
		deletedAllMoney = Toolbox::getToolbox().g_MoneyStorageDao().remove(*it);
	}
	return Toolbox::getToolbox().g_AtmDao().remove(ATM(aid, 0)) && deletedAllMoney;
}

bool ATM::editAtmWithMoneyStorage(const ATM& atmData) {
	return editAtmWithMoneyStorage(atmData, atmData.currencyStorage());
}

bool ATM::editAtmWithMoneyStorage(const ATM& atmData, const map<Currency, unsigned int>& currencyStorage) {
	if (!Toolbox::getToolbox().g_AtmDao().edit(atmData)) {
		return false;
	}

	bool isEditedCurrency = true;
	for (auto it = currencyStorage.begin(); it != currencyStorage.end() && isEditedCurrency; ++it) {
		MoneyStorage* ms = Toolbox::getToolbox().g_MoneyStorageDao().getByDenominationAndAtmId(MoneyStorage::Denomination((*it).first), atmData.id());
		if (ms == nullptr) {
			isEditedCurrency = Toolbox::getToolbox().g_MoneyStorageDao().create(MoneyStorage(MoneyStorage::Denomination((*it).first), (*it).second, atmData.id()));
			continue;
		}
		size_t msid = ms->id();
		MoneyStorage bill = MoneyStorage(msid, MoneyStorage::Denomination((*it).first), (*it).second, atmData.id());
		isEditedCurrency = Toolbox::getToolbox().g_MoneyStorageDao().edit(bill);
	}

	return isEditedCurrency;
}

void ATM::fillWithMoney(const size_t ammountOfBills) {
	for (int i = 0; i < SIZE_OF_BILLS_ARRAY; i++) {
		(currencyStorage()[BILLS[i]]) = ammountOfBills;
	}
}


