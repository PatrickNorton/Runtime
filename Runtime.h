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
    std::stack<uint32_t> returns;
    uint32_t location;
    bool nativeCall;

public:
    explicit Runtime(const std::vector<Constants::Constant>& constants);
    Variable load_variable(uint32_t index) const;
    void store_variable(uint32_t index, Variable variable);
    Variable pop();
    void push(Variable variable);
    Variable load_const(uint32_t index) const;
    Variable top() const;
    void goTo(uint32_t location);
    uint32_t currentPos() const;
    void advance(uint32_t count);
    void call(uint16_t);
    inline void callIsNative();
};


#endif //RUNTIME_RUNTIME_H
