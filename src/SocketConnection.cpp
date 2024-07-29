#include "SocketConnection.h"

#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include "Sender.h"


void SocketConnection::init(int PORT, std::string &ip) {
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "socket creation failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *) &servaddr,
             sizeof(servaddr)) < 0) {
        std::cerr << "bind failed" << std::endl;
        close(sockfd);
        exit(EXIT_FAILURE);
    }

}

void SocketConnection::send(const char *data) {
    sendto(sockfd, data, strlen(data), 0, (const struct sockaddr *)&cliaddr, sizeof(cliaddr));
    std::cout << "Message sent" << std::endl;
}

void SocketConnection::receive(char * buff) {
    socklen_t len;
    int n;

    len = sizeof(cliaddr);

    n = recvfrom(sockfd, (char *) buff, 1014,
                 MSG_WAITALL, (struct sockaddr *) &cliaddr,
                 &len);
    buff[n] = '\0';
}

void SocketConnection::endCommunication() {
    close(sockfd);
}