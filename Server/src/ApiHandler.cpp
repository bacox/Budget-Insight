//
// Created by bacox on 06-11-19.
//

#include "../include/ApiHandler.h"
void ApiHandler::hello(Mongoose::Request &request, Mongoose::StreamResponse &response) {
    response << "Hello " << htmlEntities(request.get("name", "... what's your name ?")) << endl;
}

void ApiHandler::AddTransaction(Mongoose::Request &request, Mongoose::StreamResponse &response) {
    std::cout << "Api request" << std::endl;



    response.setCode(500);
    response << "Unimplemented";
}

void ApiHandler::GetTransactions(Mongoose::Request &request, Mongoose::StreamResponse &response) {
    std::cout << "Api request" << std::endl;
    response.setCode(500);
    response << "Unimplemented";
}

void ApiHandler::GetTransactionsById(Mongoose::Request &request, Mongoose::StreamResponse &response) {
    std::cout << "Api request" << std::endl;
    response.setCode(500);
    response << "Unimplemented";
}

void ApiHandler::UploadCSVBuffer(Mongoose::Request &request, Mongoose::StreamResponse &response) {
    std::cout << "Api request" << std::endl;
    response.setCode(500);
    response << "Unimplemented";
}