//
// Created by Patrick Norton on 16/1/20.
//

#include <unordered_map>
#include <map>
#include <utility>
#include "IntUtils.h"
#include "StringUtils.h"
#include "Runtime.h"
#include "Method.h"
#include "Builtins.h"


namespace Constants {
    IntConstant::IntConstant(uint32_t value) {
        this->value = Bigint(static_cast<uint64_t>(value));
    }

    IntConstant::IntConstant(Bigint value) {
        this->value = std::move(value);
    }

    std::string IntConstant::str(Runtime* ) {
        return value.to_string();
    }

    void IntType::intStr(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        runtime->push(fromNative(self->value.to_string()));
    }

    void IntType::intAdd(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        Bigint result(self->value);
        for (const auto& arg : args) {  // TODO: Type checking
            result = result + arg->toInt(runtime);
        }
        runtime->push(fromNative(result));
    }

    void IntType::intSub(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        Bigint result(self->value);
        for (const auto& arg : args) {  // TODO: Type checking
            result = result - arg->toInt(runtime);
        }
        runtime->push(fromNative(result));
    }

    void IntType::intUSub(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        runtime->push(fromNative(-self->value));
    }

    void IntType::intMul(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        Bigint result(self->value);
        for (const auto& arg : args) {  // TODO: Type checking
            result = result * arg->toInt(runtime);
        }
        runtime->push(fromNative(result));
    }

    void IntType::intFloorDiv(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        Bigint result(self->value);
        for (const auto& arg : args) {  // TODO: Type checking
            result = result / arg->toInt(runtime);
        }
        runtime->push(fromNative(result));
    }

    void IntType::intMod(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        Bigint result(self->value);
        for (const auto& arg : args) {  // TODO: Type checking
            result = result % arg->toInt(runtime);
        }
        runtime->push(fromNative(result));
    }

    void IntType::intEquals(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        auto value = self->value;
        for (const auto& arg : args) {
            if (arg->toInt(runtime) != value) {
                runtime->push(fromNative(false));
                return;
            }
        }
        runtime->push(fromNative(true));
    }

    void IntType::intNotEquals(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        auto value = self->value;
        for (const auto& arg : args) {
            if (arg->toInt(runtime) == value) {
                runtime->push(fromNative(false));
                return;
            }
        }
        runtime->push(fromNative(true));
    }

    void IntType::intGreaterThan(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        auto value = self->value;
        for (const auto& arg : args) {
            if (!(value > arg->toInt(runtime))) {
                runtime->push(fromNative(false));
                return;
            }
        }
        runtime->push(fromNative(true));
    }

    void IntType::intLessThan(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        auto value = self->value;
        for (const auto& arg : args) {
            if (!(value < arg->toInt(runtime))) {
                runtime->push(fromNative(false));
                return;
            }
        }
        runtime->push(fromNative(true));
    }

    void IntType::intGreaterEqual(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        auto value = self->value;
        for (const auto& arg : args) {
            if (!(value >= arg->toInt(runtime))) {
                runtime->push(fromNative(false));
                return;
            }
        }
        runtime->push(fromNative(true));
    }

    void IntType::intLessEqual(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        auto value = self->value;
        for (const auto& arg : args) {
            if (!(value <= arg->toInt(runtime))) {
                runtime->push(fromNative(false));
                return;
            }
        }
        runtime->push(fromNative(true));
    }

    void IntType::intLeftBS(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1);
        auto arg = args[0];
        static auto maxBsSize = fromNative(Bigint(std::numeric_limits<size_t>::max()));
        runtime->call(arg, Operator::GREATER_THAN, {maxBsSize});
        if (runtime->pop()->toBool(runtime)) {
            throw std::runtime_error("Bitshift value greater than max allowed");
        }
        runtime->push(fromNative(self->value << static_cast<size_t>(arg->toInt(runtime))));
    }

    void IntType::intRightBS(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1);
        auto arg = args[0];
        static auto maxBsSize = fromNative(Bigint(std::numeric_limits<size_t>::max()));
        runtime->call(arg, Operator::GREATER_THAN, {maxBsSize});
        if (runtime->pop()->toBool(runtime)) {
            throw std::runtime_error("Bitshift value greater than max allowed");
        }
        runtime->push(fromNative(self->value >> static_cast<size_t>(arg->toInt(runtime))));
    }

    void IntType::intBWAnd(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        Bigint result(self->value);
        for (const auto& arg : args) {  // TODO: Type checking
            result = result & arg->toInt(runtime);
        }
        runtime->push(fromNative(result));
    }

    void IntType::intBWOr(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        Bigint result(self->value);
        for (const auto& arg : args) {  // TODO: Type checking
            result = result | arg->toInt(runtime);
        }
        runtime->push(fromNative(result));
    }

    void IntType::intBWXor(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        Bigint result(self->value);
        for (const auto& arg : args) {  // TODO: Type checking
            result = result ^ arg->toInt(runtime);
        }
        runtime->push(fromNative(result));
    }

    void IntType::intBWNot(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        runtime->push(fromNative(~self->value));
    }

    void IntType::intToInt(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        runtime->push(self);
    }

    void IntType::intToBool(const IntPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        runtime->push(fromNative(self->value != 0_B));
    }

    GenericMethod<IntConstant> IntType::intMethod(Operator op) {
        static const std::unordered_map<Operator, GenericMethod<IntConstant>> instance = {
                {Operator::STR,            intStr},
                {Operator::ADD,            intAdd},
                {Operator::SUBTRACT,       intSub},
                {Operator::U_SUBTRACT,     intUSub},
                {Operator::MULTIPLY,       intMul},
                {Operator::FLOOR_DIV,      intFloorDiv},
                {Operator::MODULO,         intMod},
                {Operator::EQUALS,         intEquals},
                {Operator::NOT_EQUALS,     intNotEquals},
                {Operator::GREATER_THAN,   intGreaterThan},
                {Operator::LESS_THAN,      intLessThan},
                {Operator::GREATER_EQUAL,  intGreaterEqual},
                {Operator::LESS_EQUAL,     intLessEqual},
                {Operator::LEFT_BITSHIFT,  intLeftBS},
                {Operator::RIGHT_BITSHIFT, intRightBS},
                {Operator::BITWISE_AND,    intBWAnd},
                {Operator::BITWISE_OR,     intBWOr},
                {Operator::BITWISE_XOR,    intBWXor},
                {Operator::BITWISE_NOT,    intBWNot},
                {Operator::INT,            intToInt},
                {Operator::BOOL,           intToBool},
        };
        return instance.at(op);
    }

    IntType::IntType() : _Type({}, {}) {
    }

    Variable IntType::createNew(const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1);
        return std::make_shared<IntConstant>(args[0]->toInt(runtime));
    }

    Bigint IntConstant::toInt(Runtime*) {
        return value;
    }

    bool IntConstant::toBool(Runtime*) {
        return value != 0_B;
    }

    Variable IntConstant::operator[](std::pair<Operator, Runtime*> pair) {
        Operator op = pair.first;
        if (!methods.count(op)) {
            auto self = this_ptr<IntConstant>();
            methods[op] = std::make_shared<GenericM<IntConstant>>(std::move(self), IntType::intMethod(op));
        }
        return methods.at(op);
    }

    Type IntConstant::getType() {
        return Builtins::int_();
    }

    BoolConstant::BoolConstant(bool value) : IntConstant(value ? 1 : 0) {
        this->value = value;
    }

    std::string BoolConstant::str(Runtime*) {
        return value ? "true" : "false";
    }

    bool BoolConstant::toBool(Runtime*) {
        return value;
    }

    Type BoolConstant::getType() {
        return Builtins::bool_();
    }

    Constant fromNative(bool val) {
        static Constant t = std::make_shared<BoolConstant>(true);
        static Constant f = std::make_shared<BoolConstant>(false);
        return val ? t : f;
    }

    std::map<Bigint, Constant> __loadInterned() {
        static const Bigint MAX = 0xFF_B;
        std::map<Bigint, Constant> interns{};
        for (Bigint i = 0_B; i < MAX; ++i) {
            interns[i] = std::make_shared<IntConstant>(i);
        }
        return interns;
    }

    Constant fromNative(const Bigint &val) {
        static std::map<Bigint, Constant> interns = __loadInterned();
        if (interns.count(val)) {
            return interns[val];
        } else {
            return std::make_shared<IntConstant>(val);
        }
    }

    Constant fromNative(const BigDecimal &val) {
        return std::make_shared<DecimalConstant>(val);
    }

    DecimalConstant::DecimalConstant(BigDecimal value) : value(std::move(value)) {}

    std::string DecimalConstant::str(Runtime*) {
        return value.toString();
    }

    Bigint DecimalConstant::toInt(Runtime*) {
        return value.round();
    }

    BoolType::BoolType() : Constants::_Type({}) {
    }

    Variable BoolType::createNew(const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1);
        return Constants::fromNative(args[0]->toBool(runtime));
    }
}
