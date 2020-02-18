//
// Created by Patrick Norton on 11/1/20.
//

#include "Runtime.h"
#include "BaseFunction.h"
#include "Executor.h"
#include "Type.h"
#include "Exception.h"
#include "Exit.h"
#include "IntTools.h"

#include <utility>
#include <iostream>


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
    stack.push(variable);
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

Runtime::Runtime(std::vector<Constants::Constant> constants, std::vector<BaseFunction> functions)
        : constants(std::move(constants)), functions(std::move(functions)) {
    frames.push(StackFrame(this->functions[0].getLocalCount(), 0));
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

void Runtime::call(const Variable& self, const std::string& name, const std::vector<Variable>& args) {
    (*(*self)[{name, this}])(args, this);
}

std::vector<Variable> Runtime::loadArgs(uint16_t argc) {
    std::vector<Variable> args(argc);
    for (uint16_t i = 0; i < argc; i++) {
        args[argc - i - 1] = pop();
    }
    return args;
}

void Runtime::pushStack(uint16_t varCount, uint16_t functionNumber) {
    if (isNative()) {
        frames.push({varCount, functionNumber});
        Executor::execute(*this);
        assert(isNative());
    } else {
        frames.push({varCount, functionNumber});
    }
}

void Runtime::popStack() {
    for (const auto& v : frames.top().getExceptions()) {
        assert(&exceptionFrames[v].top().second == &frames.top());
        exceptionFrames[v].pop();
        exceptionStack.pop();
    }
    frames.pop();
}

void Runtime::call(uint16_t functionNo, const std::vector<Variable>& args) {
    pushStack(0, functionNo);
    frames.top().loadArgs(args);
}

void Runtime::removeExceptionHandler(const Variable& exceptionType) {
    exceptionFrames[exceptionType].pop();
    frames.top().removeExceptionHandler(exceptionType);
}

void Runtime::addExceptionHandler(const Variable& exceptionType, uint32_t jumpPos) {
    exceptionFrames[exceptionType].push({jumpPos, frames.top()});
    frames.top().addExceptionHandler(exceptionType);
    exceptionStack.push(exceptionType);
}

void Runtime::throwExc(const Variable& exception) {
    throwQuick(exception->getType(), std::dynamic_pointer_cast<Constants::Exception>(exception)->getMessage());
}

void Runtime::throwQuick(const Type& exception, const std::string& message) {
    assert(exception != nullptr);
    // TODO: Finally blocks
    const auto& frame = exceptionFrames[exception];
    if (frame.empty()) {
        std::cerr << message;
        // TODO: Get stack unwinding
        throw Exit();
    }
    if (isNative()) {
        while (isNative()) popStack();
        throw NativeExc(exception, message);
    }
    const auto& framePair = frame.top();
    while (&frames.top() != &framePair.second) {
        if (isNative()) {
            throw ThrownExc(exception, message);
        }
        popStack();
    }
    goTo(framePair.first);
}

const std::vector<uint8_t>& Runtime::currentFn() {
    return functions[frames.top().getFnNumber()].getBytes();
}

void Runtime::pushNativeFrame() {
    frames.push({});
}

bool Runtime::isNative() const {
    return frames.top().isNative();
}

std::string Runtime::fnName(uint32_t i) {
    return functions[i].getName();
}

void Runtime::popHandler() {
    removeExceptionHandler(exceptionStack.top());
    exceptionStack.pop();
}

ObjectIterator Runtime::iterTop() {
    return {pop(), this};
}

ObjectIterator Runtime::iter(Variable var) {
    return {std::move(var), this};
}
