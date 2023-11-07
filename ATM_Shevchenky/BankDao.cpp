#include "BankDao.h"

BankDao::BankDao(const Database& database, const AccountDao& accountDao, const CardDao& cardDao) :
	_database(database), _cardDao(cardDao), _accountDao(accountDao) { 

}

bool BankDao::addAccountAndCardByBank(const Bank& bank, const Account& account, const Card& card) {

	Card* existingCard = _cardDao.getByNumber(card.cardNumber());
	if (existingCard) {
		delete existingCard;
		return false;
	}

	if (!_accountDao.create(Account(account.creditLimit(), account.balance(), bank.id()))) {
		return false;
	}

	vector<Account> accounts = _accountDao.getAllByBank(bank);

	if (!_cardDao.create(Card(card.cardNumber(), card.pincode(), accounts[accounts.size() - 1].id(), card.expiryDate(), card.type()))) {
		return false;
	}

	return true;
}

bool BankDao::addAccountAndCardByBankId(const size_t& id, const Account& account, const Card& card) {
	return addAccountAndCardByBank(Bank(id, ""), account, card);
}

Bank* BankDao::getById(const size_t& id) {
	const char* sql = "SELECT * FROM Banks WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, id);

	Bank* bank = nullptr;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		if (step == SQLITE_ROW) {
			bank = new Bank(
				sqlite3_column_int64(stmt, 0),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))
			);

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return bank;
}

vector<Bank> BankDao::getAll() {
	const char* sql = "SELECT * FROM Banks";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);

	vector<Bank> banks;

	if (exit == SQLITE_OK) {
		int step = sqlite3_step(stmt);
		while (step == SQLITE_ROW) {
			banks.push_back(Bank(
				sqlite3_column_int64(stmt, 0),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))
			));

			step = sqlite3_step(stmt);
		}
	}

	sqlite3_finalize(stmt);
	_database.closeConnection();

	return banks;
}

bool BankDao::create(const Bank& bank) {
	const char* sql = "INSERT INTO Banks(name) VALUES (?)";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, bank.name().c_str(), bank.name().length(), SQLITE_TRANSIENT);

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

bool BankDao::edit(const Bank& bank) {

	if (!getById(bank.id())) {
		return false;
	}

	const char* sql = "UPDATE Banks SET name = ? WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_text(stmt, 1, bank.name().c_str(), bank.name().length(), SQLITE_TRANSIENT);
	sqlite3_bind_int64(stmt, 2, bank.id());

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

bool BankDao::remove(const Bank& bank) {

	if (!getById(bank.id())) {
		return false;
	}

	const char* sql = "DELETE FROM Banks WHERE id = ?";

	_database.openConnection();

	sqlite3_stmt* stmt;
	int exit = sqlite3_prepare_v2(_database.core(), sql, strlen(sql), &stmt, nullptr);
	sqlite3_bind_int64(stmt, 1, bank.id());

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