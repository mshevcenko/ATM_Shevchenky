#include "Card.h"
#include "autil.h"
#include "Bank.h"

//Card::Card(const CardNumber& cardNumber, const string& pincode, const time_t& expiryDate, Type type) : 
//	_cardNumber(cardNumber), _pincode(pincode), _expiryDate(expiryDate), _type(type), _account(0, 0) {
//
//	//Account init is TMP
//
//}

//Card::~Card() {
//
//}

Card::Card(const string& cardNumber) : Card(cardNumber, string("1234"), 0, 0, Card::Type::Credit) { }
Card::Card(const string& cardNumber, const string& pincode, const size_t& accountId, const time_t& expiryDate, const Type& type) :
	_cardNumber(cardNumber), _pincode(pincode), _accountId(accountId), _expiryDate(expiryDate), _type(type), _account(g_AccountDao.getById(accountId)) { }
Card::Card(const CardNumber& cardNumber, const string& pincode, const time_t& expiryDate, const Account& account) :
	_cardNumber(cardNumber), _pincode(pincode), _expiryDate(expiryDate), _account(new Account(account)), _accountId(_account->id()) {}
Card::Card(const Card& ss) : _cardNumber(ss._cardNumber), _pincode(ss._pincode), _expiryDate(ss._expiryDate), _accountId(ss._accountId), _type(ss._type), _account(g_AccountDao.getById(ss._accountId)) {}

Card::~Card()
{
	if (_account != nullptr) {
		delete _account;
		_account = nullptr;
	}
}

bool Card::checkIfCardIsValid(const string& cardNumber)
{
	Card* cc = g_CardDao.getByNumber(cardNumber);
	if (cc == nullptr) {
		return false;
	}
	if (Bank::checkIfCardIsExpired(*cc)) {
		delete cc;
		return false;
	}
	delete cc;
	return true;
}
