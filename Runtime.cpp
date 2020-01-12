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
