#pragma once

using Money = double;


class Account
{
private:
	const size_t _id;
	Money _creditLimit;
	Money _balance;
	const size_t _bankId;
public:
	Account(const size_t& id = 0);
	Account(const Money& creditLimit, const Money& balance);
	Account(const Money& creditLimit, const Money& balance, const size_t& bankId);
	Account(const size_t& id, const Money& creditLimit, const Money& balance, const size_t& bankId);
	Account(const Account& acc);

	~Account();

	inline const Money& creditLimit() const
	{
		return _creditLimit;
	}

	inline const Money& balance() const
	{
		return _balance;
	}

	inline const size_t& id() const {
		return _id;
	}

	inline const size_t& bankId() const {
		return _bankId;
	}
	inline void changeBalance(const Money& delta)
	{
		_balance += delta;
	}
	inline void changeCreditLimit(const Money& money)
	{
		_creditLimit = money;
	}
	inline const Money& availableMoney() const
	{
		return _balance + _creditLimit;
	}
};