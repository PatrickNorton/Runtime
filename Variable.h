//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_VARIABLE_H
#define RUNTIME_VARIABLE_H


#include <string>
#include "Operator.h"

class _Variable {
public:
    typedef std::shared_ptr<_Variable> Variable;
    virtual std::string str() = 0;
    virtual Variable callOperator(Operator o, std::vector<Variable> args);
};

typedef _Variable::Variable Variable;


#endif //RUNTIME_VARIABLE_H
