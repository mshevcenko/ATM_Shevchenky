#include "Bank.h"
#include "OverflowService.h"
#include "OverflowCreditService.h"
#include "Transfer.h"
#include "ATM.h"
#include "WithdrawalService.h"

#include "autil.h"


Card Bank::getCardDataByCardNum(CardNumber cardNumber)
{
	return copyAndDeletePointer(Toolbox::getToolbox().g_CardDao().getByNumber(cardNumber));
}

ATM Bank::getATMbyId(int id)
{
	return copyAndDeletePointer(ATM::getAtmWithMoneyStorage(id));
}




Bank::Bank(const string& name) : Bank(0, name) { }
Bank::Bank(const size_t& id, const string& name) : _id(id), _name(name) { }
Bank::~Bank() { }
Bank::Bank(const Bank& ss) : Bank(ss._id, ss._name) {}

int Bank::proceedOverflowService(const OverflowService& ss)
{
	Card *fromCardP = Toolbox::getToolbox().g_CardDao().getByNumber(ss.from());
	if (fromCardP == nullptr || checkIfCardIsExpired(*fromCardP)) {
		Toolbox::getToolbox().g_OverflowServiceDao().remove(ss);
		return -2;
	}
	Card fromCard = copyAndDeletePointer(fromCardP);

	Card *toCardP = Toolbox::getToolbox().g_CardDao().getByNumber(ss.to());
	if (toCardP == nullptr || checkIfCardIsExpired(*toCardP)) {
		Toolbox::getToolbox().g_OverflowServiceDao().remove(ss);
		return -2;
	}
	Card toCard = copyAndDeletePointer(toCardP);

	if (fromCard.account().balance() > ss.threshold()) {
		Transfer trans(ss.from(), ss.to(), fromCard.account().balance() - ss.threshold());
		return proceedTransfer(trans);
	}
	return 0;
}

int Bank::proceedOverflowCreditService(const OverflowCreditService& ss)
{
	Card* fromCardP = Toolbox::getToolbox().g_CardDao().getByNumber(ss.from());
	if (fromCardP == nullptr || checkIfCardIsExpired(*fromCardP)) {
		Toolbox::getToolbox().g_OverflowCreditServiceDao().remove(ss);
		return -2;
	}
	Card fromCard = copyAndDeletePointer(fromCardP);

	Card* toCardP = Toolbox::getToolbox().g_CardDao().getByNumber(ss.to());
	if (toCardP == nullptr || checkIfCardIsExpired(*toCardP)) {
		Toolbox::getToolbox().g_OverflowCreditServiceDao().remove(ss);
		return -2;
	}
	Card toCard = copyAndDeletePointer(toCardP);

	if (toCard.account().balance() < ss.amount()) {
		//fromCard.account().availableMoney() --use if allowing to go in credit
		//max(fromCard.account().balance(), 0.0) --use if not allowing to go in credit
		double maxonacc = fromCard.account().availableMoney();
		return proceedTransfer(Transfer(ss.from(), ss.to(), min(maxonacc, calculateFeeSend(ss.amount() - toCard.account().balance()))));
	}
	return 0;
}

int Bank::proceedTransfer(Transfer ss)
{
	if (ss.amount() <= 0) {
		return -3;
	}
	Card* fromCardP = Toolbox::getToolbox().g_CardDao().getByNumber(ss.from());
	if (fromCardP == nullptr || checkIfCardIsExpired(*fromCardP)) {
		//g_TransferDao.remove(ss);
		return -2;
	}
	Card fromCard = copyAndDeletePointer(fromCardP);

	Card* toCardP = Toolbox::getToolbox().g_CardDao().getByNumber(ss.to());
	if (toCardP == nullptr || checkIfCardIsExpired(*toCardP)) {
		//g_TransferDao.remove(ss);
		return -2;
	}
	Card toCard = copyAndDeletePointer(toCardP);

	int status = proceedTransferActions(fromCard, toCard, ss.amount());
	if (status == 1) {
		Toolbox::getToolbox().g_TransferDao().create(ss); //chose maybe another place to write in db

		vector<OverflowService> ovss = Toolbox::getToolbox().g_OverflowServiceDao().getByFrom(toCard.cardNumber());
		for (std::vector<OverflowService>::iterator it = ovss.begin(); it != ovss.end(); ++it) {
			proceedOverflowService(*it);
		}
		vector<OverflowCreditService> ovcss = Toolbox::getToolbox().g_OverflowCreditServiceDao().getByTo(fromCard.cardNumber());
		for (std::vector<OverflowCreditService>::iterator it = ovcss.begin(); it != ovcss.end(); ++it) {
			proceedOverflowCreditService(*it);
		}
		vector<OverflowCreditService> ovcssrp = Toolbox::getToolbox().g_OverflowCreditServiceDao().getByFrom(fromCard.cardNumber());
		for (std::vector<OverflowCreditService>::iterator it = ovcssrp.begin(); it != ovcssrp.end(); ++it) {
			proceedOverflowCreditService(*it);
		}
	}

	return status;
}

int Bank::proceedTransferActions(Card& fromCard, Card& toCard, const Money& amount)
{
	if (fromCard.account().availableMoney() >= amount) {
		fromCard.changeBalance(-amount);
		Toolbox::getToolbox().g_AccountDao().edit(fromCard.account());
		toCard.changeBalance(calculateFeeRecive(amount));
		Toolbox::getToolbox().g_AccountDao().edit(toCard.account());
		return 1;
	}

	return -1;
}

int Bank::proceedTransferDaemon(TransferDaemon & ss)
{
	if (ss.amount() <= 0) {
		Toolbox::getToolbox().g_TransferDaemonDao().remove(ss);
		return -3;
	}
	
	if (ss.nextTransferDate() <= Toolbox::getCurrentDate()) {

		Card* fromCardP = Toolbox::getToolbox().g_CardDao().getByNumber(ss.from());
		if (fromCardP == nullptr || checkIfCardIsExpired(*fromCardP)) {
			Toolbox::getToolbox().g_TransferDaemonDao().remove(ss);
			return -2;
		}
		Card fromCard = copyAndDeletePointer(fromCardP);

		Card* toCardP = Toolbox::getToolbox().g_CardDao().getByNumber(ss.to());
		if (toCardP == nullptr || checkIfCardIsExpired(*toCardP)) {
			Toolbox::getToolbox().g_TransferDaemonDao().remove(ss);
			return -2;
		}
		Card toCard = copyAndDeletePointer(toCardP);


		ss.nextDate();
		Toolbox::getToolbox().g_TransferDaemonDao().edit(ss);
		if (ss.isActive()) {
			return proceedTransfer(Transfer(ss.from(), ss.to(), ss.amount()));
		}
	}
	
	return 0;
}

int Bank::proceedWithdrawalService(const WithdrawalService& ss)
{
	if (ss.amount() <= 0) {
		return -3;
	}
	Card* fromCardP = Toolbox::getToolbox().g_CardDao().getByNumber(ss.from());
	if (fromCardP == nullptr || checkIfCardIsExpired(*fromCardP)) {
		Toolbox::getToolbox().g_WithdrawalServiceDao().remove(ss);
		return -2;
	}
	Card fromCard = copyAndDeletePointer(fromCardP);
	
	int status = proceedWithdrawalActions(fromCard, ss.atmId(), ss.amount());
	if (status == 1) {
		Toolbox::getToolbox().g_WithdrawalServiceDao().create(ss); //chose maybe another place to write in db

		vector<OverflowCreditService> ovcss = Toolbox::getToolbox().g_OverflowCreditServiceDao().getByFrom(fromCard.cardNumber());
		for (std::vector<OverflowCreditService>::iterator it = ovcss.begin(); it != ovcss.end(); ++it) {
			proceedOverflowCreditService(*it);
		}
	}

	return status;
	
}

int Bank::proceedWithdrawalActions(Card& fromCard, int atmId, const Money& ammount) {
	if (fromCard.account().availableMoney() >= ammount) {
		ATM atm = getATMbyId(atmId);
		fromCard.changeBalance(-ammount);
		Toolbox::getToolbox().g_AccountDao().edit(fromCard.account());
		return 1;
	}
	return -1;
}

Account* Bank::getAccountByCredentials(const string& cardNumber, const string& pinCode)
{
	Card *cc = Toolbox::getToolbox().g_CardDao().getByNumber(cardNumber);
	Account* rr = nullptr;
	if (cc == nullptr) {
		return rr;
	}
	if (cc->pincode() == pinCode) {
		rr = new Account(cc->account());
	}
	delete cc;
	return rr;
}

bool Bank::checkCredentials(const string& cardNumber, const string& pinCode)
{
	Card* cc = Toolbox::getToolbox().g_CardDao().getByNumber(cardNumber);
	if (cc == nullptr) {
		return false;
	}
	if (cc->pincode() == pinCode) {
		return true;
	}
	delete cc;
	return false;
}

void Bank::doIncasators()
{
	vector<ATM> atms = Toolbox::getToolbox().g_AtmDao().getAllByBankId(id());

	for (std::vector<ATM>::iterator it = atms.begin(); it != atms.end(); ++it) {
		ATM* aa = ATM::getAtmWithMoneyStorage((*it).id());
		if (aa != nullptr) {
			(*aa).fillWithMoney(50);
			ATM::editAtmWithMoneyStorage(*aa);
			delete aa;
		}
	}

}

void Bank::triggerNextDayForBank(const size_t id)
{
	Toolbox::getToolbox().addOneDayToCurrentDate();
	vector<TransferDaemon> tdv = Toolbox::getToolbox().g_TransferDaemonDao().getAllByBankId(id);

	for (std::vector<TransferDaemon>::iterator it = tdv.begin(); it != tdv.end(); ++it) {
		proceedTransferDaemon(*it);
	}

	
}

void Bank::nextDay()
{
	triggerNextDayForBank(id());
}

bool Bank::checkIfCardIsExpired(Card& card) { return card.isExpiredBeforeDate(Toolbox::getCurrentDate()); };
