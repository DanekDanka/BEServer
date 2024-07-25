#pragma once

#include <string>

class Message {
public:
    Message() = default;
    ~Message() = default;

    void addError(char *error);
    void addMessage(std::string message);

    std::string getMessage();
private:
    std::string message;
    std::string errors;
};

