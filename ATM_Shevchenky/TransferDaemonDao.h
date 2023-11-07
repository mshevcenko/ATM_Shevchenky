#pragma once
#include "Database.h"
#include "TransferDaemon.h"

class TransferDaemonDao
{
private:
	Database _database;
public:
	TransferDaemonDao(const Database&);

	TransferDaemon* getByFromAndTo(const CardNumber&, const CardNumber&);
	vector<TransferDaemon> getByFrom(const CardNumber&);
	vector<TransferDaemon> getByTo(const CardNumber&);
	vector<TransferDaemon> getAllByBankId(const size_t&);
	bool create(const TransferDaemon&);
	bool edit(const TransferDaemon&);
	bool remove(const TransferDaemon&);
};