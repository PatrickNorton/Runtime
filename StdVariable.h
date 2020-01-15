//
// Created by Patrick Norton on 15/1/20.
//

#ifndef RUNTIME_STDVARIABLE_H
#define RUNTIME_STDVARIABLE_H


#include "Variable.h"
#include "Type.h"

class StdVariable : public _Variable {
private:
    Type type;
public:
    StdVariable(Type type, std::vector<Variable> args);
    Variable callOperator(Operator o, std::vector<Variable> args) override;
};


#endif //RUNTIME_STDVARIABLE_H
