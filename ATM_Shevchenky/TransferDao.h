#pragma once
#include "Database.h"
#include "Transfer.h"

class TransferDao
{
private:
	Database _database;
public:
	TransferDao(const Database&);

	Transfer* getById(const size_t&);
	vector<Transfer> getByFrom(const CardNumber&);
	vector<Transfer> getByTo(const CardNumber&);
	bool create(const Transfer&);
	bool edit(const Transfer&);
	bool remove(const Transfer&);
};