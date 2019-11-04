//
// Created by bacox on 02-11-19.
//

#include<iostream>
#include <Database.h>
#include "RandomHelper.h"
#include "TransactionTestGenerator.h"


int main(int argc, char *argv[]){
    Database db;

    db.createTransactionTable();

    std::cout << "Generate and retreive single specific transaction" << std::endl;
    Transaction * t = TransactionTestGenerator::generate();
    std::cout << "Generated transaction :: id=" << t->getId() << std::endl;
    int res = db.insertTransaction(*t);
    std::cout << "Insert succesful ? " << res << std::endl;
    Transaction queryOutput = db.getTransactionById(t->getId());
    std::cout << "Retrieved transaction :: id=" << queryOutput.getId() << std::endl;


    queryOutput.setInternalCode("BACOX");
    queryOutput.setId("BACOX");
    std::cout << "Update result : " << db.updateTransaction(queryOutput) << std::endl;
    Transaction queryOutputUpdated = db.getTransactionById(t->getId());
    std::cout << "Retrieved transaction :: id=" << queryOutputUpdated.getId() << " and internal code = " << queryOutputUpdated.getInternalCode() << std::endl;


    std::cout << "Generating new transactions" << std::endl;
//    Transaction * t1 = TransactionTestGenerator::generate();
//    std::cout << (*t1) << std::endl;
    for( int i =0; i < 20; i++) {
        Transaction * t1 = TransactionTestGenerator::generate();
//        std::cout <<  (*t1) << std::endl;
        db.insertTransaction(*t1);
        std::cout << "Size of the transaction table ? " << db.numberOfTransactions() << std::endl;
    }

    std::cout << "Check if table 'transactions' exists ? " << db.tableExists("transactions") << std::endl;
    std::cout << "Check if table 'non_table_bx' exists ? " << db.tableExists("non_table_bx") << std::endl;

    std::cout << "Check if existing transaction exists ? " << db.transactionExists(queryOutputUpdated) << std::endl;
    std::cout << "Check if non-existing transaction exists ? " << db.transactionExists("nonexistingid") << std::endl;

    std::vector<Transaction> transactions = db.getAllTransactions();
    db.emptyTransactiontable();
    db.deleteTransactionTable();
    for( Transaction t : transactions) {
        std::cout << t << std::endl;
    }
    return 0;
}