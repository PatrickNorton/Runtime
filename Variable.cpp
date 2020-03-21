//
// Created by Patrick Norton on 11/1/20.
//

#include <vector>
#include "Variable.h"
#include "Runtime.h"
#include "Type.h"

std::string _Variable::str(Runtime* runtime) {
    runtime->call(shared_from_this(), Operator::STR, {});
    return runtime->pop()->str(runtime);
}

Bigint _Variable::toInt(Runtime* runtime) {
    runtime->call(shared_from_this(), Operator::INT, {});
    return runtime->pop()->toInt(runtime);
}

bool _Variable::toBool(Runtime* runtime) {
    runtime->call(shared_from_this(), Operator::BOOL, {});
    return runtime->pop()->toBool(runtime);
}

char16_t _Variable::toChar(Runtime* runtime) {
    runtime->call(shared_from_this(), Operator::STR, {});
    return runtime->pop()->str(runtime).at(0);
}

void _Variable::operator()(const std::vector<Variable>& args, Runtime* runtime) {
    (*(*this)[{Operator::CALL, runtime}])(args, runtime);
}

Variable _Variable::operator[](std::pair<std::string, Runtime*>) {
    throw std::runtime_error("Not yet implemented");
}

Variable _Variable::operator[](std::pair<Operator, Runtime*>) {
    throw std::runtime_error("Not yet implemented");
}

Type _Variable::getType() {
    throw std::runtime_error("Not yet implemented");
}

bool _Variable::isTypeOf(const Variable &) {
    return false;
}

void _Variable::set(const std::string&, const Variable&, Runtime*) {
    throw std::runtime_error("Not yet implemented");
}
