#pragma once
#include <string>

using CardNumber = std::string;
using Money = double;

class OverflowService 
{
private:
	const size_t _id;
	CardNumber _from;
	const CardNumber _to;
	const Money _threshold;

public:

	OverflowService(const size_t& id = 0);
	OverflowService(const CardNumber& from, const CardNumber& to, const Money& threshold);
	OverflowService(const size_t& id, const CardNumber& from, const CardNumber& to, const Money& threshold);
	OverflowService(const OverflowService& ss);
	~OverflowService();


	inline const CardNumber& from() const
	{
		return _from;
	}

	inline const CardNumber& to() const
	{
		return _to;
	}

	inline const Money& threshold() const
	{
		return _threshold;
	}

	inline const size_t& id() const {
		return _id;
	}

	inline void setFrom(const CardNumber& from) {
		_from = from;
	}

};