#pragma once

#include <netinet/in.h>

class Recevier {
public:
    Recevier() = default;
    ~Recevier() = default;

    void init(int port);
    void receive();


private:
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr;
    struct sockaddr_in cliaddr;
};
