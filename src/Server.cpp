#include <iostream>
#include <thread>
#include <sstream>
#include "../include/Server.h"
#include "../include/Fabric.h"
#include "ServerLogger.h"

Server::Server(int port, char *ip) {
//    sender.init(port + 1, ip.data());       //TODO: для отправления нескольким клиентам
//    recevier.init(port);
    socket.init(port, ip);
}

Server::~Server() {
    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();

//    sender.endCommunication();
    socket.endCommunication();
}

void Server::getMessage() {
    char buff[1014];
//    recevier.receive(buff);
    socket.receive(buff);
    std::string name;
    std::string data;
    readMessage(name, data, buff);

    if (!data.empty()) {
        mutex.lock();
        data = data.substr(1, data.length() - 1) + '\n';
        storage.setData(name, data);
        name.push_back('\n');
        logger.log(name);
        logger.log(data);
        mutex.unlock();
    } else {
        mutex.lock();
        nameSendedMessage = name;
        mutex.unlock();
    }

    //перехват вывода из cerr
//    std::stringstream buffer;
//    auto originalStderr = std::cerr.rdbuf();
//    std::cerr.rdbuf(buffer.rdbuf());
//    std::cerr << "[ERROR] ";
//    std::cerr.rdbuf(originalStderr);
//    std::string output = buffer.str();
//    std::cout << output;


//    ServerLogger &err = ServerLogger::initialisation();
//    err.error("[ERROR]\n");
//    std::cout << err.getErrors();

//    mutex.lock();
//    checkErrors();
//    mutex.unlock();
}

void Server::readMessage(std::string &name, std::string &data, const char *buff) {
    std::istringstream in(buff);
    in >> name;

    if (name.size() >= 64)
        logger.error("[ERROR] Имя ресурса более 64 байт\n");
    std::getline(in, data);
}

void Server::handler() {
    threads.emplace_back([&] {
        while (true) {
            getMessage();
        }
    });
    while (true) {
        if (!logger.getErrors().empty()) {
            sendErrors();
            logger.getErrors().clear();
        } else if (!nameSendedMessage.empty()) {
            if (storage.getDataByName(nameSendedMessage).length() < 1014) {
                sendMessage(nameSendedMessage);
                nameSendedMessage.clear();
            } else {
                nameSendedMessage.clear();
                logger.error("[ERROR] Возвращаемое сообщение более 1024 байт\n");
                sendErrors();
                logger.getErrors().clear();
            }
        }
    }
}

    void Server::sendMessage(const std::string &name) {
//    sender.send("-BEGIN-");
//    sender.send(storage.getDataByName(nameSendedMessage).data());
//    sender.send("-END-");
        socket.send("-BEGIN-");
        socket.send(storage.getDataByName(nameSendedMessage).data());
        socket.send("-END-");
    }

    void Server::checkErrors() {
        if (!storage.getErrors().empty()) {
//        sender.send(storage.getErrors().data());
            socket.send(storage.getErrors().data());
            storage.getErrors().clear();
            nameSendedMessage.clear();
        }
    }

    void Server::sendErrors() {
//    sender.send("-ERROR-");
        socket.send("-ERROR-");
        for (int i = 0; i < logger.getErrors().size(); ++i) {
//        sender.send(logger.getErrors().at(i).data());
            socket.send(logger.getErrors().at(i).data());
        }
//    sender.send("-END-");
        socket.send("-END-");
    }



