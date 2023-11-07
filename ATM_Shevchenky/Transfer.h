#pragma once
#include <ctime>
#include "Card.h"

using Money = double;

class Transfer
{
private:
	size_t _id;
	CardNumber _from;
	CardNumber _to;
	Money _amount;
	time_t _transferDate;
public:

	Transfer(const size_t& id = 0);
	Transfer(const CardNumber& from, const CardNumber& to, const Money& amount, const time_t& transferDate);
	Transfer(const size_t& id, const CardNumber& from, const CardNumber& to, const Money& amount, const time_t& transferDate);

	Transfer(const CardNumber&, const CardNumber&, const Money);
	~Transfer();

	Transfer(const Transfer& ss) : Transfer(ss._id, ss._from, ss._to, ss._amount, ss._transferDate) {}

	inline const CardNumber& from() const
	{
		return _from;
	}

	inline const CardNumber& to() const
	{
		return _to;
	}

	inline const Money& amount() const
	{
		return _amount;
	}

	inline const time_t& transferDate() const
	{
		return _transferDate;
	}

	inline const size_t& id() const {
		return _id;
	}

	inline void setAmount(const Money& amount) {
		_amount = amount;
	}

	inline void setFrom(const CardNumber& from) {
		_from = from;
	}

	static inline bool dateCmp(const Transfer& a, const Transfer& b) { return a.transferDate() > b.transferDate(); }
};