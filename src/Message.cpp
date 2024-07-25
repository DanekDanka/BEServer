
#include "Message.h"

void Message::addError(char *error) {
    errors += error;
    errors += '\n';
}

void Message::addMessage(std::string message) {
}
