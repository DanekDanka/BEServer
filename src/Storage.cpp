
#include <sstream>
#include <iostream>
#include "Storage.h"

void Storage::setData(char *buff) {
    std::string name;
    std::string data;
    std::istringstream in(buff);
    in >> name;
    std::getline(in, data);

    messages[name] += data;

    std::cout << "name " << name << '\n' << "data " << messages[name] << std::endl;

}

void Storage::setData(const std::string& name, const std::string& data) {
    messages[name] += data;
}

std::string Storage::getDataByName(const std::string& name) {
    return messages[name];
}

//void Storage::addError(char *error) {
//}
