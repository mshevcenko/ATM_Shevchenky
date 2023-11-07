#pragma once
#include "Database.h"

class MoneyStorage {
public:
	enum Denomination {
		VALUE_1 = 1,
		VALUE_2 = 2,
		VALUE_5 = 5,
		VALUE_10 = 10,
		VALUE_20 = 20,
		VALUE_50 = 50,
		VALUE_100 = 100,
		VALUE_200 = 200,
		VALUE_500 = 500,
		VALUE_1000 = 1000,
	};
private:
	const size_t _id;
	const Denomination _denomination;
	const size_t _amount;
	const size_t _atmId;
public:
	MoneyStorage(const size_t&);
	MoneyStorage(const Denomination&, const size_t&, const size_t&);
	MoneyStorage(const size_t&, const Denomination&, const size_t&, const size_t&);
	~MoneyStorage();

	const size_t& id() const;
	const Denomination& denomination() const;
	const size_t& amount() const;
	const size_t& atmId() const;
};