#include "Client.h"
#include "Fabric.h"

#include "MessageStr.h"

Client::Client(int port, char * ip) {
    message = Fabric::createMessage();
    sender.init(port, ip);
}

Client::~Client() = default;

void Client::setMessage(std::string &name, std::string &data) {
    message->setName(name);
    message->setData(data);
}

void Client::sendMessage() {
    sender.send((message->getName() + message->getData()).data());
}
