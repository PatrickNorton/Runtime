//
// Created by Patrick Norton on 16/1/20.
//

#ifndef RUNTIME_INTUTILS_H
#define RUNTIME_INTUTILS_H

#include "Constant.h"

namespace Constants {

    class IntConstant : public _Constant {
    private:
        Bigint value;
    public:
        explicit IntConstant(uint32_t value);
        explicit IntConstant(Bigint value);
        std::string str() override;
        Variable callOperator(Operator o, std::vector<Variable> args) override;
    };

    class BoolConstant : public IntConstant {
    private:
        bool value;
    public:
        explicit BoolConstant(bool value);
        std::string str() override;
        Variable callOperator(Operator o, std::vector<Variable> args) override;
    };


    Constant fromNative(bool val);
    Constant fromNative(const Bigint& val);
}

#endif //RUNTIME_INTUTILS_H
