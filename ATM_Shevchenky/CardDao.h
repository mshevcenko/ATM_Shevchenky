#pragma once
#include "Database.h"
#include "Account.h"
#include "Card.h"

class CardDao
{
private:
	Database _database;
public:
	CardDao(const Database&);

	Card* getByNumber(const CardNumber&);
	Card* getByAccount(const Account&);
	Card* getByAccountId(const size_t&);
	bool create(const Card&);
	bool edit(const Card&);
	bool remove(const Card&);
};