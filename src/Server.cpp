#include "../include/Server.h"
#include "../include/Fabric.h"

Server::Server(int port) {
//    sender.init(port);
    recevier.init(port);
}

void Server::getMessage() {
    recevier.receive();
}

Server::~Server() = default;


//void Server::sendMessage() {
//    sender.send((message->getName() + message->getData()).data());
//}
