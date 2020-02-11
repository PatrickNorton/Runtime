//
// Created by Patrick Norton on 26/1/20.
//

#ifndef RUNTIME_STACKFRAME_H
#define RUNTIME_STACKFRAME_H


#include <set>
#include "Variable.h"

class StackFrame {
private:
    std::set<Variable> exceptionHandlers;
    std::vector<Variable> variables;
    uint16_t functionNumber;
    uint32_t location;
    bool native;
public:
    StackFrame(size_t varCount, uint16_t functionNumber);
    StackFrame();

    uint32_t currentPos() const;
    void advance(uint32_t);
    void jump(uint32_t);
    uint16_t getFnNumber() const;
    void loadArgs(const std::vector<Variable>&);
    void resetVars(size_t);
    void store(uint32_t, Variable);
    void addExceptionHandler(Variable);
    void removeExceptionHandler(Variable);
    const std::set<Variable>& getExceptions();
    bool isNative();

    Variable operator[] (size_t index) const;
};


#endif //RUNTIME_STACKFRAME_H
