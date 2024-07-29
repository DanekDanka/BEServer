
#include <sstream>
#include <iostream>
#include "Storage.h"
#include "ServerLogger.h"

Storage::Storage() {
    std::cerr.rdbuf(buff.rdbuf());
}

void Storage::setData(char *buff) {
    std::string name;
    std::string data;
    std::istringstream in(buff);
    in >> name;
    std::getline(in, data);

    if (!data.empty()) {
        messages[name] += data.substr(5, data.length() - 1);
    }
    std::cout << messages[name] << " MESSAGE" << std::endl;
}

void Storage::setData(const std::string &name, const std::string &data) {
    messages[name] += data;
}

std::string Storage::getDataByName(const std::string &name) {
    return messages[name].substr(0, messages[name].length() - 1);
}

void Storage::addError(char *error) {
    errors = buff.str();
}

std::string &Storage::getErrors() {
    return errors;
}
