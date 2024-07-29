#pragma once

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include "ServerLogger.h"

class Sender {
public:
    Sender();
    ~Sender();

    void init(int PORT, const char *ip);            //TODO: для отправления нескольким клиентам
    void send(const char * data);
    void endCommunication();

private:
    int maxlen;
    int sockfd;
    struct sockaddr_in servaddr;
    ServerLogger &logger {ServerLogger::initialisation()};
};


