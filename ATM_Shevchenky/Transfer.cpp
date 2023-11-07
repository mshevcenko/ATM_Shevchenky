#include "Transfer.h"
#include "autil.h"

Transfer::Transfer(const CardNumber& from, const CardNumber& to, const Money amount) : 
	_from(from), _to(to), _amount(amount), _transferDate(Toolbox::getCurrentDate()), _id(0) {
	
}

Transfer::Transfer(const size_t& id) : Transfer(id, "", "", 0, 0) { }
Transfer::Transfer(const CardNumber& from, const CardNumber& to, const Money& amount, const time_t& transferDate) :
	Transfer(0, from, to, amount, transferDate) { }
Transfer::Transfer(const size_t& id, const CardNumber& from, const CardNumber& to, const Money& amount, const time_t& transferDate) :
	_id(id), _from(from), _to(to), _amount(amount), _transferDate(transferDate) { }

Transfer::~Transfer()
{
}
