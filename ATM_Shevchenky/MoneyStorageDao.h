#pragma once
#include "Database.h"
#include "MoneyStorage.h"

class MoneyStorageDao {
private:
	Database _database;
public:
	MoneyStorageDao(const Database&);
	
	MoneyStorage* getByDenominationAndAtmId(const MoneyStorage::Denomination&, const size_t&);
	vector<MoneyStorage> getAllByAtmId(const size_t&);
	vector<MoneyStorage> getAllByDenomination(const MoneyStorage::Denomination&);
	bool create(const MoneyStorage&);
	bool edit(const MoneyStorage&);
	bool remove(const MoneyStorage&);
};