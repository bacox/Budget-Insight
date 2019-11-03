//
// Created by bacox on 03-11-19.
//

#include <iostream>
#include <sstream>
#include "Database.h"

Database::Database() :db(databaseFile, SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE){
    ;
}

Database::~Database() {

}

void Database::createTransactionTable() {
    // Create a new table with an explicit "id" column aliasing the underlying rowid
    deleteTransactionTable();
    std::string tableItems = "id TEXT PRIMARY KEY";
    tableItems += " , date TEXT";
    tableItems += " , iban TEXT";
    tableItems += " , ibanAgainst TEXT";
    tableItems += " , valuta TEXT";
    tableItems += " , balance REAL";
    tableItems += " , mutationAmount REAL";
    tableItems += " , journalDate TEXT";
    tableItems += " , internalCode TEXT";
    tableItems += " , globalCode TEXT";

    db.exec("CREATE TABLE " + TRANSACTIONTABLE + " (" + tableItems + ")");
}

void Database::emptyTransactiontable() {
    db.exec("DELETE FROM " + TRANSACTIONTABLE);
}

void Database::deleteTransactionTable() {
    db.exec("DROP TABLE IF EXISTS " + TRANSACTIONTABLE);
}

void Database::insertTransaction(Transaction &t) {
    // first row
    std::stringstream values;
    values << "\"" << t.getId() << "\"";
    values << ", " << "\"" << t.getDate() << "\"";
    values << ", " << "\"" << t.getBanknumber() << "\"";
    values << ", " << "\"" << t.getBanknumberAgainst() << "\"";
    values << ", " << "\"" << t.getValuta()  << "\"";
    values << ", " << "\"" << t.getBalanceBeforeMutation() << "\"";
    values << ", " << "\"" << t.getMutationAmount() << "\"";
    values << ", " << "\"" << t.getJournalDate() << "\"";
    values << ", " << "\"" << t.getInternalCode() << "\"";
    values << ", " << "\"" << t.getGlobalCode() << "\"";
    std::string queryString = "INSERT INTO " + TRANSACTIONTABLE + " VALUES (" + values.str() + ")";
    int nb = db.exec(queryString);
//    std::cout << queryString << ", returned " << nb << std::endl;
}

std::vector<Transaction> Database::getAllTransactions() {
    std::vector<Transaction> transactions;
    SQLite::Statement   query(db, "SELECT * FROM " + TRANSACTIONTABLE);
    while (query.executeStep())
    {
        std::string id = query.getColumn(0);
        std::string date = query.getColumn(1);
        std::string iban = query.getColumn(2);
        std::string iban2 = query.getColumn(3);
        std::string valuta = query.getColumn(4);
        long mutationBalance = query.getColumn(5);
        long mutationAmount = query.getColumn(6);
        std::string journalDate = query.getColumn(7);
        std::string internalCode = query.getColumn(8);
        std::string globalCode = query.getColumn(9);
        Transaction transaction(date, iban, iban2, valuta, mutationBalance, mutationAmount, journalDate, internalCode, globalCode, id);
        transactions.push_back(transaction);
    }
    return transactions;
}
