//
// Created by Patrick Norton on 31/1/20.
//

#include "Exception.h"

#include <utility>

Constants::Exception::Exception(std::string msg) {
    this->message = std::move(msg);
}

std::string Constants::Exception::getMessage() {
    return message;
}
