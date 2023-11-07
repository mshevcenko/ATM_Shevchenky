#include "TransferDao.h"

TransferDao::TransferDao(const Database& database) : _database(database) {

}

Transfer* TransferDao::getById(const size_t& id) {
	const char* sql = "SELECT id, \"from\", \"to\", amount, CAST(strftime('%s', \"datetime\") AS INT) FROM Transfers WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, id);

	Transfer* transfer = nullptr;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_ROW) {
			transfer = new Transfer(
				sqlite3_column_int64(stmt, 0),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_double(stmt, 3),
				sqlite3_column_int64(stmt, 4)
			);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return transfer;
}

vector<Transfer> TransferDao::getByFrom(const CardNumber& from) {
	const char* sql = "SELECT id, \"from\", \"to\", amount, CAST(strftime('%s', \"datetime\") AS INT) FROM Transfers WHERE \"from\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, from.c_str(), from.length(), SQLITE_TRANSIENT);

	vector<Transfer> transfers;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			transfers.push_back(Transfer(
				sqlite3_column_int64(stmt, 0),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_double(stmt, 3),
				sqlite3_column_int64(stmt, 4)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return transfers;
}

vector<Transfer> TransferDao::getByTo(const CardNumber& to) {
	const char* sql = "SELECT id, \"from\", \"to\", amount, CAST(strftime('%s', \"datetime\") AS INT) FROM Transfers WHERE \"to\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, to.c_str(), to.length(), SQLITE_TRANSIENT);

	vector<Transfer> transfers;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			transfers.push_back(Transfer(
				sqlite3_column_int64(stmt, 0),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_double(stmt, 3),
				sqlite3_column_int64(stmt, 4)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return transfers;
}

bool TransferDao::create(const Transfer& service) {
	const char* sql = "INSERT INTO Transfers(\"from\", \"to\", amount, \"datetime\") VALUES (?, ?, ?, DATETIME(?, 'unixepoch'))";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, service.from().c_str(), service.from().length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, service.to().c_str(), service.to().length(), SQLITE_TRANSIENT);
	sqlite3_bind_double(stmt, 3, service.amount());
	sqlite3_bind_int64(stmt, 4, service.transferDate());

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

bool TransferDao::edit(const Transfer& service) {

	if (!getById(service.id())) {
		return false;
	}

	const char* sql = "UPDATE Transfers SET \"from\" = ?, \"to\" = ?, amount = ?, \"datetime\" = DATETIME(?, 'unixepoch') WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, service.from().c_str(), service.from().length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, service.to().c_str(), service.to().length(), SQLITE_TRANSIENT);
	sqlite3_bind_double(stmt, 3, service.amount());
	sqlite3_bind_int64(stmt, 4, service.transferDate());
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

bool TransferDao::remove(const Transfer& service) {
	if (!getById(service.id())) {
		return false;
	}

	const char* sql = "DELETE FROM Transfers WHERE id = ?";

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