#pragma once

#include <sys/socket.h>
#include <memory>
#include <map>
#include <vector>
#include "Storage.h"
#include "SocketConnection.h"
#include "ServerLogger.h"

class Server {
public:
    Server(int port, char *ip);

    ~Server();

    void sendMessage(const std::string &name);

    void getMessage();

    void readMessage(std::string &name, std::string &data, const char *buff);

    void handler();         //TODO: плохое название, переделать
    void sendErrors();

private:
    std::mutex mutex;
    std::vector<std::thread> threads;

    Storage storage;
    SocketConnection socket;
    std::string nameSendedMessage;
    ServerLogger &logger{ServerLogger::initialisation()};
};

