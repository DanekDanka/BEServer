
#include <bits/stdc++.h>
#include <stdlib.h>
#include "include/Server.h"

#define PORT     8080
#define MAXLINE 1024

// 0    port
int main(int argc, char* argv[]) {
    if (argc == 0) {
        std::cerr << "Введено неправильное количество параметров" << '\n' << "Введите: port" << std::endl;
        return 0;
    }

    Server server(atoi(argv[1]));
    server.handler();

    return 0;
}
