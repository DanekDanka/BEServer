#pragma once

#include <sys/socket.h>
#include <memory>
#include <map>
#include "Sender.h"
#include "Recevier.h"

class Server {
public:
    Server(int port);
    ~Server();

//    void sendMessage();
    void getMessage();

private:
    std::map<std::string, std::string> messages;
    Sender sender;
    Recevier recevier;
};

