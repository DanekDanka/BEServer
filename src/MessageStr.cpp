#include "MessageStr.h"

MessageStr::MessageStr() = default;

MessageStr::~MessageStr() = default;

void MessageStr::setData(std::string &newData) {
    data = newData;
}

void MessageStr::setName(std::string &newName) {
    name = newName;
}

std::string &MessageStr::getData() {
    return data;
}

std::string &MessageStr::getName() {
    return name;
}

