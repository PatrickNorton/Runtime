//
// Created by Patrick Norton on 12/1/20.
//

#include "BuiltinImpl.h"
#include "StringUtils.h"


namespace BuiltinImpl {
    String::String(std::string str) {
        str_ = std::move(str);
    }

    std::string String::str() {
        return str_;
    }

    Variable String::callOperator(Operator o, std::vector<Variable> args) {
        throw std::runtime_error("Operator calling not yet implemented for str");
    }

    std::string str_t::str() {
        return "str";
    }

    Variable str_t::callOperator(Operator o, std::vector<Variable> args) {
        switch (o) {
            case Operator::CALL:
                return args[0]->callOperator(Operator::STR, {});
            case Operator::STR:
                return Constants::fromNative("str", true);
            default:
                throw std::runtime_error("Operator not implemented");
        }
    }

    NullType::NullType() = default;

    std::string NullType::str() {
        return "null";
    }

    Variable NullType::callOperator(Operator, std::vector<Variable>) {
        throw std::runtime_error("Cannot call functions on null");
    }
}
