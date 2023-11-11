#pragma once
#include <ctime>
#include <string>

using CardNumber = std::string;

using Money = double;

class TransferDaemon
{
private:
	const size_t _id;
	CardNumber _from;
	const CardNumber _to;
	const Money _amount;
	time_t _nextTransferDate;
	const time_t _frequency;
	bool _isActive;
public:
	TransferDaemon(const size_t& id = 0);
	TransferDaemon(const CardNumber& from, const CardNumber& to, const Money& amount, const time_t& nextTransferDate, const time_t& frequency, bool isActive);
	TransferDaemon(const size_t& id, const CardNumber& from, const CardNumber& to, const Money& amount, const time_t& nextTransferDate, const time_t& frequency, bool isActive);
	TransferDaemon(const TransferDaemon& ss);
	
	~TransferDaemon();

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

	inline const time_t& nextTransferDate() const
	{
		return _nextTransferDate;
	}

	inline const time_t& frequency() const
	{
		return _frequency;
	}

	inline const bool isActive() const
	{
		return _isActive;
	}

	inline const size_t& id() const {
		return _id;
	}

	inline void nextDate() {
		_nextTransferDate += _frequency;
	}

	inline void setFrom(const CardNumber& from) {
		_from = from;
	}

	inline void setIsActive(const bool isActive) {
		_isActive = isActive;
	}

};