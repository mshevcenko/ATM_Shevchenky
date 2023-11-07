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
	Card* ccP = g_CardDao.getByNumber(cardNumber);
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
	return g_AccountDao.edit(currentAccount());
}

vector<pair<Currency, unsigned int>> ATM::withdraw(unsigned int ammount)
{

	vector<pair<Currency, unsigned int>> res = vector<pair<Currency, unsigned int>>();

	for (int i = 0; i < SIZE_OF_BILLS_ARRAY; i++) {
		uint32_t billsAmount = ammount / BILLS[i];
		billsAmount = min(billsAmount, this->_currencyStorage[BILLS[i]]);
		res.push_back(pair(BILLS[i], billsAmount));
		ammount -= BILLS[i] * billsAmount;
	}

	if (ammount == 0) {
		//do provide money
		WithdrawalService ws(currentCardNumber(), ammount, id());
		if (Bank::proceedWithdrawalService(ws) == 1) {
			for (int i = 0; i < SIZE_OF_BILLS_ARRAY; i++) {
				this->_currencyStorage[BILLS[i]] -= res.at(SIZE_OF_BILLS_ARRAY - 1 - i).second; //maybe reverse order
			}
			return res;
		}
	}

	return vector<pair<Currency, unsigned int>>();
}

bool ATM::createOverflowService(const OverflowService& service)
{
	bool res = Card::checkIfCardIsValid(service.from());
	res &= Card::checkIfCardIsValid(service.to());
	if (res) {
		return g_OverflowServiceDao.create(service);
	}
	return res;
}

bool ATM::createOverflowCreditService(OverflowCreditService service)
{
	service.setFrom(currentCardNumber());
	bool res = Card::checkIfCardIsValid(service.from());
	res &= Card::checkIfCardIsValid(service.to());
	if (res) {
		return g_OverflowCreditServiceDao.create(service);
	}
	return res;
}

bool ATM::hasOverflowService()
{
	vector<OverflowService> owss = g_OverflowServiceDao.getByFrom(currentCardNumber());
	if (owss.size() > 0) {
		return true;
	}
	return false;
}

OverflowService ATM::getOverflowService()
{
	vector<OverflowService> owss = g_OverflowServiceDao.getByFrom(currentCardNumber());
	return owss.front();
}

vector<OverflowCreditService> ATM::getOverflowCreditServices()
{
	return g_OverflowCreditServiceDao.getByFrom(currentCardNumber());
}

bool ATM::deleteOverflowService(const OverflowService& service)
{
	return g_OverflowServiceDao.remove(service);
}

bool ATM::deleteOverflowCreditService(const OverflowCreditService& service)
{
	return g_OverflowCreditServiceDao.remove(service);
}

vector<Transfer> ATM::getTransfers()
{
	vector<Transfer> out = g_TransferDao.getByFrom(currentCardNumber());
	vector<Transfer> in = g_TransferDao.getByTo(currentCardNumber());
	
	for (std::vector<Transfer>::iterator it = in.begin(); it != in.end(); ++it) {
		(*it).setAmount(Bank::calculateFeeRecive((*it).amount()));
	}

	std::sort(out.begin(), out.end(), &Transfer::dateCmp); //maybe not needed
	std::sort(in.begin(), in.end(), &Transfer::dateCmp); //maybe not needed

	vector<Transfer> res = vector<Transfer>(out.size() + in.size());
	std::merge(out.begin(), out.end(), in.begin(), in.end(), res.begin(), &Transfer::dateCmp);
	std::cout << res.size() << std::endl;
	return res;
}

vector<WithdrawalService> ATM::getWithdrawalServices()
{
	vector<WithdrawalService> services = g_WithdrawalServiceDao.getByFrom(currentCardNumber());
	sort(services.begin(), services.end(), &WithdrawalService::dateCmp);
	return services;
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

bool ATM::createTransferDaemon(const TransferDaemon& transferDaemon)
{
	bool res = Card::checkIfCardIsValid(transferDaemon.from());
	res &= Card::checkIfCardIsValid(transferDaemon.to());
	if (res) {
		return g_TransferDaemonDao.create(transferDaemon);
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
	return g_TransferDaemonDao.getByFrom(currentCardNumber());
}

bool ATM::editTransfer(const TransferDaemon& transferDaemon)
{
	bool res = Card::checkIfCardIsValid(transferDaemon.from());
	res &= Card::checkIfCardIsValid(transferDaemon.to());
	if (res) {
		return g_TransferDaemonDao.edit(transferDaemon);
	}
	return false;
}

bool ATM::deleteTransfer(const TransferDaemon& transferDaemon)
{
	return g_TransferDaemonDao.remove(transferDaemon);
}

bool ATM::createCardAndAccount(const string& cardNumber, const string& pinCode, double balance, time_t expiryDate, const size_t bankId)
{
	Account acc = Account(0, 0, balance, bankId);
	if (g_AccountDao.create(acc)) {
		size_t accid = Toolbox::getLastCreatedAccountId(bankId);
		Card card = Card(cardNumber, pinCode, accid, expiryDate, Card::Credit);
		if (g_CardDao.create(card)) {
			return true;
		}
		else {
			g_AccountDao.remove(Account(accid));
		}
	}
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
	Card *cc = g_CardDao.getByAccount(currentAccount());
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
	_currentAccount = g_AccountDao.getByCardNumber(_currentCardNumber);
}

void ATM::saveToDB()
{
	exit();
	g_AtmDao.edit(*this);
}

void ATM::doIncasators()
{
	Bank* bank = g_BankDao.getById(bankId());
	if (bank == nullptr) {
		return;
	}
	bank->doIncasators();
	delete bank;
}


//int ATM::provideMoney(Money money)
//{
//	uint32_t planedToBeGivenBills[sizeof(BILLS)/sizeof(Currency)];
//	
//	for (int i = 0; i < SIZE_OF_BILLS_ARRAY; i++) {
//		planedToBeGivenBills[i] = money / BILLS[i];
//		planedToBeGivenBills[i] = min(planedToBeGivenBills[i], this->_currencyStorange[BILLS[i]]);
//		money -= BILLS[i] * planedToBeGivenBills[i];
//	}
//	
//	if (money == 0) {
//		//do provide money
//
//		for (int i = 0; i < SIZE_OF_BILLS_ARRAY; i++) {
//			this->_currencyStorange[BILLS[i]] -= planedToBeGivenBills[i];
//		}
//
//		return 1;
//	}
//	else {
//		//not enought money in ATM
//		return -1;
//	}
//	return 0;
//}


