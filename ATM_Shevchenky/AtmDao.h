#pragma once
#include "Database.h"
#include "Bank.h"
#include "Atm.h"

class AtmDao
{
private:
	Database _database;
public:
	AtmDao(const Database&);

	ATM* getById(const size_t&);
	vector<ATM> getAllByBank(const Bank&);
	vector<ATM> getAllByBankId(const size_t&);
	bool create(const ATM&);
	bool edit(const ATM&);
	bool remove(const ATM&);
};