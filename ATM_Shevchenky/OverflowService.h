#pragma once
#include "Card.h"

using Money = double;

class OverflowService 
{
private:
	const size_t _id;
	const CardNumber _from;
	const CardNumber _to;
	const Money _threshold;

public:

	OverflowService(const size_t& id) : OverflowService(id, "", "", 0) { }
	OverflowService(const CardNumber& from, const CardNumber& to, const Money& threshold) : 
		OverflowService(0, from, to, threshold) { }
	OverflowService(const size_t& id, const CardNumber& from, const CardNumber& to, const Money& threshold) : 
		_id(id), _from(from), _to(to), _threshold(threshold) { }

	OverflowService(const OverflowService& ss) : OverflowService(ss._id, ss._from, ss._to, ss._threshold) {}
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
};