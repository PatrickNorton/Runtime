//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_RUNTIME_H
#define RUNTIME_RUNTIME_H


#include <stack>
#include <vector>
#include "Variable.h"
#include "Constant.h"
#include "StackFrame.h"

class Runtime final {
private:
    std::vector<std::vector<uint8_t>> functions;
    std::vector<Constants::Constant> constants;
    std::stack<Variable> stack;
    std::stack<StackFrame> frames;

public:
    explicit Runtime(const std::vector<Constants::Constant>& constants);
    Runtime(std::vector<Constants::Constant>, std::vector<std::vector<uint8_t>>);
    Variable load_variable(uint32_t index) const;
    void store_variable(uint32_t index, Variable variable);
    Variable pop();
    void push(const Variable& variable);
    Variable load_const(uint32_t index) const;
    Variable top() const;
    void goTo(uint32_t location);
    uint32_t currentPos() const;
    void advance(uint32_t count);
    void call(uint16_t);
    void call(const Variable&, Operator, const std::vector<Variable>&);
    void call(uint16_t, const std::vector<Variable>&);
    void pushStack(uint16_t, uint16_t);
    void popStack();
    std::vector<Variable> loadArgs(uint16_t);
};


#endif //RUNTIME_RUNTIME_H
