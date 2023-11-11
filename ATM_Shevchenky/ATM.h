#pragma once
#include <map>
#include <string>
#include <vector>
#include "Account.h"
#include "Bank.h"
#include "OverflowService.h"
#include "OverflowCreditService.h"
#include "Transfer.h"
#include "TransferDaemon.h"
#include "WithdrawalService.h"

class MoneyStorage;

using namespace std;
using Currency = int;
using Money = double;

#define SIZE_OF_BILLS_ARRAY sizeof(BILLS) / sizeof(Currency)

static Currency BILLS[] = {1000, 500, 200, 100 ,50 ,20 ,10 ,5 ,2 ,1};

class ATM 
{
private:
	const size_t _id;
	map<Currency, unsigned int> _currencyStorage;
	Account* _currentAccount = nullptr;
	string _currentCardNumber = "";

	const size_t _bankId;
	//const Bank _bank;
	void clearCurrencyStorage();
	void doTransferService(Transfer ss);
	void doWithdrawalService(WithdrawalService ss);
public:
	ATM(const Bank&);
	~ATM();
	ATM(const size_t& bankId);
	ATM(const size_t& id, const size_t& bankId);
	ATM(const size_t& id, const size_t& bankId, const map<Currency, unsigned int>& currencyStorage);
	ATM(const ATM& ss);

	inline const size_t& id() const {
		return _id;
	}

	inline const string& currentCardNumber() const {
		return _currentCardNumber;
	}

	inline map<Currency, unsigned int>& currencyStorage() {
		return _currencyStorage;
	}

	inline const map<Currency, unsigned int>& currencyStorage() const {
		return _currencyStorage;
	}

	inline Account& currentAccount() {
		return *_currentAccount;
	}

	inline const size_t& bankId() const {
		return _bankId;
	}
	//void doOverflowService(OverflowService ss);
	//void doOverflowCreditService(OverflowCreditService ss);
	//void doTransferDaemonService(TransferDaemon ss);

	
	void updateUsingMoneyStorage(vector<MoneyStorage> msv);

	bool isExpired(const string& cardNumber);
	bool insertCard(const string&, const string&);

	void exit();
	bool checkPinCode(const string&);
	bool changeCreditLimit(double newCreditLimit);
	vector<pair<Currency, unsigned int>> withdraw(const size_t ammount);
	bool createOverflowService(OverflowService& service);
	bool createOverflowCreditService(OverflowCreditService service);
	bool hasOverflowService();
	OverflowService getOverflowService();
	vector<OverflowCreditService> getOverflowCreditServices();
	bool deleteOverflowService(const OverflowService& service);
	bool deleteOverflowCreditService(const OverflowCreditService& service);
	vector<Transfer> getTransfers();// returns all transfers incoming(without commision) and outcoming
	vector<WithdrawalService> getWithdrawalServices();
	bool createTransfer(Transfer transfer);// only to and (ammount with commision)
	bool createTransferDaemon(TransferDaemon transferDaemon);// all except id
	double getCommission();
	double calculateFeeSend(double money);
	double calculateFeeReceived(double money);
	vector<TransferDaemon> getTransferDaemons();
	bool editTransferDaemon(const TransferDaemon&);
	bool deleteTransferDaemon(const TransferDaemon&);

	bool createCardAndAccount(const string& cardNumber, const string& pinCode, double balance, time_t expiryDate, const size_t bankId);
	void nextDay();
	double getBalance();
	double getCreditLimit();
	time_t getExpiryDate();

	void updateData();
	/*int provideMoney(Money money);*/
	void saveToDB();
	void doIncasators();


	static ATM* getAtmWithMoneyStorage(const size_t id);

	static bool createAtmWithMoneyStorage(const ATM& atmData);

	static bool createAtmWithMoneyStorage(const ATM& atmData, const map<Currency, unsigned int>& currencyStorage);

	static bool deleteAtmWithMoneyStorage(const size_t& aid);

	static bool editAtmWithMoneyStorage(const ATM& atmData);

	static bool editAtmWithMoneyStorage(const ATM& atmData, const map<Currency, unsigned int>& currencyStorage);

	void fillWithMoney(const size_t ammountOfBills);

};