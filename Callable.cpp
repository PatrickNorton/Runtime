//
// Created by Patrick Norton on 15/1/20.
//

#include "Callable.h"

_Callable::_Callable(std::vector<uint8_t>* bytecode) {
    this->bytecode = bytecode;
}

std::vector<uint8_t> *_Callable::getBytecode() {
    return bytecode;
}

Variable _Callable::operator()(std::vector<Variable> args) {
    throw std::runtime_error("Calling not yet implemented");
}
