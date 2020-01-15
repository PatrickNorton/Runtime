//
// Created by Patrick Norton on 15/1/20.
//

#ifndef RUNTIME_CALLABLE_H
#define RUNTIME_CALLABLE_H


#include "Variable.h"

class _Callable : public _Variable {
private:
    std::vector<uint8_t>* bytecode;
public:
    explicit _Callable(std::vector<uint8_t>* bytecode);
    std::vector<uint8_t>* getBytecode();
    Variable operator() (std::vector<Variable> args);
};

typedef std::shared_ptr<_Callable> Callable;


#endif //RUNTIME_CALLABLE_H
