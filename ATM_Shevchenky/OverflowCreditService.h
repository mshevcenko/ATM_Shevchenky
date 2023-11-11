#pragma once
#include <string>

using CardNumber = std::string;

using Money = double;

class OverflowCreditService
{
private:
	const size_t _id;
	CardNumber _from;
	const CardNumber _to;
	const Money _amount;

public:
	OverflowCreditService(const size_t& id = 0);
	OverflowCreditService(const CardNumber& from, const CardNumber& to, const Money& amount);
	OverflowCreditService(const size_t& id, const CardNumber& from, const CardNumber& to, const Money& amount);
	OverflowCreditService(const OverflowCreditService& ss);
	
	~OverflowCreditService();

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

	inline const size_t id() const {
		return _id;
	}

	inline void setFrom(const CardNumber& from) {
		_from = from;
	}

};