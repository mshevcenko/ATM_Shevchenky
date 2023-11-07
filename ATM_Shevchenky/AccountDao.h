#pragma once
#include "Database.h"
#include "Account.h"
#include "Bank.h"
#include "Card.h"

class AccountDao
{
private: 
	Database _database;
public:
	AccountDao(const Database&);

	Account* getById(const size_t&);
	Account* getByCard(const Card&);
	Account* getByCardNumber(const CardNumber&);
	vector<Account> getAllByBank(const Bank&);
	vector<Account> getAllByBankId(const size_t&);
	bool create(const Account&);
	bool edit(const Account&);
	bool remove(const Account&);
};