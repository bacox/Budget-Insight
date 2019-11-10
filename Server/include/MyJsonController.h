//
// Created by bacox on 08-11-19.
//

#ifndef BUDGET_INSIGHT_JSONCONTROLLER_H
#define BUDGET_INSIGHT_JSONCONTROLLER_H


#include <mongoose/JsonController.h>
#include <TransactionApi.h>
#include "Serializer.h"

using namespace Mongoose;

class MyJsonController : public JsonController{
public:
//    void hello(Request &request, JsonResponse &response)
//    {
//        int i;
//
//        for (i=0; i<12; i++) {
//            response["users"][i]["Name"] = "Bob";
//        }
//
//        response["timestamp"] = (int)time(NULL);
//    }
//
//    void GetTransactionsById(Request &request, JsonResponse &response)
//    {
//        std::string id = request.get("id", "-1");
//        Transaction t = TransactionApi::getById(id);
//
//        std::cout << "Found the id in the url: " << id << std::endl;
//        response["transaction"] = Serializer::TransactionToJson(t);
//    }
//    void GetAllTransactions(Request &request, JsonResponse &response)
//    {
////        Json::Value root;
//        std::vector<Transaction> list = TransactionApi::getAll();
//        if(list.size() > 0) {
//            for (Transaction t: list) {
//                response.append(Serializer::TransactionToJson(t));
//            }
//        } else {
//            response["data"] = Json::Value(Json::arrayValue);;
//        }
//
//    }

    void GetTransactionsById(Request &request, JsonResponse &response);

    void GetAllTransactions(Request &request, JsonResponse &response);


    void setup()
    {
        // Example of prefix, putting all the urls into "/api"
        setPrefix("/api-v2");

        // Hello demo
//        addRouteResponse("GET", "/", MyJsonController, hello, JsonResponse);
//        addRouteResponse("GET", "/hello", MyJsonController, hello, JsonResponse);
        addRouteResponse("GET", "/test", MyJsonController, GetTransactionsById, JsonResponse);
        addRouteResponse("GET", "/all", MyJsonController, GetAllTransactions, JsonResponse);
    }
};


#endif //BUDGET_INSIGHT_JSONCONTROLLER_H
