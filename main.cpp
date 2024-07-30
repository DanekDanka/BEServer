
#include <bits/stdc++.h>
#include <stdlib.h>
#include "include/Server.h"
#include "ServerLogger.h"

int main(int argc, char *argv[]) {
    if (argc == 0) {
        std::cerr << "Введено неправильное количество параметров" << '\n' << "Введите: port" << std::endl;
        return 1;
    }
    ServerLogger &logger = ServerLogger::initialisation();

    Server server(atoi(argv[2]), argv[1]);
    server.handler();

    return 0;
}
