#pragma once

#include <string>
#include <vector>

class ServerLogger {
public:
    static ServerLogger& initialisation();

    void error(const char * err);
    void log(const char * str);
    void log(std::string &str);
    std::vector<std::string> &getErrors();

private:
    ServerLogger() = default;
    ~ServerLogger() = default;

    ServerLogger(ServerLogger const&) = delete;
    ServerLogger & operator= (ServerLogger const&) = delete;

    std::vector<std::string> errors;
};


