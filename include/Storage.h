#pragma once

#include <string>
#include <map>
#include <vector>

class Storage {
public:
    Storage();

    ~Storage() = default;

    void setData(char *buff);

    void setData(const std::string &name, const std::string &data);

    std::string getDataByName(const std::string &name);

private:
    std::stringstream buff;
    std::map<std::string, std::string> messages;
    std::string errors;
};


