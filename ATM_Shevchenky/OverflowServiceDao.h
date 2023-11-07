#pragma once
#include "Database.h"
#include "OverflowService.h"

class OverflowServiceDao
{
private:
	Database _database;
public:
	OverflowServiceDao(const Database&);

	OverflowService* getByFromAndTo(const CardNumber&, const CardNumber&);
	vector<OverflowService> getByFrom(const CardNumber&);
	vector<OverflowService> getByTo(const CardNumber&);
	bool create(const OverflowService&);
	bool edit(const OverflowService&);
	bool remove(const OverflowService&);
};