//
// Created by bacox on 02-11-19.
//

#include<iostream>
#include <zconf.h>
#include <WebServer.h>


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


    std::cout << "Starting webserver on port 8080" << std::endl;

    WebServer server(8080);
//    ApiHandler myController;
//    Mongoose::Server server(8080);
//    server.registerController(&myController);
//    server.setOption("document_root", "../www");
//    server.setOption("enable_directory_listing", "yes");
//
//    server.start();
    server.start();
    std::cout << "Running" << std::endl;
    server.dumpRoutes();
//    myController.dumpRoutes();
    while (1) {
        usleep(10);
    }

    return 0;
}