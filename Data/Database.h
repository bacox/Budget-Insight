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

public:
    Database();

    void createTransactionTable();
    void emptyTransactiontable();
    void deleteTransactionTable();

    void insertTransaction(Transaction &t);

    std::vector<Transaction> getAllTransactions();


    virtual ~Database();
//    ("test.db3", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
};


#endif //BUDGET_INSIGHT_DATABASE_H
