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

uint32_t _Variable::operator()(const std::vector<Variable>& args, Runtime* runtime) {
    return (*(*this)[{Operator::CALL, runtime}])(args, runtime);
}

Variable _Variable::operator[](std::pair<uint16_t, Runtime*>) {
    throw std::runtime_error("Not yet implemented");
}

Variable _Variable::operator[](std::pair<Operator, Runtime*>) {
    throw std::runtime_error("Not yet implemented");
}

bool _Variable::instanceOf(const Variable& other) {
    return getType()->isSubclass(other->getType());
}

Type _Variable::getType() {
    throw std::runtime_error("Not yet implemented");
}
