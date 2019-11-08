//
// Created by bacox on 08-11-19.
//

#ifndef BUDGET_INSIGHT_JSONCONTROLLER_H
#define BUDGET_INSIGHT_JSONCONTROLLER_H


#include <mongoose/JsonController.h>
using namespace Mongoose;

class MyJsonController : public JsonController{
public:
    void hello(Request &request, JsonResponse &response)
    {
        int i;

        for (i=0; i<12; i++) {
            response["users"][i]["Name"] = "Bob";
        }

        response["timestamp"] = (int)time(NULL);
    }

    void setup()
    {
        // Example of prefix, putting all the urls into "/api"
        setPrefix("/api-v2");

        // Hello demo
        addRouteResponse("GET", "/", MyJsonController, hello, JsonResponse);
        addRouteResponse("GET", "/hello", MyJsonController, hello, JsonResponse);
    }
};


#endif //BUDGET_INSIGHT_JSONCONTROLLER_H
