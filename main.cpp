//
// Created by bacox on 02-11-19.
//

#include<iostream>
#include <WebServer.h>
#include "Util/include/Log.h"
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
    Util::Log::Init();
    int port = 8080;

    EN_CORE_INFO("Starting webserver on port {}!", port);
//    spdlog::info("Starting webserver on port {}!", port);

    WebServer server(8080);
    server.generateFakeData();
    server.start();
    EN_CORE_INFO("Running");
    server.dumpRoutes();
    while (1) {
        ApiHandler::sleep(10);
    }

    return 0;
}