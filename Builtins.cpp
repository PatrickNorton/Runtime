//
// Created by Patrick Norton on 11/1/20.
//

#include <utility>
#include <vector>
#include <iostream>
#include "Builtins.h"
#include "Operator.h"
#include "BuiltinImpl.h"


namespace Builtins {
    Variable null = std::make_shared<BuiltinImpl::NullType>(BuiltinImpl::NullType());
    const Variable str = BuiltinImpl::str_t();
    Constants::Constant print = std::make_shared<Constants::Function>(Constants::Function(Builtins::_print));
    const std::vector<Constants::Constant> values = {
            print
    };
}

void Builtins::_print(const std::vector<Variable> &args) {
    for (const auto& arg : args) {
        std::cout << arg->str() << std::endl;
    }
}
