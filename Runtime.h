//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_RUNTIME_H
#define RUNTIME_RUNTIME_H


#include <stack>
#include <vector>
#include "Variable.h"

class Runtime {
private:
    std::vector<Variable> variables;
    std::stack<Variable> stack;
public:
    Variable load_variable(uint32_t index);
    void store_variable(uint32_t index, Variable variable);
    Variable pop();
};


#endif //RUNTIME_RUNTIME_H
