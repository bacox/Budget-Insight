//
// Created by bacox on 02-11-19.
//

#include<iostream>
#include <Importer.h>
#include <TransactionApi.h>


int main(int argc, char *argv[]){

    Importer import;
    std::vector<Transaction> transactions = import.csv("../../data.csv");
    for( Transaction t : transactions) {
        TransactionApi::create(t);
    }

    std::vector<Transaction> dbTransactions = TransactionApi::getAll();
    for( const Transaction& transaction : dbTransactions) {
        std::cout << transaction << std::endl;
    }

    return 0;
}