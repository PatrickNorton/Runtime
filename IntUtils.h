//
// Created by Patrick Norton on 16/1/20.
//

#ifndef RUNTIME_INTUTILS_H
#define RUNTIME_INTUTILS_H

#include "Constant.h"
#include "BigDecimal.h"
#include "Method.h"
#include "Type.h"
#include <map>

namespace Constants {
    class IntConstant;

    typedef std::shared_ptr<IntConstant> IntPtr;

    class IntType : public _Type {
    private:
        static void intStr(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intAdd(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intSub(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intUSub(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intMul(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intFloorDiv(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intMod(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intPow(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intEquals(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intNotEquals(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intGreaterThan(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intLessThan(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intGreaterEqual(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intLessEqual(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intLeftBS(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intRightBS(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intBWAnd(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intBWOr(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intBWXor(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intBWNot(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intToInt(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intToBool(const IntPtr&, const std::vector<Variable>&, Runtime*);
        static void intHash(const IntPtr&, const std::vector<Variable>&, Runtime*);

    public:
        static GenericMethod<Constants::IntConstant> intMethod(Operator);
        Variable createNew(const std::vector<Variable>&, Runtime*) override;

    };

    class BoolType : public _Type {
    public:
        Variable createNew(const std::vector<Variable>&, Runtime*) override;
    };

    class IntConstant : public _Constant {
    private:
        friend class IntType;
        Bigint value;
        std::map<Operator, std::shared_ptr<GenericM<IntConstant>>> methods;
    public:
        explicit IntConstant(uint32_t value);
        explicit IntConstant(Bigint value);
        std::string str(Runtime *) override;
        Bigint toInt(Runtime *) override;
        bool toBool(Runtime*) override;
        char16_t toChar(Runtime*) override;
        Type getType() override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
    };

    class BoolConstant : public IntConstant {
    private:
        bool value;
    public:
        explicit BoolConstant(bool value);
        std::string str(Runtime *) override;
        bool toBool(Runtime*) override;
        Type getType() override;
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
