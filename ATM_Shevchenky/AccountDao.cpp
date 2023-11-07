#include "AccountDao.h"

AccountDao::AccountDao(const Database& database) : _database(database) {

}

Account* AccountDao::getById(const size_t& id) {
	const char* sql = "SELECT * FROM Accounts WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, id);

	Account* account = nullptr;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_ROW) {
			account = new Account(
				sqlite3_column_int64(stmt, 0),
				sqlite3_column_double(stmt, 2),
				sqlite3_column_double(stmt, 1),
				sqlite3_column_int64(stmt, 3)
			);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return account;
}

Account* AccountDao::getByCard(const Card& card) {
	const char* sql = "SELECT * FROM Accounts WHERE id IN (SELECT account_id FROM Cards WHERE card_number = ?)";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, card.cardNumber().c_str(), strlen(card.cardNumber().c_str()), SQLITE_TRANSIENT);

	Account* account = nullptr;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_ROW) {
			account = new Account(
				sqlite3_column_int64(stmt, 0),
				sqlite3_column_double(stmt, 2),
				sqlite3_column_double(stmt, 1),
				sqlite3_column_int64(stmt, 3)
			);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return account;
}

Account* AccountDao::getByCardNumber(const CardNumber& number) {
	return getByCard(Card(number));
}

vector<Account> AccountDao::getAllByBank(const Bank& bank) {
	const char* sql = "SELECT * FROM Accounts WHERE bank_id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, bank.id());

	vector<Account> accounts;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			accounts.push_back(Account(
				sqlite3_column_int(stmt, 0),
				sqlite3_column_double(stmt, 2),
				sqlite3_column_double(stmt, 1),
				sqlite3_column_int(stmt, 3)
			));
			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return accounts;
}

vector<Account> AccountDao::getAllByBankId(const size_t& id) {
	return getAllByBank(Bank(id, ""));
}

bool AccountDao::create(const Account& account) {
	const char* sql = "INSERT INTO Accounts(balance, credit_limit, bank_id) VALUES (?, ?, ?)";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_double(stmt, 1, account.balance());
	sqlite3_bind_double(stmt, 2, account.creditLimit());
	sqlite3_bind_int64(stmt, 3, account.bankId());

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

bool AccountDao::edit(const Account& account) {

	if (!getById(account.id())) {
		return false;
	}

	const char* sql = "UPDATE Accounts SET balance = ?, credit_limit = ?, bank_id = ? WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_double(stmt, 1, account.balance());
	sqlite3_bind_double(stmt, 2, account.creditLimit());
	sqlite3_bind_int64(stmt, 3, account.bankId());
	sqlite3_bind_int64(stmt, 4, account.id());

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

bool AccountDao::remove(const Account& account) {

	if (!getById(account.id())) {
		return false;
	}

	const char* sql = "DELETE FROM Accounts WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, account.id());

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