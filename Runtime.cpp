//
// Created by Patrick Norton on 11/1/20.
//

#include "Runtime.h"


Variable Runtime::load_variable(uint32_t index) {
    return this->variables[index];
}


void Runtime::store_variable(uint32_t index, Variable variable) {
    this->variables[index] = variable;
}

Variable Runtime::pop() {
    auto var = stack.top();
    stack.pop();
    return var;
}

void Runtime::push(Variable variable) {
    stack.push(variable);
}

Variable Runtime::load_const(uint32_t index) {
    return constants[index];
}

Variable Runtime::top() {
    return stack.top();
}

void Runtime::goTo(uint32_t location) {
    throw std::runtime_error("Goto not allowed yet");
}

uint32_t Runtime::currentPos() {
    return location;
}

Runtime::Runtime(const std::vector<Constants::Constant>& constants) {
    this->constants = constants;
    location = 0;
}

void Runtime::advance(uint32_t count) {
    location += count;
}
