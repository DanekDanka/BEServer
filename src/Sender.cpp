#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include "Sender.h"

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
    servaddr.sin_addr.s_addr = inet_addr(ip);
}

void Sender::send(const char *data) {
    sendto(sockfd, data, sizeof(data), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    std::cout << "Message sent" << std::endl;
}

void Sender::receive(char *buffer) {
    size_t n = 0;
    socklen_t len;
    n = recvfrom(sockfd, buffer, maxlen, MSG_WAITALL, (struct sockaddr*)&servaddr, &len);
    buffer[n] = '\0';
    std::cout << "Message received" << std::endl;
}

void Sender::endCommunication() {
    close(sockfd);
}
