//
// Created by Patrick Norton on 11/1/20.
//

#include "Runtime.h"

#include <utility>


Variable Runtime::load_variable(uint32_t index) const {
    return frames.top()[index];
}


void Runtime::store_variable(uint32_t index, Variable variable) {
    frames.top().store(index, std::move(variable));
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
    frames.top().jump(pos);
}

uint32_t Runtime::currentPos() const {
    return frames.top().currentPos();
}

Runtime::Runtime(const std::vector<Constants::Constant>& constants) {
    this->constants = constants;
    frames = {};
}

void Runtime::advance(uint32_t count) {
    frames.top().advance(count);
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

void Runtime::pushStack(uint16_t varCount, uint16_t functionNumber) {
    frames.push({varCount, functionNumber});
}

void Runtime::popStack() {
    frames.pop();
}

Runtime::Runtime(std::vector<Constants::Constant> constants, std::vector<std::vector<uint8_t>> functions)
    : constants(std::move(constants)), functions(std::move(functions)) {
}

void Runtime::call(uint16_t functionNo, const std::vector<Variable>& args) {
    pushStack(0, functionNo);
    frames.top().loadArgs(args);
    popStack();
}
