#include "OverflowServiceDao.h"

OverflowServiceDao::OverflowServiceDao(const Database& database) : _database(database) {

}

OverflowService* OverflowServiceDao::getByFromAndTo(const CardNumber& from, const CardNumber& to) {
	const char* sql = "SELECT * FROM OverflowService WHERE \"from\" = ? AND \"to\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, from.c_str(), from.length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, to.c_str(), to.length(), SQLITE_TRANSIENT);

	OverflowService* overflowService = nullptr;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_ROW) {
			overflowService = new OverflowService(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_double(stmt, 0)
			);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return overflowService;
}

vector<OverflowService> OverflowServiceDao::getByFrom(const CardNumber& from) {
	const char* sql = "SELECT * FROM OverflowService WHERE \"from\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, from.c_str(), from.length(), SQLITE_TRANSIENT);

	vector<OverflowService> overflowServices;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			overflowServices.push_back(OverflowService(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_double(stmt, 0)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return overflowServices;
}

vector<OverflowService> OverflowServiceDao::getByTo(const CardNumber& to) {
	const char* sql = "SELECT * FROM OverflowService WHERE \"to\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, to.c_str(), to.length(), SQLITE_TRANSIENT);

	vector<OverflowService> overflowServices;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			overflowServices.push_back(OverflowService(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_double(stmt, 0)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return overflowServices;
}

bool OverflowServiceDao::create(const OverflowService& service) {
	const char* sql = "INSERT INTO OverflowService(\"from\", \"to\", threshold) VALUES (?, ?, ?)";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, service.from().c_str(), service.from().length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, service.to().c_str(), service.to().length(), SQLITE_TRANSIENT);
	sqlite3_bind_double(stmt, 3, service.threshold());

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

bool OverflowServiceDao::edit(const OverflowService& service) {

	if (!getByFromAndTo(service.from(), service.to())) {
		return false;
	}

	const char* sql = "UPDATE OverflowService SET threshold = ? WHERE \"from\" = ? AND \"to\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_double(stmt, 1, service.threshold());
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

bool OverflowServiceDao::remove(const OverflowService& service) {

	if (!getByFromAndTo(service.from(), service.to())) {
		return false;
	}

	const char* sql = "DELETE FROM OverflowService WHERE \"from\" = ? AND \"to\" = ?";

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