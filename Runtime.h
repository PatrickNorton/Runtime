//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_RUNTIME_H
#define RUNTIME_RUNTIME_H


#include <stack>
#include <vector>
#include <map>
#include "Variable.h"
#include "Constant.h"
#include "StackFrame.h"
#include "BaseFunction.h"

class Runtime final {
private:
    std::vector<BaseFunction> functions;
    std::vector<Constants::Constant> constants;
    std::stack<Variable> stack;
    std::stack<StackFrame> frames;
    std::map<Variable, std::stack<std::tuple<uint32_t, uint32_t, uint32_t>>> exceptions;
    std::map<Variable, std::stack<std::pair<uint32_t, StackFrame&>>> exceptionFrames;

public:
    Runtime(std::vector<Constants::Constant>, std::vector<BaseFunction>);
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

    void addExceptionHandler(const Variable&, uint32_t);
    void removeExceptionHandler(const Variable&);
    void throwExc(const Variable&);

    void call(const Variable& self, const std::string& name, const std::vector<Variable>& args);
};


#endif //RUNTIME_RUNTIME_H
