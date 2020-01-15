//
// Created by Patrick Norton on 15/1/20.
//

#include "Type.h"

#include <utility>

_Type::_Type(std::unordered_map<Operator, Callable> operators) {
    this->operators = std::move(operators);
}

Variable _Type::callOperator(Operator o, std::vector<Variable> args) {
    return (*(operators)[o])(args);
}

Variable _Type::callOperator(Operator o, Variable self, std::vector<Variable> args) {
    throw std::runtime_error("Calling not yet implemented");
}
