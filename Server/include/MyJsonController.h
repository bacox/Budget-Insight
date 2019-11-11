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

private:
    void CreateErrorResult(JsonResponse &res, std::string &reason);
    void CreateSuccessResult(JsonResponse &res, Json::Value &data);

public:

    void GetTransactionsById(Request &request, JsonResponse &response);
    void GetAllTransactions(Request &request, JsonResponse &response);

    void setup()
    {
        setPrefix("/api-v2");

        addRouteResponse("GET", "/getById", MyJsonController, GetTransactionsById, JsonResponse);
        addRouteResponse("GET", "/getAll", MyJsonController, GetAllTransactions, JsonResponse);
    }
};

#endif //BUDGET_INSIGHT_JSONCONTROLLER_H
