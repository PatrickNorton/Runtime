//
// Created by Patrick Norton on 12/1/20.
//

#include <utility>
#include <vector>
#include "Constant.h"
#include "Builtins.h"
#include "BuiltinImpl.h"
#include "Runtime.h"

std::string Constants::Function::str() {
    return std::string();
}

Constants::Function::Function(Callable caller) {
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

uint32_t Constants::Function::operator()(uint16_t argc, Runtime* runtime) {
    runtime->callIsNative();
    std::vector<Variable> args(argc);
    for (uint16_t i = argc - 1; i >= 0; i++) {
        args[argc] = runtime->pop();
    }
    function(args);
    return 0;
}

Constants::Constant Constants::null() {
    static Constant instance = std::make_shared<BuiltinImpl::NullType>(BuiltinImpl::NullType());
    return instance;
}
