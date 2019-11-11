//
// Created by bacox on 06-11-19.
//

#include "WebServer.h"
#include "../../Util/include/TransactionTestGenerator.h"
#include "../../Util/include/Log.h"

WebServer::WebServer(int port) : port(port), server(port){
    configure();
}

void WebServer::configure() {
    server.registerController(&controller);
    server.registerController(&jsonController);
    server.setOption("document_root", "../www");
    server.setOption("enable_directory_listing", "yes");
}

void WebServer::start() {
    EN_INFO("Starting server");
    server.start();
}

void WebServer::stop() {
    EN_INFO("Stopping server");
    server.stop();
}

void WebServer::dumpRoutes() {
    controller.dumpRoutes();
    jsonController.dumpRoutes();
}

void WebServer::generateFakeData() {
    int items = 0;
    Util::TransactionTestGenerator gen;
    while(items++ < 50) {
        Transaction *t = gen.generate();
        TransactionApi::create((*t));
    }
}

void WebServer::reload() {
    stop();
    start();
}
