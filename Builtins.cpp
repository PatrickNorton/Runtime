//
// Created by Patrick Norton on 11/1/20.
//

#include <vector>
#include <iostream>
#include "Builtins.h"
#include "BuiltinImpl.h"
#include "IntUtils.h"


namespace Builtins {
    Variable null = std::make_shared<BuiltinImpl::NullType>(BuiltinImpl::NullType());
    const Variable str = BuiltinImpl::str_t();
    Constants::Constant print = std::make_shared<Constants::Function>(Constants::Function(Builtins::_print));
    const std::vector<Constants::Constant> values = {
            print
    };
}

void Builtins::_print(const std::vector<Variable> &args, Runtime* runtime) {
    for (const auto& arg : args) {
        std::cout << arg->str(runtime) << std::endl;
    }
}

Type Builtins::int_() {
    static Type instance = std::make_shared<Constants::IntType>();
    return instance;
}
