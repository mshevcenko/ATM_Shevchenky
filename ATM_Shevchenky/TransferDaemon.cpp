#include "TransferDaemon.h"

TransferDaemon::TransferDaemon(const size_t& id) : TransferDaemon(id, "", "", 0, 0, 0, false) { }
TransferDaemon::TransferDaemon(const CardNumber& from, const CardNumber& to, const Money& amount, const time_t& nextTransferDate, const time_t& frequency, bool isActive) :
	TransferDaemon(0, from, to, amount, nextTransferDate, frequency, isActive) { }
TransferDaemon::TransferDaemon(const size_t& id, const CardNumber& from, const CardNumber& to, const Money& amount, const time_t& nextTransferDate, const time_t& frequency, bool isActive) :
	_id(id), _from(from), _to(to), _amount(amount), _nextTransferDate(nextTransferDate), _frequency(frequency), _isActive(isActive) { }
TransferDaemon::TransferDaemon(const TransferDaemon& ss) : TransferDaemon(ss._id, ss._from, ss._to, ss._amount, ss._nextTransferDate, ss._frequency, ss._isActive) {}

TransferDaemon::~TransferDaemon()
{
}