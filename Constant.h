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
    private:
        void (*function)(const std::vector<Variable>&);
    public:
        explicit Function(void (*caller)(const std::vector<Variable>&));
        std::string str() override;
        Variable callOperator(Operator o, std::vector<Variable> args) override;
    };

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

    typedef std::shared_ptr<_Constant> Constant;

    Constant fromNative(bool val);
    Constant null();
}


#endif //RUNTIME_CONSTANT_H
