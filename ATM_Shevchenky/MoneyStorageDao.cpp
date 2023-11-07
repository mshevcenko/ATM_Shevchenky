#include "MoneyStorageDao.h"

MoneyStorageDao::MoneyStorageDao(const Database& database) : _database(database) {

}

MoneyStorage* MoneyStorageDao::getByDenominationAndAtmId(const MoneyStorage::Denomination& denomination, const size_t& atmId) {
	const char* sql = "SELECT * FROM MoneyStorages WHERE denomination = ? AND atm_id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, denomination);
	sqlite3_bind_int64(stmt, 2, atmId);

	MoneyStorage* moneyStorage = nullptr;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_ROW) {
			moneyStorage = new MoneyStorage(
				sqlite3_column_int64(stmt, 0),
				static_cast<MoneyStorage::Denomination>(sqlite3_column_int64(stmt, 1)),
				sqlite3_column_int64(stmt, 2),
				sqlite3_column_int64(stmt, 3)
			);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return moneyStorage;
}

vector<MoneyStorage> MoneyStorageDao::getAllByAtmId(const size_t& atmId) {
	const char* sql = "SELECT * FROM MoneyStorages WHERE atm_id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, atmId);

	vector<MoneyStorage> moneyStorages;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			moneyStorages.push_back(MoneyStorage(
				sqlite3_column_int64(stmt, 0),
				static_cast<MoneyStorage::Denomination>(sqlite3_column_int64(stmt, 1)),
				sqlite3_column_int64(stmt, 2),
				sqlite3_column_int64(stmt, 3)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return moneyStorages;
}

vector<MoneyStorage> MoneyStorageDao::getAllByDenomination(const MoneyStorage::Denomination& denomination) {
	const char* sql = "SELECT * FROM MoneyStorages WHERE denomination = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, denomination);

	vector<MoneyStorage> moneyStorages;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			moneyStorages.push_back(MoneyStorage(
				sqlite3_column_int64(stmt, 0),
				static_cast<MoneyStorage::Denomination>(sqlite3_column_int64(stmt, 1)),
				sqlite3_column_int64(stmt, 2),
				sqlite3_column_int64(stmt, 3)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return moneyStorages;
}

bool MoneyStorageDao::create(const MoneyStorage& moneyStorage) {
	const char* sql = "INSERT INTO MoneyStorages(denomination, amount, atm_id) VALUES (?, ?, ?)";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, moneyStorage.denomination());
	sqlite3_bind_int64(stmt, 2, moneyStorage.amount());
	sqlite3_bind_int64(stmt, 3, moneyStorage.atmId());

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

bool MoneyStorageDao::edit(const MoneyStorage& moneyStorage) {

	if (!getByDenominationAndAtmId(moneyStorage.denomination(), moneyStorage.atmId())) {
		return false;
	}

	const char* sql = "UPDATE MoneyStorages SET amount = ? WHERE denomination = ? AND atm_id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, moneyStorage.amount());
	sqlite3_bind_int64(stmt, 2, moneyStorage.denomination());
	sqlite3_bind_int64(stmt, 3, moneyStorage.atmId());

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

bool MoneyStorageDao::remove(const MoneyStorage& moneyStorage) {

	if (!getByDenominationAndAtmId(moneyStorage.denomination(), moneyStorage.atmId())) {
		return false;
	}

	const char* sql = "DELETE FROM MoneyStorages WHERE denomination = ? AND atm_id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, moneyStorage.denomination());
	sqlite3_bind_int64(stmt, 2, moneyStorage.atmId());

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