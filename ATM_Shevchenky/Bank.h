#pragma once
#include <string>
#include "TransferDaemon.h"
#include "Card.h"

class ATM;
class OverflowService;
class OverflowCreditService;
class Transfer;
class WithdrawalService;

using namespace std;


static const double g_FEE = 0.05;

class Bank
{
private:
	size_t _id;
	string _name;
	//vector<ATM> _atms;
	//vector<TransferDaemon> _transferDaemons; //as i remember its should be in DB

	static Card getCardDataByCardNum(CardNumber cardNumber);
	static ATM getATMbyId(int id);

	static int proceedTransferActions(Card& fromCard, Card& toCard, const Money& ammount);
	static int proceedWithdrawalActions(Card& fromCard, int atmId, const Money& ammount);

public:

	Bank(const string& name = "TB");
	Bank(const size_t& id, const string& name = "Standard bank");
	~Bank();
	Bank(const Bank& ss);

	inline const size_t& id() const { 
		return _id; 
	}
	
	inline const string name() const {
		return _name;
	}

	/*inline vector<ATM> atms() const {
		return _atms;
	}

	inline vector<TransferDaemon> transferDaemons() {
		return _transferDaemons;
	}*/

	static int proceedOverflowService(const OverflowService& ss);
	static int proceedOverflowCreditService(const OverflowCreditService& ss);
	static int proceedTransfer(Transfer ss);
	static int proceedTransferDaemon(TransferDaemon & ss);
	static int proceedWithdrawalService(const WithdrawalService& ss);

	static bool checkIfCardIsExpired(Card& card);

	static Account* getAccountByCredentials(const string& cardNumber, const string& pinCode);
	static bool checkCredentials(const string& cardNumber, const string& pinCode);

	static inline Money calculateFeeRecive(Money mm) { return mm * (1 - g_FEE); }
	static inline Money calculateFeeSend(Money mm) { return mm / (1 - g_FEE); }

	void doIncasators();
	static void triggerNextDayForBank(const size_t id);
	void nextDay();


	
	
};