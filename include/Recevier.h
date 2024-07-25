#pragma once

#include <netinet/in.h>

class Recevier {
public:
    Recevier() = default;
    ~Recevier() = default;

    void init(int port);
    void receive(char *buff);


private:
    int sockfd;
    struct sockaddr_in servaddr;
    struct sockaddr_in cliaddr;
};
