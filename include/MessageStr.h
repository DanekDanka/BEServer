#pragma once

#include "IMessage.h"

class MessageStr : public IMessage {
public:
    MessageStr();
    ~MessageStr() override;

    std::string &getName() override;
    std::string &getData() override;

    void setName(std::string &newName) override;
    void setData(std::string &newData) override;

private:
    std::string name;
    std::string data;

};

