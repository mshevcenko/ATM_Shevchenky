#include "WithdrawalService.h"

#include"autil.h"

WithdrawalService::WithdrawalService(const CardNumber& from, const Money& amount, int atmId) :
	_from(from), _amount(amount), _atmId(atmId), _id(0), _withdrawalDate(Toolbox::getCurrentDate())
{
	
}

WithdrawalService::WithdrawalService(const size_t& id) : WithdrawalService(id, "", 0, 0, 0) { }
WithdrawalService::WithdrawalService(const CardNumber& from, const Money& amount, const time_t& withdrawalDate, const size_t& atmId) :
	WithdrawalService(0, from, amount, withdrawalDate, atmId) { }
WithdrawalService::WithdrawalService(const size_t& id, const CardNumber& from, const Money& amount, const time_t& withdrawalDate, const size_t& atmId) :
	_id(id), _from(from), _amount(amount), _withdrawalDate(withdrawalDate), _atmId(atmId) { }
WithdrawalService::WithdrawalService(const WithdrawalService& ss) : WithdrawalService(ss._id, ss._from, ss._amount, ss._withdrawalDate, ss._atmId) {}

WithdrawalService::~WithdrawalService()
{
}
