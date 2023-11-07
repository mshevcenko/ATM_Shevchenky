#pragma once
#include "Database.h"
#include "OverflowCreditService.h"

class OverflowCreditServiceDao
{
private:
	Database _database;
public:
	OverflowCreditServiceDao(const Database&);

	OverflowCreditService* getByFromAndTo(const CardNumber&, const CardNumber&);
	vector<OverflowCreditService> getByFrom(const CardNumber&);
	vector<OverflowCreditService> getByTo(const CardNumber&);
	bool create(const OverflowCreditService&);
	bool edit(const OverflowCreditService&);
	bool remove(const OverflowCreditService&);
};