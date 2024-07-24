#include "Fabric.h"
#include "MessageStr.h"

Fabric::Fabric() = default;

Fabric::~Fabric() = default;

std::unique_ptr<IMessage> Fabric::createMessage() {
    return std::make_unique<MessageStr>();
}
