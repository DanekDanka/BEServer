#include <iostream>
#include <thread>
#include <sstream>
#include "../include/Server.h"
#include "ServerLogger.h"

Server::Server(int port, char *ip) {
    socket.init(port, ip);
}

Server::~Server() {
    for (int i = 0; i < threads.size(); ++i)
        threads[i].join();

    socket.endCommunication();
}

void Server::getMessage() {
    char buff[1014];
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
    threads.emplace_back([&] {
        while (true) {
            std::string str;
            std::cin >> str;
            if (str == "exit") {
                socket.endCommunication();
                exit(EXIT_SUCCESS);         // очевидно что так заканчивать программу не стоит, но в данном случае
                // это не большой проет и на мой взгляд добавлене сюда полноценной
                // точки выхода излишне. (Да, нужно будет немного подправить циклы
                // в потоках, чтобы все завершалось корректно и добавить опрашивание
                // атомика, например, на предмет того, нужно ли завершать работу)
            }
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
    socket.send("-BEGIN-");
    socket.send(storage.getDataByName(nameSendedMessage).data());
    socket.send("-END-");
}

void Server::sendErrors() {
    socket.send("-ERROR-");
    for (int i = 0; i < logger.getErrors().size(); ++i) {
        socket.send(logger.getErrors().at(i).data());
    }
    socket.send("-END-");
}



