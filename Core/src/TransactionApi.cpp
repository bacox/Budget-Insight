//
// Created by bacox on 05-11-19.
//

#include <Database.h>
#include "TransactionApi.h"

int TransactionApi::count() {
    Database &db = Database::getInstance();
    if(!db.tableExists(Database::TRANSACTIONTABLE))
        return 0;
    return db.numberOfTransactions();
}

std::vector<Transaction> TransactionApi::getAll() {
    Database &db = Database::getInstance();
    return db.getAllTransactions();
}

Transaction TransactionApi::getById(std::string id) {
    Database &db = Database::getInstance();
    return db.getTransactionById(id);
}

Transaction TransactionApi::update(Transaction &t) {
    Database &db = Database::getInstance();
    if(db.transactionExists(t.getId())) {
        return t;
    }
    if(db.updateTransaction(t)) {
        return db.getTransactionById(t.getId());
    }
    // @TODO: Should return an error or some notion that the update has failed
    return t;
}

bool TransactionApi::remove(Transaction &t) {
    return false;
}

bool TransactionApi::remove(std::string id) {
    return false;
}

Transaction TransactionApi::create(Transaction &t) {
    Database &db = Database::getInstance();
    if(db.transactionExists(t)){
        return t;
    }
    if(db.insertTransaction(t)) {
        return db.getTransactionById(t.getId());
    }
    return t;
}

bool TransactionApi::exists(Transaction &t) {
    Database &db = Database::getInstance();
    return db.transactionExists(t);
}

bool TransactionApi::exists(std::string id) {
    Database &db = Database::getInstance();
    return db.transactionExists(id);
}

bool TransactionApi::removeAll() {
    Database &db = Database::getInstance();
    db.emptyTransactiontable();
//    db.deleteTransactionTable();
}
