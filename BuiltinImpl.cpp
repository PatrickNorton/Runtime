//
// Created by Patrick Norton on 12/1/20.
//

#include "BuiltinImpl.h"


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
                return std::make_shared<String>(String("str"));
        }
    }
}
