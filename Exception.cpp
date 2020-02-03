//
// Created by Patrick Norton on 31/1/20.
//

#include "Exception.h"

#include <utility>

Constants::Exception::Exception(std::string msg, Type type) {
    this->message = std::move(msg);
    this->type = std::move(type);
}

std::string Constants::Exception::getMessage() {
    return message;
}

Type Constants::Exception::getType() {
    return type;
}
