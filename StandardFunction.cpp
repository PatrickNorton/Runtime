//
// Created by Patrick Norton on 22/1/20.
//

#include "StandardFunction.h"

Constants::StandardFunction::StandardFunction(uint32_t location) {
    this->location = location;
}

Variable Constants::StandardFunction::callOperator(Operator o, std::vector<Variable>) {
    if (o == Operator::CALL) {
        throw std::runtime_error("Calling not yet implemented");
    } else {
        throw std::runtime_error("Should not have gotten here");
    }
}

Constants::StandardFunction::operator bool() {
    return true;
}
