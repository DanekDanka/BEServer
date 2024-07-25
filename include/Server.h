#pragma once

#include <sys/socket.h>
#include <memory>
#include <map>
#include <vector>
#include "Sender.h"
#include "Recevier.h"
#include "Storage.h"

class Server {
public:
    Server(int port);
    ~Server();

    void sendMessage(const std::string& name);
    void getMessage();
    static void readMessage(std::string &name, std::string &data, const char *buff);
    void handler();         //TODO: плохое название, переделать

private:
    std::mutex mutex;
    std::vector<std::thread> threads;

    Storage storage;
    Sender sender;
    Recevier recevier;
    std::string nameSendedMessage;
};

