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

    class NullType : public Constants::_Constant {
    public:
        std::string str(Runtime *) override;
    };

    class StopIteration : public Constants::_Type {
    private:
        static void create(const std::vector<Variable>&, Runtime*);
    public:
        Variable operator[](std::pair<Operator, Runtime*> pair) override;
        Variable createNew(const std::vector<Variable>&, Runtime*) override;
    };

    class ValueError : public Constants::_Type {
    private:
        static void create(const std::vector<Variable>&, Runtime*);
    public:
        Variable operator[](std::pair<Operator, Runtime*> pair) override;
        Variable createNew(const std::vector<Variable>&, Runtime*) override;
    };

    void print(const std::vector<Variable>&, Runtime*);
    void input(const std::vector<Variable>&, Runtime*);
    void iter(const std::vector<Variable>&, Runtime*);
};


#endif //RUNTIME_BUILTINIMPL_H
