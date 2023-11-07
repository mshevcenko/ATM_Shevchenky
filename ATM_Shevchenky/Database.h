#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include "sqlite/sqlite3.h"

using namespace std;

using CardNumber = string;
using Currency = int;
using Money = double;

class ATM;
class Bank;
class Account;
class Card;
class Transfer;
class TransferDaemon;
class MoneyStorage;
class OverflowCreditService;
class OverflowService;
class WithdrawalService;
class ATMDao;
class BankDao;
class AccountDao;
class CardDao;
class TransferDao;
class TransferDaemonDao;
class OverflowCreditServiceDao;
class OverflowServiceDao;
class WithdrawalServiceDao;
class MoneyStorageDao;

class Database {
private:
	sqlite3* _database;
	const string _connectionString;
	bool _isConnectionOpened;
public:
	template <typename T>
	class DatabaseQueryItem;
	class DatabaseException;

	enum DataTypes {
		TEXT,
		INT,
		REAL,
		BLOB,
	};

	void openConnection();
	void closeConnection();

	Database(const string&);
	Database(const Database&);
	~Database();
	Database& operator=(const Database&)& = delete;

	sqlite3* core();
};

class Database::DatabaseException {
private: 
	const string _message;
	DatabaseException& operator=(const DatabaseException&)& = delete;
public:
	DatabaseException(const string&);
	~DatabaseException();
	const string& message() const;
};