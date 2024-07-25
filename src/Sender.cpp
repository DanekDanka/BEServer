#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include "../include/Sender.h"

Sender::Sender() {}

Sender::~Sender() {

}

void Sender::init(int PORT, const char *ip) {
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "[ERROR] Socket creation failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
}

void Sender::send(const char *data) {
    sendto(sockfd, data, strlen(data), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    std::cout << "Message sent" << std::endl;
}

void Sender::endCommunication() {
    close(sockfd);
}
