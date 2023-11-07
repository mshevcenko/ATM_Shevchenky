#pragma once

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

static time_t ONE_DAY = 1;
static time_t CURRENT_DATE = 0;

static Database g_DB = Database("ATM.db");
static AccountDao g_AccountDao = AccountDao(g_DB);
static AtmDao g_AtmDao = AtmDao(g_DB);
static CardDao g_CardDao = CardDao(g_DB);
static BankDao g_BankDao = BankDao(g_DB, g_AccountDao, g_CardDao);
static OverflowCreditServiceDao g_OverflowCreditServiceDao = OverflowCreditServiceDao(g_DB);
static OverflowServiceDao g_OverflowServiceDao = OverflowServiceDao(g_DB);
static TransferDaemonDao g_TransferDaemonDao = TransferDaemonDao(g_DB);
static TransferDao g_TransferDao = TransferDao(g_DB);
static WithdrawalServiceDao g_WithdrawalServiceDao = WithdrawalServiceDao(g_DB);
static MoneyStorageDao g_MoneyStorageDao = MoneyStorageDao(g_DB);


class Toolbox
{
public:
	static time_t getCurrentDate() {
		//return time(nullptr); 
		return CURRENT_DATE;
	}
	
	static ATM* getAtmWithMoney(const size_t id) {
		ATM* atm = g_AtmDao.getById(id);
		if (atm == nullptr) {
			return nullptr;
		}
		vector<MoneyStorage> msv = g_MoneyStorageDao.getAllByAtmId(id);
		atm->updateUsingMoneyStorage(msv);
		return atm;
	}

	static void fillWithMoney(ATM& aat) {
		for (int i = 0; i < SIZE_OF_BILLS_ARRAY; i++) {
			(aat.currencyStorage()[BILLS[i]]) = 100;
		}
	}

	static size_t getLastCreatedAccountId(const size_t bankId) {
		auto accv = g_AccountDao.getAllByBankId(bankId);
		size_t maxIndex = 0;
		for (auto it = accv.begin(); it != accv.end(); ++it) {
			maxIndex = max((*it).id(), maxIndex);
		}
		return maxIndex;
	}

	static bool makeTest(string name, bool res) {
		cout << "Test-" << name << "::" << res << '\n';
		return res;
	}

};