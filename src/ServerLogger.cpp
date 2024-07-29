#include "ServerLogger.h"

ServerLogger &ServerLogger::initialisation() {
    static ServerLogger error;
    return error;
}

void ServerLogger::error(const char *err) {
    std::string error = err;
    if (error.at(error.size() - 1) == '\n') {
        fprintf(stderr, "%s", error.data());
        error.pop_back();
        errors.emplace_back(error);
    } else {
        errors.emplace_back(error);
        error.push_back('\n');
        fprintf(stderr, "%s", error.data());
    }
}

std::vector<std::string> &ServerLogger::getErrors() {
    return errors;
}

void ServerLogger::log(const char *str) {
    std::string string = str;
    if (string.at(string.size() - 1) == '\n') {
        fprintf(stdout, "%s", string.data());
    } else {
        string.push_back('\n');
        fprintf(stdout, "%s", string.data());
    }
}

void ServerLogger::log(std::string &str) {
    if (str.at(str.size() - 1) == '\n') {
        fprintf(stdout, "%s", str.data());
    } else {
        str.push_back('\n');
        fprintf(stdout, "%s", str.data());
    }
}


