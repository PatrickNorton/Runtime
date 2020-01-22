//
// Created by Patrick Norton on 11/1/20.
//

#include "Runtime.h"

#include <utility>


Variable Runtime::load_variable(uint32_t index) const {
    return this->variables[index];
}


void Runtime::store_variable(uint32_t index, Variable variable) {
    this->variables[index] = std::move(variable);
}

Variable Runtime::pop() {
    auto var = stack.top();
    stack.pop();
    return var;
}

void Runtime::push(Variable variable) {
    stack.push(std::move(variable));
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
    nativeCall = false;
}

void Runtime::advance(uint32_t count) {
    location += count;
}

void Runtime::call(uint16_t argc) {
    auto caller = pop();
    auto callLoc = (*caller)(argc, this);
    if (nativeCall) {
        assert(callLoc == 0);
        nativeCall = false;
    } else {
        returns.push(location);
        goTo(callLoc);
    }
}

void Runtime::callIsNative() {
    nativeCall = true;
}
