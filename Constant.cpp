//
// Created by Patrick Norton on 12/1/20.
//

#include <utility>
#include <vector>
#include "Constant.h"
#include "Builtins.h"
#include "BuiltinImpl.h"

std::string Constants::Function::str() {
    return std::string();
}

Constants::Function::Function(void (*caller)(const std::vector<Variable>&)) {
    function = caller;
}

Variable Constants::Function::callOperator(Operator o, std::vector<Variable> args) {
    if (o == Operator::CALL) {
        function(args);
        return Builtins::null;
    } else {
        throw std::runtime_error("Operator not yet implemented");
    }
}

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
        case Operator::BOOL_AND:
            break;
        case Operator::BOOL_OR:
            break;
        case Operator::BOOL_NOT:
            break;
        case Operator::BOOL_XOR:
            break;
        case Operator::COMPARE:
            break;
        case Operator::INT:
            return Variable(this);
        case Operator::BOOL:
            return Constants::fromNative(value == Bigint(0));
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

Constants::Constant Constants::null() {
    static Constant instance = std::make_shared<BuiltinImpl::NullType>(BuiltinImpl::NullType());
    return instance;
}
