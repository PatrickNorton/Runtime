//
// Created by Patrick Norton on 11/1/20.
//

#include <vector>
#include "Variable.h"

std::string _Variable::str() {
    return callOperator(Operator::STR, {})->str();
}

Bigint _Variable::toInt() {
    return callOperator(Operator::INT, {})->toInt();
}

_Variable::operator bool() {
    return bool(*callOperator(Operator::BOOL, {}));
}

uint32_t _Variable::operator()(uint16_t argc, Runtime* runtime) {
    return (*(*this)[{Operator::CALL, runtime}])(argc, runtime);
}

Variable _Variable::operator[](std::pair<uint16_t, Runtime*>) {
    throw std::runtime_error("Not yet implemented");
}

Variable _Variable::operator[](std::pair<Operator, Runtime*>) {
    throw std::runtime_error("Not yet implemented");
}
