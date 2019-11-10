//
// Created by bacox on 08-11-19.
//

#include "MyJsonController.h"

void MyJsonController::GetAllTransactions(Request &request, JsonResponse &response) {
    //        Json::Value root;
    std::vector<Transaction> list = TransactionApi::getAll();
    if(list.size() > 0) {
        for (Transaction t: list) {
            response.append(Serializer::TransactionToJson(t));
        }
    } else {
        response["data"] = Json::Value(Json::arrayValue);;
    }
}

void MyJsonController::GetTransactionsById(Request &request, JsonResponse &response) {
    std::string id = request.get("id", "-1");
    Transaction t = TransactionApi::getById(id);

    std::cout << "Found the id in the url: " << id << std::endl;
    response["transaction"] = Serializer::TransactionToJson(t);
}
