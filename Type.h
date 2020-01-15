//
// Created by Patrick Norton on 15/1/20.
//

#ifndef RUNTIME_TYPE_H
#define RUNTIME_TYPE_H


#include <memory>
#include <unordered_map>
#include "Operator.h"
#include "Callable.h"

class _Type : public _Variable {
private:
    typedef std::shared_ptr<_Type> Type;
    std::unordered_map<Operator, Callable> operators;
public:
    explicit _Type(std::unordered_map<Operator, Callable> operators);
    Variable callOperator(Operator o, std::vector<Variable> args) override;
    Variable callOperator(Operator o, Variable self, std::vector<Variable> args);
};

typedef std::shared_ptr<_Type> Type;

#endif //RUNTIME_TYPE_H
