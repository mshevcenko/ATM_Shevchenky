#include "OverflowCreditServiceDao.h"

OverflowCreditServiceDao::OverflowCreditServiceDao(const Database& database) : _database(database) { 

}

OverflowCreditService* OverflowCreditServiceDao::getByFromAndTo(const CardNumber& from, const CardNumber& to) {
	const char* sql = "SELECT * FROM OverflowCreditService WHERE \"from\" = ? AND \"to\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, from.c_str(), from.length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, to.c_str(), to.length(), SQLITE_TRANSIENT);

	OverflowCreditService* overflowCreditService = nullptr;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_ROW) {
			overflowCreditService = new OverflowCreditService(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_double(stmt, 0)
			);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return overflowCreditService;
}

vector<OverflowCreditService> OverflowCreditServiceDao::getByFrom(const CardNumber& from) {
	const char* sql = "SELECT * FROM OverflowCreditService WHERE \"from\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, from.c_str(), from.length(), SQLITE_TRANSIENT);

	vector<OverflowCreditService> overflowCreditServices;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			overflowCreditServices.push_back(OverflowCreditService(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_double(stmt, 0)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return overflowCreditServices;
}

vector<OverflowCreditService> OverflowCreditServiceDao::getByTo(const CardNumber& to) {
	const char* sql = "SELECT * FROM OverflowCreditService WHERE \"to\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, to.c_str(), to.length(), SQLITE_TRANSIENT);

	vector<OverflowCreditService> overflowCreditServices;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			overflowCreditServices.push_back(OverflowCreditService(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_double(stmt, 0)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return overflowCreditServices;
}

bool OverflowCreditServiceDao::create(const OverflowCreditService& service) {
	const char* sql = "INSERT INTO OverflowCreditService(\"from\", \"to\", amount) VALUES (?, ?, ?)";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, service.from().c_str(), service.from().length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, service.to().c_str(), service.to().length(), SQLITE_TRANSIENT);
	sqlite3_bind_double(stmt, 3, service.amount());

	bool result = false;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_DONE) {
			result = true;
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return result;
}

bool OverflowCreditServiceDao::edit(const OverflowCreditService& service) {

	if (!getByFromAndTo(service.from(), service.to())) {
		return false;
	}

	const char* sql = "UPDATE OverflowCreditService SET amount = ? WHERE \"from\" = ? AND \"to\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_double(stmt, 1, service.amount());
	sqlite3_bind_text(stmt, 2, service.from().c_str(), service.from().length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 3, service.to().c_str(), service.to().length(), SQLITE_TRANSIENT);

	bool result = false;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_DONE) {
			result = true;
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return result;
}

bool OverflowCreditServiceDao::remove(const OverflowCreditService& service) {

	if (!getByFromAndTo(service.from(), service.to())) {
		return false;
	}

	const char* sql = "DELETE FROM OverflowCreditService WHERE \"from\" = ? AND \"to\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, service.from().c_str(), service.from().length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, service.to().c_str(), service.to().length(), SQLITE_TRANSIENT);

	bool result = false;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_DONE) {
			result = true;
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return result;
}