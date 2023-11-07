#include "TransferDaemonDao.h"

TransferDaemonDao::TransferDaemonDao(const Database& database) : _database(database) {

}

TransferDaemon* TransferDaemonDao::getByFromAndTo(const CardNumber& from, const CardNumber& to) {
	const char* sql = "SELECT \"from\", \"to\", amount, CAST(strftime('%s', next_transfer_datetime) AS INT), frequency, is_active FROM TransferDaemons WHERE \"from\" = ? AND \"to\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, from.c_str(), from.length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, to.c_str(), to.length(), SQLITE_TRANSIENT);

	TransferDaemon* transferDaemon = nullptr;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_ROW) {
			transferDaemon = new TransferDaemon(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				sqlite3_column_double(stmt, 2),
				sqlite3_column_int64(stmt, 3),
				sqlite3_column_int64(stmt, 4),
				sqlite3_column_int64(stmt, 5)
			);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return transferDaemon;
}

vector<TransferDaemon> TransferDaemonDao::getByFrom(const CardNumber& from) {
	const char* sql = "SELECT \"from\", \"to\", amount, CAST(strftime('%s', next_transfer_datetime) AS INT), frequency, is_active FROM TransferDaemons WHERE \"from\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, from.c_str(), from.length(), SQLITE_TRANSIENT);

	vector<TransferDaemon> transferDaemons;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			transferDaemons.push_back(TransferDaemon(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				sqlite3_column_double(stmt, 2),
				sqlite3_column_int64(stmt, 3),
				sqlite3_column_int64(stmt, 4),
				sqlite3_column_int64(stmt, 5)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return transferDaemons;
}

vector<TransferDaemon> TransferDaemonDao::getByTo(const CardNumber& to) {
	const char* sql = "SELECT \"from\", \"to\", amount, CAST(strftime('%s', next_transfer_datetime) AS INT), frequency, is_active FROM TransferDaemons WHERE \"to\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, to.c_str(), to.length(), SQLITE_TRANSIENT);

	vector<TransferDaemon> transferDaemons;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			transferDaemons.push_back(TransferDaemon(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				sqlite3_column_double(stmt, 2),
				sqlite3_column_int64(stmt, 3),
				sqlite3_column_int64(stmt, 4),
				sqlite3_column_int64(stmt, 5)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return transferDaemons;
}

vector<TransferDaemon> TransferDaemonDao::getAllByBankId(const size_t& bankId) {
	const char* sql = "SELECT \"from\", \"to\", amount, CAST(strftime('%s', next_transfer_datetime) AS INT), frequency, is_active FROM TransferDaemons WHERE \"from\" IN (SELECT card_number FROM Cards WHERE account_id IN (SELECT id FROM Accounts WHERE bank_id = ?))";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, bankId);

	vector<TransferDaemon> transferDaemons;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			transferDaemons.push_back(TransferDaemon(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				sqlite3_column_double(stmt, 2),
				sqlite3_column_int64(stmt, 3),
				sqlite3_column_int64(stmt, 4),
				sqlite3_column_int64(stmt, 5)
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return transferDaemons;
}

bool TransferDaemonDao::create(const TransferDaemon& service) {

	const char* sql = "INSERT INTO TransferDaemons(\"from\", \"to\", amount, next_transfer_datetime, frequency, is_active) VALUES (?, ?, ?, DATETIME(?, 'unixepoch'), ?, ?)";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, service.from().c_str(), service.from().length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, service.to().c_str(), service.to().length(), SQLITE_TRANSIENT);
	sqlite3_bind_double(stmt, 3, service.amount());
	sqlite3_bind_int64(stmt, 4, service.nextTransferDate());
	sqlite3_bind_int64(stmt, 5, service.frequency());
	sqlite3_bind_int64(stmt, 6, service.isActive());

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

bool TransferDaemonDao::edit(const TransferDaemon& service) {

	if (!getByFromAndTo(service.from(), service.to())) {
		return false;
	}

	const char* sql = "UPDATE TransferDaemons SET amount = ?, next_transfer_datetime = DATETIME(?, 'unixepoch'), frequency = ?, is_active = ? WHERE \"from\" = ? AND \"to\" = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_double(stmt, 1, service.amount());
	sqlite3_bind_int64(stmt, 2, service.nextTransferDate());
	sqlite3_bind_int64(stmt, 3, service.frequency());
	sqlite3_bind_int64(stmt, 4, service.isActive());
	sqlite3_bind_text(stmt, 5, service.from().c_str(), service.from().length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 6, service.to().c_str(), service.to().length(), SQLITE_TRANSIENT);

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

bool TransferDaemonDao::remove(const TransferDaemon& service) {

	if (!getByFromAndTo(service.from(), service.to())) {
		return false;
	}

	const char* sql = "DELETE FROM TransferDaemons WHERE \"from\" = ? AND \"to\" = ?";

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