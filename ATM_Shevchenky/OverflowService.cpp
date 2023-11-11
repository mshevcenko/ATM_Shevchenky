#include "OverflowService.h"


OverflowService::OverflowService(const size_t& id) : OverflowService(id, "", "", 0) { }
OverflowService::OverflowService(const CardNumber& from, const CardNumber& to, const Money& threshold) :
	OverflowService(0, from, to, threshold) { }
OverflowService::OverflowService(const size_t& id, const CardNumber& from, const CardNumber& to, const Money& threshold) :
	_id(id), _from(from), _to(to), _threshold(threshold) { }
OverflowService::OverflowService(const OverflowService& ss) : OverflowService(ss._id, ss._from, ss._to, ss._threshold) {}

OverflowService::~OverflowService()
{

}
