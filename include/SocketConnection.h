#pragma once

#include <netinet/in.h>
#include <string>

class SocketConnection {
public:
    SocketConnection() = default;
    ~SocketConnection() = default;

    void init(int PORT, std::string &ip);

    void receive(char *buff);
    void send(const char * data);
    void endCommunication();

private:
    int maxlen;
    int sockfd;
    struct sockaddr_in servaddr;
    struct sockaddr_in cliaddr;
};


