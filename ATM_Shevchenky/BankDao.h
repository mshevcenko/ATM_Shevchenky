#pragma once
#include "Database.h"
#include "AccountDao.h"
#include "CardDao.h"
#include "Account.h"
#include "Bank.h"
#include "Card.h"

class BankDao
{
private:
	Database _database;
	AccountDao _accountDao;
	CardDao _cardDao;
public:
	BankDao(const Database&, const AccountDao&, const CardDao&);

	bool addAccountAndCardByBank(const Bank&, const Account&, const Card&);
	bool addAccountAndCardByBankId(const size_t&, const Account&, const Card&);
	Bank* getById(const size_t&);
	vector<Bank> getAll();
	bool create(const Bank&);
	bool edit(const Bank&);
	bool remove(const Bank&);
};