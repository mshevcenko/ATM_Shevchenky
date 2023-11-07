#include "WithdrawalServiceDao.h"

WithdrawalServiceDao::WithdrawalServiceDao(const Database& database) : _database(database) {

}

WithdrawalService* WithdrawalServiceDao::getById(const size_t& id) {
	const char* sql = "SELECT id, \"from\", amount, CAST(strftime('%s', datetime) AS INT), atm_id FROM Withdrawals WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, id);

	WithdrawalService* withdrawal = nullptr;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_ROW) {
			withdrawal = new WithdrawalService(
				sqlite3_column_int64(stmt, 0),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				sqlite3_column_double(stmt, 2),
				sqlite3_column_int64(stmt, 3),
				sqlite3_column_int64(stmt, 4)
			);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return withdrawal;
}

vector<WithdrawalService> WithdrawalServiceDao::getByFrom(const CardNumber& from) {
	const char* sql = "SELECT id, \"from\", amount, CAST(strftime('%s', datetime) AS INT), atm_id FROM Withdrawals WHERE \"from\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, from.c_str(), from.length(), SQLITE_TRANSIENT);

	vector<WithdrawalService> withdrawals;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			withdrawals.push_back(WithdrawalService(
				sqlite3_column_int64(stmt, 0),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				sqlite3_column_double(stmt, 2),
				sqlite3_column_int64(stmt, 3),
				sqlite3_column_int64(stmt, 4)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return withdrawals;
}

bool WithdrawalServiceDao::create(const WithdrawalService& service) {

	const char* sql = "INSERT INTO Withdrawals(\"from\", amount, datetime, atm_id) VALUES (?, ?, DATETIME(?, 'unixepoch'), ?)";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, service.from().c_str(), service.from().length(), SQLITE_TRANSIENT);
	sqlite3_bind_double(stmt, 2, service.amount());
	sqlite3_bind_int64(stmt, 3, service.withdrawalDate());
	sqlite3_bind_int64(stmt, 4, service.atmId());

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

bool WithdrawalServiceDao::edit(const WithdrawalService& service) {

	if (!getById(service.id())) {
		return false;
	}

	const char* sql = "UPDATE Withdrawals SET \"from\" = ?, amount = ?, datetime = DATETIME(?, 'unixepoch'), atm_id = ? WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, service.from().c_str(), service.from().length(), SQLITE_TRANSIENT);
	sqlite3_bind_double(stmt, 2, service.amount());
	sqlite3_bind_int64(stmt, 3, service.withdrawalDate());
	sqlite3_bind_int64(stmt, 4, service.atmId());
	sqlite3_bind_int64(stmt, 5, service.id());

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

bool WithdrawalServiceDao::remove(const WithdrawalService& service) {

	if (!getById(service.id())) {
		return false;
	}

	const char* sql = "DELETE FROM Withdrawals WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, service.id());

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