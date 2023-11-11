#include "autil.h"


Toolbox::Toolbox(bool timeVar) : 
_timeVar(timeVar),
_DB("ATM.db"),
_AccountDao(_DB),
_AtmDao(_DB),
_CardDao(_DB),
_BankDao(_DB, _AccountDao, _CardDao),
_OverflowCreditServiceDao(_DB),
_OverflowServiceDao(_DB),
_TransferDaemonDao(_DB),
_TransferDao(_DB),
_WithdrawalServiceDao(_DB),
_MoneyStorageDao(_DB) {};

Database& Toolbox::g_DB() {
	return _DB;
}

AccountDao& Toolbox::g_AccountDao() {
	return _AccountDao;
}

AtmDao& Toolbox::g_AtmDao() {
	return _AtmDao;
}

CardDao& Toolbox::g_CardDao() {
	return _CardDao;
}

BankDao& Toolbox::g_BankDao() {
	return _BankDao;
}

OverflowCreditServiceDao& Toolbox::g_OverflowCreditServiceDao() {
	return _OverflowCreditServiceDao;
}

OverflowServiceDao& Toolbox::g_OverflowServiceDao() {
	return _OverflowServiceDao;
}

TransferDaemonDao& Toolbox::g_TransferDaemonDao() {
	return _TransferDaemonDao;
}

TransferDao& Toolbox::g_TransferDao() {
	return _TransferDao;
}

WithdrawalServiceDao& Toolbox::g_WithdrawalServiceDao() {
	return _WithdrawalServiceDao;
}

MoneyStorageDao& Toolbox::g_MoneyStorageDao() {
	return _MoneyStorageDao;
}


Toolbox& Toolbox::getToolbox() {
	return toolbox;
}

time_t Toolbox::getCurrentDate() {
	if (getToolbox()._timeVar) {
		return time(nullptr);
	}
	return getToolbox()._CurrentDate;
}

time_t Toolbox::getOneDay() {
	if (getToolbox()._timeVar) {
		return 86400;
	}
	return getToolbox()._OneDay;
}

void Toolbox::setCurrentDate(const time_t& time) {
	if (getToolbox()._timeVar) {
		return;
	}
	getToolbox()._CurrentDate = time;
}

void Toolbox::addOneDayToCurrentDate() {
	if (getToolbox()._timeVar) {
		return;
	}
	getToolbox()._CurrentDate += getToolbox()._OneDay;
}

void Toolbox::setOneDay(const time_t& time){
	if (getToolbox()._timeVar) {
		return;
	}
	getToolbox()._OneDay = time;
}

size_t Toolbox::getLastCreatedAtmIdByBank(size_t bid) {
	return getToolbox().g_AtmDao().getAllByBankId(bid).front().id();
}

size_t Toolbox::calculateSum(const vector<pair<Currency, unsigned int>>& currencyStorage) {
	size_t res = 0;
	for (auto it = currencyStorage.begin(); it != currencyStorage.end(); ++it) {
		res += (*it).first * (*it).second;
	}
	return res;
}

size_t Toolbox::getLastCreatedAccountId(const size_t bankId) {
	auto accv = getToolbox().g_AccountDao().getAllByBankId(bankId);
	size_t maxIndex = 0;
	for (auto it = accv.begin(); it != accv.end(); ++it) {
		maxIndex = max((*it).id(), maxIndex);
	}
	return maxIndex;
}

bool Toolbox::makeTest(string name, bool res) {
	cout << "Test-" << name << "::" << res << '\n';
	return res;
}