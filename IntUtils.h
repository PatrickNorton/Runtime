//
// Created by Patrick Norton on 16/1/20.
//

#ifndef RUNTIME_INTUTILS_H
#define RUNTIME_INTUTILS_H

#include "Constant.h"
#include "BigDecimal.h"
#include "Method.h"

namespace Constants {

    class IntConstant : public _Constant {
    private:
        Bigint value;
        std::map<Operator, std::shared_ptr<Method>> methods;
    public:
        explicit IntConstant(uint32_t value);
        explicit IntConstant(Bigint value);
        std::string str(Runtime *) override;
        Bigint toInt(Runtime *) override;
        bool toBool(Runtime*) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
    };

    class BoolConstant : public IntConstant {
    private:
        bool value;
    public:
        explicit BoolConstant(bool value);
        std::string str(Runtime *) override;
        bool toBool(Runtime*) override;
    };

    class DecimalConstant : public _Constant {
    private:
        BigDecimal value;
    public:
        explicit DecimalConstant(BigDecimal value);
        std::string str(Runtime *) override;
        Bigint toInt(Runtime *) override;
    };


    Constant fromNative(bool val);
    Constant fromNative(const Bigint& val);
    Constant fromNative(const BigDecimal& val);
}

#endif //RUNTIME_INTUTILS_H
