#pragma once
#include <string>
#include <ctime>
#include "Account.h"

using namespace std;

using CardNumber = string;
using Money = double;

class Card
{
public:
	enum Type {
		Credit,
		Debit
	};
private:
	const CardNumber _cardNumber;
	const string _pincode;
	const time_t _expiryDate;
	Account* _account = nullptr;
	const size_t _accountId;
	const Type _type = Card::Type::Credit;
	
public:
	Card(const string& cardNumber = 0);
	Card(const string& cardNumber, const string& pincode, const size_t& accountId, const time_t& expiryDate, const Type& type);
	~Card();
	Card(const CardNumber& cardNumber, const string& pincode, const time_t& expiryDate, const Account& account);
	Card(const Card& ss);


	inline const Account& account() const
	{
		return *_account;
	}

	
	inline const CardNumber& cardNumber() const
	{
		return _cardNumber;
	}

	inline const string& pincode() const
	{
		return _pincode;
	}

	inline const size_t& accountId() const {
		return _accountId;
	}

	inline const time_t& expiryDate() const
	{
		return _expiryDate;
	}

	inline const Type& type() const
	{
		return _type;
	}

	inline bool isExpiredBeforeDate(time_t time) const {
		return _expiryDate < time;
	}

	inline void changeBalance(const Money& delta) { 
		_account->changeBalance(delta);
	}

	static bool checkIfCardIsValid(const string& cardNumber);

};

