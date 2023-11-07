#pragma once
#include <ctime>
#include <string>

using CardNumber = std::string;
using Money = double;

class WithdrawalService
{
private:
	size_t _id;
	CardNumber _from;
	Money _amount;
	time_t _withdrawalDate;
	size_t _atmId;
public:
	WithdrawalService(const size_t& id);
	WithdrawalService(const CardNumber& from, const Money& amount, const time_t& withdrawalDate, const size_t& atmId);
	WithdrawalService(const size_t& id, const CardNumber& from, const Money& amount, const time_t& withdrawalDate, const size_t& atmId);
	WithdrawalService(const WithdrawalService& ss);
	WithdrawalService(const CardNumber&, const Money&, int);

	~WithdrawalService();

	inline const size_t& id() const {
		return _id;
	}

	inline const CardNumber& from() const
	{
		return _from;
	}

	inline const Money& amount() const
	{
		return _amount;
	}

	inline const time_t& withdrawalDate() const {
		return _withdrawalDate;
	}

	inline const size_t& atmId() const
	{
		return _atmId;
	}

	static inline bool dateCmp(const WithdrawalService& a, const WithdrawalService& b) { return a.withdrawalDate() > b.withdrawalDate(); }
};