#include "MoneyStorage.h"

MoneyStorage::MoneyStorage(const size_t& id) : MoneyStorage(id, MoneyStorage::Denomination::VALUE_1, 0, 0) {

}

MoneyStorage::MoneyStorage(const Denomination& denomination, const size_t& amount, const size_t& atmId) :
	MoneyStorage(0, denomination, amount, atmId) {

}

MoneyStorage::MoneyStorage(const size_t& id, const Denomination& denomination, const size_t& amount, const size_t& atmId) :
	_id(id), _denomination(denomination), _amount(amount), _atmId(atmId) {

}

MoneyStorage::~MoneyStorage() {

}

const size_t& MoneyStorage::id() const {
	return _id;
}

const MoneyStorage::Denomination& MoneyStorage::denomination() const {
	return _denomination;
}

const size_t& MoneyStorage::amount() const {
	return _amount;
}

const size_t& MoneyStorage::atmId() const {
	return _atmId;
}