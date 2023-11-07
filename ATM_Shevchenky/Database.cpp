#include "Database.h"

Database::Database(const string& connectionString = "ATM.db") : 
	_isConnectionOpened(false), _database(nullptr), _connectionString(connectionString) {
	
}

Database::Database(const Database& database) : 
	_isConnectionOpened(database._isConnectionOpened), _database(database._database), 
	_connectionString(database._connectionString) {
	
}

Database::~Database() {
	if (_database != nullptr) {
		closeConnection();
	}
}

void Database::openConnection() {
	if (!_isConnectionOpened) {
		int status = sqlite3_open(_connectionString.c_str(), &_database);

		if (status != SQLITE_OK) {
			throw DatabaseException("Cannot open the database connection!");
		}

		_isConnectionOpened = true;
	}
}

void Database::closeConnection() {
	if (_database != nullptr && _isConnectionOpened) {
		int status = sqlite3_close(_database);

		if (status != SQLITE_OK) {
			throw DatabaseException("Cannot close the database connection!");
		}

		_isConnectionOpened = false;
	}
}

sqlite3* Database::core() { return _database; }

Database::DatabaseException::DatabaseException(const string& message = "DatabaseException occured") : _message(message) {
	
}

Database::DatabaseException::~DatabaseException() {
	
}

const string& Database::DatabaseException::message() const {
	return _message;
}