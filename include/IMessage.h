#pragma once

#include <string>
#include <fstream>

class IMessage {
public:
    IMessage() = default;
    virtual ~IMessage() = default;

    virtual std::string &getName() = 0;
    virtual std::string &getData() = 0;

    virtual void setName(std::string &newName) = 0;
    virtual void setData(std::string &newData) = 0;
};
