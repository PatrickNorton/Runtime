//
// Created by Patrick Norton on 12/1/20.
//

#include "BuiltinImpl.h"
#include "StringUtils.h"


namespace BuiltinImpl {
    String::String(std::string str) {
        str_ = std::move(str);
    }

    std::string String::str(Runtime *) {
        return str_;
    }

    NullType::NullType() = default;

    std::string NullType::str(Runtime *) {
        return "null";
    }

    Type str_t() {
        static const std::unordered_map<Operator, Callable> strOperators {};  // TODO: Implement operators
        static Type instance = std::make_shared<Constants::_Type>(Constants::_Type(strOperators));
        return instance;
    }
}
