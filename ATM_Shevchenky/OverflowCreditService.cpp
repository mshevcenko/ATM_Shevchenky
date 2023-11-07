#include "OverflowCreditService.h"


OverflowCreditService::OverflowCreditService(const size_t& id) : OverflowCreditService(id, "", "", 0) { }
OverflowCreditService::OverflowCreditService(const CardNumber& from, const CardNumber& to, const Money& amount) :
	OverflowCreditService(0, from, to, amount) { }
OverflowCreditService::OverflowCreditService(const size_t& id, const CardNumber& from, const CardNumber& to, const Money& amount) :
	_id(id), _from(from), _to(to), _amount(amount) { }
OverflowCreditService::OverflowCreditService(const OverflowCreditService& ss) : OverflowCreditService(ss._id, ss._from, ss._to, ss._amount) {}

OverflowCreditService::~OverflowCreditService()
{
}
