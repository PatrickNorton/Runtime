//
// Created by Patrick Norton on 16/1/20.
//

#include <unordered_map>
#include <map>
#include "IntUtils.h"
#include "StringUtils.h"


Constants::IntConstant::IntConstant(uint32_t value) {
    this->value = Bigint(static_cast<uint64_t>(value));
}

Constants::IntConstant::IntConstant(Bigint value) {
    this->value = std::move(value);
}

std::string Constants::IntConstant::str() {
    return "";
}

Variable Constants::IntConstant::callOperator(Operator o, std::vector<Variable> args) {
    switch (o) {

        case Operator::STR:
            break;
        case Operator::ADD: {
            Bigint result(this->value);
            for (const auto& arg : args) {  // TODO: Type checking
                result = result + arg->toInt();
            }
            return std::make_shared<IntConstant>(IntConstant(result));
        }
        case Operator::SUBTRACT: {
            Bigint result(this->value);
            for (const auto& arg : args) {  // TODO: Type checking
                result = result - arg->toInt();
            }
            return std::make_shared<IntConstant>(IntConstant(result));
        }
        case Operator::U_SUBTRACT: {
            assert(args.empty());
            return std::make_shared<IntConstant>(IntConstant(-value));
        }
        case Operator::MULTIPLY: {
            Bigint result(this->value);
            for (const auto& arg : args) {  // TODO: Type checking
                result = result * arg->toInt();
            }
            return std::make_shared<IntConstant>(IntConstant(result));
        }
        case Operator::DIVIDE: // TODO: Non-floor division
            break;
        case Operator::FLOOR_DIV: {
            Bigint result(this->value);
            for (const auto& arg : args) {  // TODO: Type checking
                result = result / arg->toInt();
            }
            return std::make_shared<IntConstant>(IntConstant(result));
        }
        case Operator::POWER:
            break;
        case Operator::EQUALS:
            for (const auto& arg : args) {
                if (arg->toInt() != value) {
                    return std::make_shared<BoolConstant>(BoolConstant(false));
                }
            }
            return std::make_shared<BoolConstant>(BoolConstant(true));
        case Operator::NOT_EQUALS:
            for (const auto& arg : args) {
                if (arg->toInt() == value) {
                    return std::make_shared<BoolConstant>(BoolConstant(false));
                }
            }
            return std::make_shared<BoolConstant>(BoolConstant(true));
        case Operator::GREATER_THAN:
            break;
        case Operator::LESS_THAN:
            break;
        case Operator::GREATER_EQUAL:
            break;
        case Operator::LESS_EQUAL:
            break;
        case Operator::LEFT_BITSHIFT: {
            assert(args.size() == 1);
            auto arg = args[0];
            static auto maxBsSize = std::make_shared<IntConstant>(Bigint(std::numeric_limits<size_t>::max()));
            if ((*arg).callOperator(Operator::GREATER_THAN, {maxBsSize})) {
                throw std::runtime_error("Bitshift value greater than max allowed");
            }
            return std::make_shared<IntConstant>(value << static_cast<size_t>(arg->toInt()));
        }
        case Operator::RIGHT_BITSHIFT: {
            assert(args.size() == 1);
            auto arg = args[0];
            static auto maxBsSize = std::make_shared<IntConstant>(Bigint(std::numeric_limits<size_t>::max()));
            if ((*arg).callOperator(Operator::GREATER_THAN, {maxBsSize})) {
                throw std::runtime_error("Bitshift value greater than max allowed");
            }
            return std::make_shared<IntConstant>(value >> static_cast<size_t>(arg->toInt()));
        }
        case Operator::BITWISE_AND: {
            Bigint result(this->value);
            for (const auto& arg : args) {  // TODO: Type checking
                result = result & arg->toInt();
            }
            return std::make_shared<IntConstant>(IntConstant(result));
        }
        case Operator::BITWISE_OR: {
            Bigint result(this->value);
            for (const auto& arg : args) {  // TODO: Type checking
                result = result | arg->toInt();
            }
            return std::make_shared<IntConstant>(IntConstant(result));
        }
        case Operator::BITWISE_XOR: {
            Bigint result(this->value);
            for (const auto& arg : args) {  // TODO: Type checking
                result = result ^ arg->toInt();
            }
            return std::make_shared<IntConstant>(IntConstant(result));
        }
        case Operator::BITWISE_NOT: {
            assert(args.empty());
            return std::make_shared<IntConstant>(IntConstant(~value));
        }
        case Operator::MODULO:
            break;
        case Operator::COMPARE:
            break;
        case Operator::INT:
            return Variable(this);
        case Operator::BOOL:
            return Constants::fromNative(value == 0_B);
        default:
            throw std::runtime_error("Operator should not be called on variable");
    }
    throw std::runtime_error("Operator not yet implemented");
}

Constants::BoolConstant::BoolConstant(bool value) : IntConstant(value ? 1 : 0) {
    this->value = value;
}

Variable Constants::BoolConstant::callOperator(Operator o, std::vector<Variable> args) {
    switch (o) {
        case Operator::STR:
            return std::make_shared<String>(String(value ? "true" : "false"));
        default:
            return IntConstant::callOperator(o, args);
    }
}

std::string Constants::BoolConstant::str() {
    return value ? "true" : "false";
}

Constants::Constant Constants::fromNative(bool val) {
    static Constant t = std::make_shared<BoolConstant>(BoolConstant(true));
    static Constant f = std::make_shared<BoolConstant>(BoolConstant(false));
    return val ? t : f;
}

std::map<Bigint, Constants::Constant> __loadInterned() {
    static const Bigint MAX {0xff};
    std::map<Bigint, Constants::Constant> interns {};
    for (Bigint i = 0_B; i < MAX; ++i) {
        interns[i] = std::make_shared<Constants::IntConstant>(Constants::IntConstant(i));
    }
    return interns;
}

Constants::Constant Constants::fromNative(const Bigint& val) {
    static std::map<Bigint, Constant> interns = __loadInterned();
    if (interns.count(val)) {
        return interns[val];
    } else {
        return std::make_shared<IntConstant>(Constants::IntConstant(val));
    }
}
