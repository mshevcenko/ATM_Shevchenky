#include "Account.h"

Account::Account(const size_t& id) : Account(id, 0, 0, 0) { }
Account::Account(const Money& creditLimit, const Money& balance) : Account(0, creditLimit, balance, 0) { }
Account::Account(const Money& creditLimit, const Money& balance, const size_t& bankId) : Account(0, creditLimit, balance, bankId) { }
Account::Account(const size_t& id, const Money& creditLimit, const Money& balance, const size_t& bankId) :
	_id(id), _creditLimit(creditLimit), _balance(balance), _bankId(bankId) { }
Account::Account(const Account& acc) : Account(acc._id, acc._creditLimit, acc._balance, acc._bankId) {}

Account::~Account() {

}
