//
// Created by bacox on 06-11-19.
//

#ifndef BUDGET_INSIGHT_APIHANDLER_H
#define BUDGET_INSIGHT_APIHANDLER_H


#include <mongoose/WebController.h>

using namespace Mongoose;
class ApiHandler : public Mongoose::WebController{
public:
    void hello(Mongoose::Request &request, Mongoose::StreamResponse &response);

    void AddTransaction(Mongoose::Request &request, Mongoose::StreamResponse &response);

    void GetTransactions(Mongoose::Request &request, Mongoose::StreamResponse &response);

    void GetTransactionsById(Mongoose::Request &request, Mongoose::StreamResponse &response);

    void UploadCSVBuffer(Mongoose::Request &request, Mongoose::StreamResponse &response);
    //Setup routes

    void setup()
    {
        setPrefix("/api");
        addRoute("GET", "/hello", ApiHandler , hello);
        addRoute("GET", "/transaction/add", ApiHandler , AddTransaction);
        addRoute("GET", "/transaction/getMany", ApiHandler , GetTransactions);
        addRoute("GET", "/transaction/get", ApiHandler , GetTransactionsById);
        addRoute("GET", "/upload", ApiHandler , UploadCSVBuffer);
    }
};


#endif //BUDGET_INSIGHT_APIHANDLER_H
