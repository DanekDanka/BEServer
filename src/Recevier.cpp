#include <iostream>
#include <cstring>
#include <sstream>
#include "Recevier.h"

#include "Recevier.h"


void Recevier::init(int port) {
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "socket creation failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (const struct sockaddr *) &servaddr,
             sizeof(servaddr)) < 0) {
        std::cerr << "bind failed" << std::endl;
        exit(EXIT_FAILURE);
    }

}

void Recevier::receive(char * buff) {
    socklen_t len;
    int n;

    len = sizeof(cliaddr);

    n = recvfrom(sockfd, (char *) buff, 1014,
                 MSG_WAITALL, (struct sockaddr *) &cliaddr,
                 &len);
    buff[n] = '\0';
}
