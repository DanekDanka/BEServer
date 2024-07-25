#include <iostream>
#include <thread>
#include <sstream>
#include "../include/Server.h"
#include "../include/Fabric.h"

Server::Server(int port) {
    sender.init(port + 1, "127.0.0.1");       //TODO: для отправления нескольким клиентам
    recevier.init(port);
}

Server::~Server() {
    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();

    sender.endCommunication();
}

void Server::getMessage() {
    char buff[1014];
    recevier.receive(buff);
    std::string name;
    std::string data;
    readMessage(name, data, buff);

    if (!data.empty()) {
        mutex.lock();
        storage.setData(name, data);
        std::cout << name << data << std::endl;
        mutex.unlock();
    } else {
        mutex.lock();
        nameSendedMessage = name;
        mutex.unlock();
    }
}

void Server::readMessage(std::string &name, std::string &data, const char *buff) {
    std::istringstream in(buff);
    in >> name;
    std::getline(in, data);
}

void Server::handler() {
    threads.emplace_back([&] {
        while (true) {
            getMessage();
        }
    });
    while (true) {
        if (!nameSendedMessage.empty()) {
            sendMessage(nameSendedMessage);
            nameSendedMessage.clear();
        }
    }
}

void Server::sendMessage(const std::string& name) {
    sender.send(storage.getDataByName(nameSendedMessage).data());
}



