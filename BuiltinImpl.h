//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_BUILTINIMPL_H
#define RUNTIME_BUILTINIMPL_H


#include <utility>
#include <vector>
#include <iostream>
#include "Builtins.h"
#include "Operator.h"


namespace BuiltinImpl {
    class str_t : public _Variable {
    public:
        std::string str() override;
        Variable callOperator(Operator o, std::vector<Variable> args) override;
    };

    class String : public _Variable {
    public:
        explicit String(std::string str);
        std::string str() override;
        Variable callOperator(Operator o, std::vector<Variable> args) override;

    private:
        std::string str_;
    };
};


#endif //RUNTIME_BUILTINIMPL_H
