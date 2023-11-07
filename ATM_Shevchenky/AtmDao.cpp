#include "AtmDao.h"

AtmDao::AtmDao(const Database& database) : _database(database) {

}

ATM* AtmDao::getById(const size_t& id) {
	const char* sql = "SELECT * FROM ATMs WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, id);

	ATM* atm = nullptr;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_ROW) {
			atm = new ATM(
				sqlite3_column_int64(stmt, 0),
				sqlite3_column_int64(stmt, 1)
			);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return atm;
}

vector<ATM> AtmDao::getAllByBank(const Bank& bank) {
	const char* sql = "SELECT * FROM ATMs WHERE bank_id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, bank.id());

	vector<ATM> atms;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			atms.push_back(ATM(
				sqlite3_column_int64(stmt, 0),
				sqlite3_column_int64(stmt, 1)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return atms;
}

vector<ATM> AtmDao::getAllByBankId(const size_t& id) {
	return getAllByBank(Bank(id, ""));
}

bool AtmDao::create(const ATM& atm) {
	const char* sql = "INSERT INTO ATMs(bank_id) VALUES(?)";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, atm.bankId());

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

bool AtmDao::edit(const ATM& atm) {

	if (!getById(atm.id())) {
		return false;
	}

	const char* sql = "UPDATE ATMs SET bank_id = ? WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, atm.bankId());
	sqlite3_bind_int64(stmt, 2, atm.id());

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

bool AtmDao::remove(const ATM& atm) {

	if (!getById(atm.id())) {
		return false;
	}

	const char* sql = "DELETE FROM ATMs WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, atm.id());

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