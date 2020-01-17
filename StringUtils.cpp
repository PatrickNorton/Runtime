//
// Created by Patrick Norton on 16/1/20.
//

#include "StringUtils.h"

#include <unordered_set>
#include <unordered_map>

#include "IntUtils.h"

Constants::String::String(std::string value) {
    this->value = std::move(value);
}

std::string Constants::String::str() {
    return this->value;
}

Variable Constants::String::callOperator(Operator o, std::vector<Variable> args) {
    switch (o) {

        case Operator::ADD: {
            std::string result = value;
            for (const auto &arg : args) {
                result += arg->str();
            }
            return Constants::fromNative(result);
        }
        case Operator::SUBTRACT:
            break;
        case Operator::U_SUBTRACT:
            break;
        case Operator::MULTIPLY: {
            assert(args.size() == 1);
            auto arg = args[0]->toInt();
            auto resultSize = arg * Bigint(value.size());
            if (resultSize > Bigint(std::numeric_limits<size_t>::max())) {
                throw std::runtime_error("Resulting string too big");
            }
            std::vector<char> result {};
            for (size_t i = 0; i < static_cast<size_t>(resultSize); i++) {
                result.insert(result.end(), value.begin(), value.end());
            }
            return Constants::fromNative(std::string(result.begin(), result.end()));
        }
        case Operator::DIVIDE:
            break;
        case Operator::FLOOR_DIV:
            break;
        case Operator::POWER:
            break;
        case Operator::EQUALS:
            break;
        case Operator::NOT_EQUALS:
            break;
        case Operator::GREATER_THAN:
            break;
        case Operator::LESS_THAN:
            break;
        case Operator::GREATER_EQUAL:
            break;
        case Operator::LESS_EQUAL:
            break;
        case Operator::LEFT_BITSHIFT:
            break;
        case Operator::RIGHT_BITSHIFT:
            break;
        case Operator::BITWISE_AND:
            break;
        case Operator::BITWISE_OR:
            break;
        case Operator::BITWISE_XOR:
            break;
        case Operator::BITWISE_NOT:
            break;
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
        case Operator::IN:
            break;
        case Operator::NOT_IN:
            break;
        case Operator::CASTED:
            break;
        case Operator::IS:
            break;
        case Operator::IS_NOT:
            break;
        case Operator::NULL_COERCE:
            break;
        case Operator::NOT_NULL:
            break;
        case Operator::OPTIONAL:
            break;
        case Operator::INSTANCEOF:
            break;
        case Operator::NOT_INSTANCEOF:
            break;
        case Operator::COMPARE:
            break;
        case Operator::CALL:
            break;
        case Operator::STR: {
            return shared_from_this();
        }
        case Operator::INT:
            break;
        case Operator::BOOL: {
            return Constants::fromNative(!value.empty());
        }
    }
    throw std::runtime_error("Operator not yet implemented");
}

Constants::Constant Constants::fromNative(const std::string& val) {
    return fromNative(val, false);
}

Constants::Constant Constants::fromNative(const std::string& val, bool intern) {
    static std::unordered_map<std::string, Constant> interns{};
    if (interns.count(val)) {
        return interns[val];
    } else {
        if (intern) {
            interns[val] = std::make_shared<String>(String(val));
            return interns[val];
        } else {
            return std::make_shared<String>(String(val));
        }
    }
}
