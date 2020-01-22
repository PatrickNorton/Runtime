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

    NullType::NullType() = default;

    std::string NullType::str() {
        return "null";
    }

    Variable NullType::callOperator(Operator, std::vector<Variable>) {
        throw std::runtime_error("Cannot call functions on null");
    }

    Type str_t() {
        static const std::unordered_map<Operator, Callable> strOperators {};  // TODO: Implement operators
        static Type instance = std::make_shared<Constants::_Type>(Constants::_Type(strOperators));
        return instance;
    }
}
