//
// Created by Patrick Norton on 11/1/20.
//

#include <vector>
#include "Variable.h"

std::string _Variable::str(Runtime* runtime) {
    return (*this)[{Operator::STR, runtime}]->str(runtime);
}

Bigint _Variable::toInt(Runtime* runtime) {
    return (*this)[{Operator::INT, runtime}]->toInt(runtime);
}

bool _Variable::toBool(Runtime* runtime) {
    return (*this)[{Operator::BOOL, runtime}]->toBool(runtime);
}

uint32_t _Variable::operator()(const std::vector<Variable>& args, Runtime* runtime) {
    return (*(*this)[{Operator::CALL, runtime}])(args, runtime);
}

Variable _Variable::operator[](std::pair<uint16_t, Runtime*>) {
    throw std::runtime_error("Not yet implemented");
}

Variable _Variable::operator[](std::pair<Operator, Runtime*>) {
    throw std::runtime_error("Not yet implemented");
}
