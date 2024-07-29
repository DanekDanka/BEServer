
#include <sstream>
#include <iostream>
#include <algorithm>
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
    if (!messages[name].empty())
        messages[name] += '\n';

    if (data[data.length() - 1] == '\n')
        messages[name] += data.substr(0, data.length() - 1);
    else
        messages[name] += data;
}

std::string Storage::getDataByName(const std::string &name) {
    std::string out;
    for (auto &i: messages) {
        if (name == i.first)
            out += i.second + '\n';
        else if ((name.length() < i.first.length()) && (i.first[name.length()] == '/') &&
                 (name == i.first.substr(0, name.length())))
            out += i.second + '\n';
    }
    out.pop_back();
    return out;
}

void Storage::addError(char *error) {
    errors = buff.str();
}

std::string &Storage::getErrors() {
    return errors;
}
