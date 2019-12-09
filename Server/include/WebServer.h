//
// Created by bacox on 06-11-19.
//

#ifndef BUDGET_INSIGHT_SERVER_H
#define BUDGET_INSIGHT_SERVER_H


#include <mongoose/Server.h>
#include "ApiHandler.h"
#include "MyJsonController.h"

class WebServer {
private:
    Mongoose::Server server;
    int port = 8080;
    ApiHandler controller;
    MyJsonController jsonController;
public:
    WebServer(int port);
    void configure();
    void start();
    void stop();
    void dumpRoutes();
    void generateFakeData();
    void reload();
};


#endif //BUDGET_INSIGHT_SERVER_H
