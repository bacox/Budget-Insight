//
// Created by bacox on 02-11-19.
//

#include<iostream>
#include <WebServer.h>
#include "spdlog/spdlog.h"

int main(int argc, char *argv[]){

//    Importer import;
//    std::vector<Transaction> transactions = import.csv("../../data.csv");
//    for( Transaction t : transactions) {
//        TransactionApi::create(t);
//    }
//
//    std::vector<Transaction> dbTransactions = TransactionApi::getAll();
//    for( const Transaction& transaction : dbTransactions) {
//        std::cout << transaction << std::endl;
//    }
    int port = 8080;
    spdlog::info("Starting webserver on port {}!", port);

    WebServer server(8080);
    server.generateFakeData();
    server.start();
    spdlog::info("Running");
    server.dumpRoutes();
    while (1) {
        ApiHandler::sleep(10);
    }

    return 0;
}