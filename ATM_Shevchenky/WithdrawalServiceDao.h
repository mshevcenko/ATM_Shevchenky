#pragma once
#include "Database.h"
#include "WithdrawalService.h"

class WithdrawalServiceDao
{
private:
	Database _database;
public:
	WithdrawalServiceDao(const Database&);

	WithdrawalService* getById(const size_t&);
	vector<WithdrawalService> getByFrom(const CardNumber&);
	bool create(const WithdrawalService&);
	bool edit(const WithdrawalService&);
	bool remove(const WithdrawalService&);
};