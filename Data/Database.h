//
// Created by bacox on 03-11-19.
//

#ifndef BUDGET_INSIGHT_DATABASE_H
#define BUDGET_INSIGHT_DATABASE_H
#include <SQLiteCpp/SQLiteCpp.h>
#include <vector>
#include "../Transaction.h"


class Database {
private:
    std::string databaseFile = "storage.db3";
    SQLite::Database db;
    const std::string TRANSACTIONTABLE = "transactions";

    std::string transactionValuesUtil(Transaction &t);
    std::string transactionValuesTypesUtil(Transaction &t);
    int tableSize(std::string tableName);


public:
    Database();

    void createTransactionTable();
    void emptyTransactiontable();
    void deleteTransactionTable();

    bool tableExists(std::string tableName);

    bool transactionExists(Transaction &t);
    bool transactionExists(std::string id);

    int insertTransaction(Transaction &t);

    int updateTransaction(Transaction &t);

    int deleteTransaction(std::string id);

    int numberOfTransactions();

    std::vector<Transaction> getAllTransactions();
    Transaction getTransactionById(std::string id);

    virtual ~Database();
//    ("test.db3", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
};


#endif //BUDGET_INSIGHT_DATABASE_H
