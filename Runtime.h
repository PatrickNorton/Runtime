//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_RUNTIME_H
#define RUNTIME_RUNTIME_H


#include <stack>
#include <vector>
#include "Variable.h"
#include "Constant.h"

class Runtime final {
private:
    std::vector<Constants::Constant> constants;
    std::vector<Variable> variables;
    std::stack<Variable> stack;
    uint32_t location;
public:
    explicit Runtime(const std::vector<Constants::Constant>& constants);
    Variable load_variable(uint32_t index);
    void store_variable(uint32_t index, Variable variable);
    Variable pop();
    void push(Variable variable);
    Variable load_const(uint32_t index);
    Variable top();
    void goTo(uint32_t location);
    uint32_t currentPos();
    void advance(uint32_t count);
};


#endif //RUNTIME_RUNTIME_H
