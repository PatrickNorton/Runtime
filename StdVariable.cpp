//
// Created by Patrick Norton on 15/1/20.
//

#include "StdVariable.h"

#include <utility>

StdVariable::StdVariable(Type type, std::vector<Variable> args) {
    this->type = std::move(type);
}

Variable StdVariable::callOperator(Operator o, std::vector<Variable> args) {
    return type->callOperator(o, std::make_shared<StdVariable>(*this), args);
}
