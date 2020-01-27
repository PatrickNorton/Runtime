//
// Created by Patrick Norton on 22/1/20.
//

#include "Function.h"
#include <exception>

Constants::StdFunction::StdFunction(uint32_t index) {
    this->index = index;
}

void Constants::StdFunction::operator()(const std::vector<Variable>& args, Runtime* runtime) {
    runtime->call(index, args);
}

Variable Constants::StdFunction::operator[](std::pair<uint16_t, Runtime*>) {
    throw std::runtime_error("Value not supported");
}

Variable Constants::StdFunction::operator[](std::pair<Operator, Runtime*> pair) {
    Operator op = pair.first;
    if (op == Operator::CALL) {
        return shared_from_this();
    } else {
        throw std::runtime_error("Operator not supported");
    }
}
