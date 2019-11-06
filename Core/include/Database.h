//
// Created by bacox on 03-11-19.
//

#ifndef BUDGET_INSIGHT_DATABASE_H
#define BUDGET_INSIGHT_DATABASE_H
#include <vector>
#include <SQLiteCpp/SQLiteCpp.h>
#include "Transaction.h"


class Database {
private:
    std::string databaseFile = "storage.db3";
    SQLite::Database db;
    std::string transactionValuesUtil(Transaction &t);

    std::string transactionValuesTypesUtil(Transaction &t);
    int tableSize(std::string tableName);
public:


    static const std::string TRANSACTIONTABLE;
    static Database& getInstance()
    {
        static Database instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
private:
    Database();                   // Constructor? (the {} brackets) are needed here.

    // C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
public:
    Database(Database const&)               = delete;
    void operator=(Database const&)  = delete;

    // Note: Scott Meyers mentions in his Effective Modern
    //       C++ book, that deleted functions should generally
    //       be public as it results in better error messages
    //       due to the compilers behavior to check accessibility
    //       before deleted status

private:
    void init();

public:
//    Database();

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

//    virtual ~Database();
//    ("test.db3", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
};


#endif //BUDGET_INSIGHT_DATABASE_H
