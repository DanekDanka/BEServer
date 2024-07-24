#pragma once

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>

class Sender {
public:
    Sender();
    ~Sender();

    void init(int PORT, const char *ip);
    void send(const char * data);
    void receive(char * buffer);
    void endCommunication();

private:
    int maxlen;
    int sockfd;
    struct sockaddr_in servaddr;
};


