#pragma once

#ifndef AUTIL_H
#define debug
#include "Account.h"


#include "AccountDao.h"
#include "AtmDao.h"
#include "BankDao.h"
#include "CardDao.h"
#include "OverflowCreditServiceDao.h"
#include "OverflowServiceDao.h"
#include "TransferDaemonDao.h"
#include "TransferDao.h"
#include "WithdrawalServiceDao.h"
#include "MoneyStorageDao.h"


template <class TTT>
TTT copyAndDeletePointer(TTT* pp) {
	TTT rr(*pp);
	delete pp;
	pp = 0;
	return rr;
}




class Toolbox
{
private:
	bool _timeVar;

	time_t _OneDay = 1;
	time_t _CurrentDate = 0;

	Database _DB;
	AccountDao _AccountDao;
	AtmDao _AtmDao;
	CardDao _CardDao;
	BankDao _BankDao;
	OverflowCreditServiceDao _OverflowCreditServiceDao;
	OverflowServiceDao _OverflowServiceDao;
	TransferDaemonDao _TransferDaemonDao;
	TransferDao _TransferDao;
	WithdrawalServiceDao _WithdrawalServiceDao;
	MoneyStorageDao _MoneyStorageDao;

public:
	Toolbox(bool timeVar = false);

	Database& g_DB();

	AccountDao& g_AccountDao();

	AtmDao& g_AtmDao();

	CardDao& g_CardDao();

	BankDao& g_BankDao();

	OverflowCreditServiceDao& g_OverflowCreditServiceDao();

	OverflowServiceDao& g_OverflowServiceDao();

	TransferDaemonDao& g_TransferDaemonDao();

	TransferDao& g_TransferDao();

	WithdrawalServiceDao& g_WithdrawalServiceDao();

	MoneyStorageDao& g_MoneyStorageDao();


	static Toolbox& getToolbox();

	static time_t getCurrentDate();

	static time_t getOneDay();

	static void setCurrentDate(const time_t& time);

	static void setOneDay(const time_t& time);

	static void addOneDayToCurrentDate();

	static size_t getLastCreatedAtmIdByBank(size_t bid);

	static size_t calculateSum(const vector<pair<Currency, unsigned int>>& currencyStorage);

	static size_t getLastCreatedAccountId(const size_t bankId);

	static bool makeTest(string name, bool res);

};

static Toolbox toolbox = Toolbox(false);

#define AUTIL_H
#endif