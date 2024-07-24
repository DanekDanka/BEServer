#pragma once

#include <memory>
#include "IMessage.h"

class Fabric {
public:
    Fabric();
    ~Fabric();

    static std::unique_ptr<IMessage> createMessage();

};

