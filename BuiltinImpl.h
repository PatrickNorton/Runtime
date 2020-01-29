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
#include "Type.h"


namespace BuiltinImpl {
    Type str_t();

    class String : public _Variable {
    public:
        explicit String(std::string str);
        std::string str(Runtime *) override;

    private:
        std::string str_;
    };

    class NullType : public Constants::_Constant {
    public:
        explicit NullType();
        std::string str(Runtime *) override;
    };

    void print(const std::vector<Variable>&, Runtime*);
};


#endif //RUNTIME_BUILTINIMPL_H
