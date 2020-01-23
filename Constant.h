//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_CONSTANT_H
#define RUNTIME_CONSTANT_H


#include "Variable.h"
#include "Bigint.h"

namespace Constants {
    class _Constant : public _Variable {
    };

class Function : public _Constant {
    public:
        typedef void (*Callable)(const std::vector<Variable>&, Runtime*);
    private:
        Callable function;
    public:
        explicit Function(Callable caller);
        std::string str(Runtime *) override;
        Variable callOperator(Operator o, std::vector<Variable> args) override;
        uint32_t operator() (const std::vector<Variable>& , Runtime*) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
    };

    typedef std::shared_ptr<_Constant> Constant;
    Constant null();
}


#endif //RUNTIME_CONSTANT_H
