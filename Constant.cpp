//
// Created by Patrick Norton on 12/1/20.
//

#include <vector>
#include "Constant.h"

Constants::String::String(std::string value) {
    this->value = value;
}

std::string Constants::String::str() {
    return this->value;
}

Variable Constants::String::callOperator(Operator o, std::vector<Variable> args) {
    throw std::runtime_error("Operators on strings not yet implemented");
}
