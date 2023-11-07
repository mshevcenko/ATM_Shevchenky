#include "CardDao.h"

CardDao::CardDao(const Database& database) : _database(database) {

}

Card* CardDao::getByNumber(const CardNumber& number) {
	const char* sql = "SELECT card_number, CAST(strftime('%s', expiration_date) AS INT), pincode, account_id, type FROM Cards WHERE card_number = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, number.c_str(), number.length(), SQLITE_TRANSIENT);

	Card* card = nullptr;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_ROW) {
			card = new Card(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_int64(stmt, 3),
				sqlite3_column_int64(stmt, 1),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)) == "Credit" ? Card::Type::Credit : Card::Type::Debit
			);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return card;
}

Card* CardDao::getByAccount(const Account& account) {
	const char* sql = "SELECT card_number, CAST(strftime('%s', expiration_date) AS INT), pincode, account_id, type FROM Cards WHERE account_id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int(stmt, 1, account.id());

	Card* card = nullptr;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_ROW) {
			card = new Card(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_int64(stmt, 3),
				sqlite3_column_int64(stmt, 1),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)) == "Credit" ? Card::Type::Credit : Card::Type::Debit
			);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return card;
}

Card* CardDao::getByAccountId(const size_t& account_id) {
	return getByAccount(Account(account_id));
}

bool CardDao::create(const Card& card) {
	const char* sql = "INSERT INTO Cards(card_number, pincode, expiration_date, account_id, type) VALUES (?, ?, DATETIME(?, 'unixepoch'), ?, ?)";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	string cardType = card.type() == Card::Type::Credit ? "Credit" : "Debit";
	sqlite3_bind_text(stmt, 1, card.cardNumber().c_str(), card.cardNumber().length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, card.pincode().c_str(), card.pincode().length(), SQLITE_TRANSIENT);
	sqlite3_bind_int64(stmt, 3, card.expiryDate());
	sqlite3_bind_int64(stmt, 4, card.accountId());
	sqlite3_bind_text(stmt, 5, cardType.c_str(), cardType.length(), SQLITE_TRANSIENT);

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

bool CardDao::edit(const Card& card) {

	if (!getByNumber(card.cardNumber())) {
		return false;
	}

	const char* sql = "UPDATE Cards SET pincode = ?, expiration_date = DATETIME(?, 'unixepoch'), account_id = ?, type = ? WHERE card_number = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	string cardType = card.type() == Card::Type::Credit ? "Credit" : "Debit";
	sqlite3_bind_text(stmt, 1, card.pincode().c_str(), card.pincode().length(), SQLITE_TRANSIENT);
	sqlite3_bind_int64(stmt, 2, card.expiryDate());
	sqlite3_bind_int64(stmt, 3, card.accountId());
	sqlite3_bind_text(stmt, 4, cardType.c_str(), cardType.length(), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 5, card.cardNumber().c_str(), card.cardNumber().length(), SQLITE_TRANSIENT);

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

bool CardDao::remove(const Card& card) {

	if (!getByNumber(card.cardNumber())) {
		return false;
	}

	const char* sql = "DELETE FROM Cards WHERE card_number = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, card.cardNumber().c_str(), card.cardNumber().length(), SQLITE_TRANSIENT);

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