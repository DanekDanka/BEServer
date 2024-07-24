#pragma once

#include <sys/socket.h>
#include <memory>
#include "IMessage.h"
#include "Sender.h"

class Client {
public:
    Client(int port, char * ip);
    ~Client();

    void setMessage(std::string &name, std::string &data);
    void sendMessage();


private:
    std::unique_ptr<IMessage> message {};
    Sender sender;
    int port{};
    std::string ip;
};

