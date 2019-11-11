//
// Created by bacox on 08-11-19.
//

#include "MyJsonController.h"

void MyJsonController::GetAllTransactions(Request &request, JsonResponse &response) {

    response["result"] = "error";
    //        Json::Value root;
    std::vector<Transaction> list = TransactionApi::getAll();
    if(list.size() > 0) {
        Json::Value transactions= Json::Value(Json::arrayValue);
        for (Transaction t: list) {
            transactions.append(Serializer::TransactionToJson(t));
        }
        CreateSuccessResult(response, transactions);
    } else {
        std::string reason = "No transactions";
        CreateErrorResult(response, reason);
    }
//    response["aux"] = "Hello world";
}

void MyJsonController::GetTransactionsById(Request &request, JsonResponse &response) {
    std::string id = request.get("id", "-1");
    Transaction t = TransactionApi::getById(id);

    std::cout << "Found the id in the url: " << id << std::endl;
    Json::Value data = Serializer::TransactionToJson(t);
//    Json::Value d2 = Json::Value(Json::arrayValue);
    CreateSuccessResult(response, data);
}

void MyJsonController::CreateErrorResult(JsonResponse &res, std::string &reason) {
    res["result"] = "error";
    res["error"] = Json::Value();
    res["error"]["reason"] = reason;
    res["data"] = Json::Value(Json::arrayValue);
}

void MyJsonController::CreateSuccessResult(JsonResponse &res, Json::Value &data) {
    res["result"] = "success";
    res["data"] = data;
}
