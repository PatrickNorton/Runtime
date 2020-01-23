//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_VARIABLE_H
#define RUNTIME_VARIABLE_H


#include <string>
#include "Operator.h"
#include "Bigint.h"

class Runtime;  // Forward declaration to make everything work out

class _Variable : public std::enable_shared_from_this<_Variable> {
public:
    typedef std::shared_ptr<_Variable> Variable;
    virtual std::string str();
    virtual Bigint toInt();
    virtual Variable callOperator(Operator o, std::vector<Variable> args) = 0;
    virtual explicit operator bool();
    virtual uint32_t operator() (const std::vector<Variable>&, Runtime*);
    virtual Variable operator[] (std::pair<uint16_t, Runtime*>);
    virtual Variable operator[] (std::pair<Operator, Runtime*>);
};


typedef _Variable::Variable Variable;


#endif //RUNTIME_VARIABLE_H
