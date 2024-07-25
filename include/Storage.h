#pragma once

#include <string>
#include <map>

class Storage {
public:
    Storage() = default;
    ~Storage() = default;

//    void addError(char *error);

    void setData(char * buff);
    void setData(const std::string& name, const std::string& data);

    std::string getDataByName(const std::string& name);

private:
    std::map<std::string, std::string> messages;
//    std::map<std::string, std::string> errors;
};


