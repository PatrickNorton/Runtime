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


Constants::IntConstant::IntConstant(uint32_t value) {
    this->value = Bigint(static_cast<uint64_t>(value));
}

Constants::IntConstant::IntConstant(Bigint value) {
    this->value = std::move(value);
}

std::string Constants::IntConstant::str(Runtime *) {
    return value.to_string();
}

void intStr(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    assert(args.empty());
    runtime->push(Constants::fromNative(self->toInt(runtime).to_string()));
}

void intAdd(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    Bigint result(self->toInt(runtime));
    for (const auto& arg : args) {  // TODO: Type checking
        result = result + arg->toInt(runtime);
    }
    runtime->push(Constants::fromNative(result));
}

void intSub(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    Bigint result(self->toInt(runtime));
    for (const auto& arg : args) {  // TODO: Type checking
        result = result - arg->toInt(runtime);
    }
    runtime->push(Constants::fromNative(result));
}

void intUSub(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    assert(args.empty());
    runtime->push(Constants::fromNative(-self->toInt(runtime)));
}

void intMul(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    Bigint result(self->toInt(runtime));
    for (const auto& arg : args) {  // TODO: Type checking
        result = result * arg->toInt(runtime);
    }
    runtime->push(Constants::fromNative(result));
}

void intFloorDiv(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    Bigint result(self->toInt(runtime));
    for (const auto& arg : args) {  // TODO: Type checking
        result = result / arg->toInt(runtime);
    }
    runtime->push(Constants::fromNative(result));
}

void intMod(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    Bigint result(self->toInt(runtime));
    for (const auto& arg : args) {  // TODO: Type checking
        result = result % arg->toInt(runtime);
    }
    runtime->push(Constants::fromNative(result));
}

void intEquals(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    auto value = self->toInt(runtime);
    for (const auto& arg : args) {
        if (arg->toInt(runtime) != value) {
            runtime->push(Constants::fromNative(false));
            return;
        }
    }
    runtime->push(Constants::fromNative(true));
}

void intNotEquals(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    auto value = self->toInt(runtime);
    for (const auto& arg : args) {
        if (arg->toInt(runtime) == value) {
            runtime->push(Constants::fromNative(false));
            return;
        }
    }
    runtime->push(Constants::fromNative(true));
}

void intGreaterThan(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    auto value = self->toInt(runtime);
    for (const auto& arg : args) {
        if (!(value > arg->toInt(runtime))) {
            runtime->push(Constants::fromNative(false));
            return;
        }
    }
    runtime->push(Constants::fromNative(true));
}

void intLessThan(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    auto value = self->toInt(runtime);
    for (const auto& arg : args) {
        if (!(value < arg->toInt(runtime))) {
            runtime->push(Constants::fromNative(false));
            return;
        }
    }
    runtime->push(Constants::fromNative(true));
}

void intGreaterEqual(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    auto value = self->toInt(runtime);
    for (const auto& arg : args) {
        if (!(value >= arg->toInt(runtime))) {
            runtime->push(Constants::fromNative(false));
            return;
        }
    }
    runtime->push(Constants::fromNative(true));
}

void intLessEqual(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    auto value = self->toInt(runtime);
    for (const auto& arg : args) {
        if (!(value <= arg->toInt(runtime))) {
            runtime->push(Constants::fromNative(false));
            return;
        }
    }
    runtime->push(Constants::fromNative(true));
}

void intLeftBS(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    assert(args.size() == 1);
    auto arg = args[0];
    static auto maxBsSize = Constants::fromNative(Bigint(std::numeric_limits<size_t>::max()));
    runtime->call(arg, Operator::GREATER_THAN, {maxBsSize});
    if (runtime->pop()->toBool(runtime)) {
        throw std::runtime_error("Bitshift value greater than max allowed");
    }
    runtime->push(Constants::fromNative(self->toInt(runtime) << static_cast<size_t>(arg->toInt(runtime))));
}

void intRightBS(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    assert(args.size() == 1);
    auto arg = args[0];
    static auto maxBsSize = Constants::fromNative(Bigint(std::numeric_limits<size_t>::max()));
    runtime->call(arg, Operator::GREATER_THAN, {maxBsSize});
    if (runtime->pop()->toBool(runtime)) {
        throw std::runtime_error("Bitshift value greater than max allowed");
    }
    runtime->push(Constants::fromNative(self->toInt(runtime) >> static_cast<size_t>(arg->toInt(runtime))));
}

void intBWAnd(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    Bigint result(self->toInt(runtime));
    for (const auto& arg : args) {  // TODO: Type checking
        result = result & arg->toInt(runtime);
    }
    runtime->push(Constants::fromNative(result));
}

void intBWOr(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    Bigint result(self->toInt(runtime));
    for (const auto& arg : args) {  // TODO: Type checking
        result = result | arg->toInt(runtime);
    }
    runtime->push(Constants::fromNative(result));
}

void intBWXor(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    Bigint result(self->toInt(runtime));
    for (const auto& arg : args) {  // TODO: Type checking
        result = result ^ arg->toInt(runtime);
    }
    runtime->push(Constants::fromNative(result));
}

void intBWNot(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    assert(args.empty());
    runtime->push(Constants::fromNative(~self->toInt(runtime)));
}

void intToInt(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    assert(args.empty());
    runtime->push(self);
}

void intToBool(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    assert(args.empty());
    runtime->push(Constants::fromNative(self->toInt(runtime) != 0_B));
}

const std::unordered_map<Operator, Constants::NativeMethod>& intMethods() {
    static const std::unordered_map<Operator, Constants::NativeMethod> instance = {
            {Operator::STR, intStr},
            {Operator::ADD, intAdd},
            {Operator::SUBTRACT, intSub},
            {Operator::U_SUBTRACT, intUSub},
            {Operator::MULTIPLY, intMul},
            {Operator::FLOOR_DIV, intFloorDiv},
            {Operator::MODULO, intMod},
            {Operator::EQUALS, intEquals},
            {Operator::NOT_EQUALS, intNotEquals},
            {Operator::GREATER_THAN, intGreaterThan},
            {Operator::LESS_THAN, intLessThan},
            {Operator::GREATER_EQUAL, intGreaterEqual},
            {Operator::LESS_EQUAL, intLessEqual},
            {Operator::LEFT_BITSHIFT, intLeftBS},
            {Operator::RIGHT_BITSHIFT, intRightBS},
            {Operator::BITWISE_AND, intBWAnd},
            {Operator::BITWISE_OR, intBWOr},
            {Operator::BITWISE_XOR, intBWXor},
            {Operator::BITWISE_NOT, intBWNot},
            {Operator::INT, intToInt},
            {Operator::BOOL, intToBool},
    };
    return instance;
}

Bigint Constants::IntConstant::toInt(Runtime *) {
    return value;
}

bool Constants::IntConstant::toBool(Runtime *) {
    return value != 0_B;
}

Variable Constants::IntConstant::operator[] (std::pair<Operator, Runtime*> pair) {
    Operator op = pair.first;
    if (!methods.count(op)) {
        methods[op] = std::make_shared<Method>(shared_from_this(), intMethods().at(op));
    }
    return methods.at(op);
}

Constants::BoolConstant::BoolConstant(bool value) : IntConstant(value ? 1 : 0) {
    this->value = value;
}

std::string Constants::BoolConstant::str(Runtime *) {
    return value ? "true" : "false";
}

bool Constants::BoolConstant::toBool(Runtime *) {
    return value;
}

Constants::Constant Constants::fromNative(bool val) {
    static Constant t = std::make_shared<BoolConstant>(true);
    static Constant f = std::make_shared<BoolConstant>(false);
    return val ? t : f;
}

std::map<Bigint, Constants::Constant> __loadInterned() {
    static const Bigint MAX = 0xFF_B;
    std::map<Bigint, Constants::Constant> interns {};
    for (Bigint i = 0_B; i < MAX; ++i) {
        interns[i] = std::make_shared<Constants::IntConstant>(i);
    }
    return interns;
}

Constants::Constant Constants::fromNative(const Bigint& val) {
    static std::map<Bigint, Constant> interns = __loadInterned();
    if (interns.count(val)) {
        return interns[val];
    } else {
        return std::make_shared<IntConstant>(val);
    }
}

Constants::Constant Constants::fromNative(const BigDecimal &val) {
    return std::make_shared<DecimalConstant>(DecimalConstant(val));
}

Constants::DecimalConstant::DecimalConstant(BigDecimal value) : value(std::move(value)) {}

std::string Constants::DecimalConstant::str(Runtime *) {
    return value.toString();
}

Bigint Constants::DecimalConstant::toInt(Runtime *) {
    return value.round();
}
