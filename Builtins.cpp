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
    Variable null = nullptr;
    const Variable str = std::make_shared<_Variable>(new BuiltinImpl::str_t());
}


void Builtins::print(const std::vector<Variable>& args) {
    for (const auto& arg : args) {
        std::cout << arg->str();
    }
}
