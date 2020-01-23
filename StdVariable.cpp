//
// Created by Patrick Norton on 15/1/20.
//

#include "StdVariable.h"

#include <utility>

StdVariable::StdVariable(Type type, std::vector<Variable> args) {
    this->type = std::move(type);
}
