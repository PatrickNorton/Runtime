//
// Created by Patrick Norton on 11/1/20.
//

#include "Runtime.h"

#include <utility>


Variable Runtime::load_variable(uint32_t index) const {
    return this->variables[index];
}


void Runtime::store_variable(uint32_t index, Variable variable) {
    if (variables.size() <= index) {
        variables.resize(index + 1);
    }
    variables[index] = std::move(variable);
}

Variable Runtime::pop() {
    auto var = stack.top();
    stack.pop();
    return var;
}

void Runtime::push(const Variable& variable) {
    stack.push((variable));
}

Variable Runtime::load_const(uint32_t index) const {
    return constants[index];
}

Variable Runtime::top() const {
    return stack.top();
}

void Runtime::goTo(uint32_t pos) {
    location = pos;
}

uint32_t Runtime::currentPos() const {
    return location;
}

Runtime::Runtime(const std::vector<Constants::Constant>& constants) {
    this->constants = constants;
    location = 0;
}

void Runtime::advance(uint32_t count) {
    location += count;
}

void Runtime::call(uint16_t argc) {
    auto args = loadArgs(argc);
    auto caller = pop();
    (*caller)(args, this);
}

void Runtime::call(const Variable& self, Operator o, const std::vector<Variable>& args) {
    (*(*self)[{o, this}])(args, this);
}

std::vector<Variable> Runtime::loadArgs(uint16_t argc) {
    std::vector<Variable> args(argc);
    for (uint16_t i = 0; i < argc; i++) {
        args[argc - i - 1] = pop();
    }
    return args;
}

void Runtime::pushStack() {
    returns.push(location);
}
