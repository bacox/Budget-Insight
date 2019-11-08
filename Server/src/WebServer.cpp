//
// Created by bacox on 06-11-19.
//

#include "WebServer.h"


WebServer::WebServer(int port) : port(port), server(port){
    configure();
}

void WebServer::configure() {
    server.registerController(&controller);
    server.registerController(&jsonController);
    server.setOption("document_root", "../../www");
    server.setOption("enable_directory_listing", "yes");
}

void WebServer::start() {
    server.start();
}

void WebServer::stop() {
    server.stop();
}

void WebServer::dumpRoutes() {
    controller.dumpRoutes();
}
