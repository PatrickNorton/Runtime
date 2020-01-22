//
// Created by Patrick Norton on 12/1/20.
//

#include <utility>
#include <vector>
#include "Constant.h"
#include "Builtins.h"
#include "BuiltinImpl.h"
#include "Runtime.h"

namespace Constants {
    std::string Function::str() {
        return std::string();
    }

    Function::Function(Callable caller) {
        function = std::move(caller);
    }

    Variable Function::callOperator(Operator o, std::vector<Variable> args) {
        throw std::runtime_error("No longer implemented");
    }

    uint32_t Function::operator()(uint16_t argc, Runtime *runtime) {
        runtime->callIsNative();
        std::vector<Variable> args(argc);
        for (uint16_t i = argc - 1; i >= 0; i++) {
            args[argc] = runtime->pop();
        }
        function(argc, runtime);
        return 0;
    }

    Function::Function(const Function::OldCallable &caller) {
        function = [=](uint16_t argc, Runtime *runtime) { return convert(caller, argc, runtime); };
    }

    void Function::convert(const Function::OldCallable &caller, uint16_t argc, Runtime *runtime) {
        std::vector<Variable> args(argc);
        for (uint16_t i = argc - 1; i >= 0; i++) {
            args[argc] = runtime->pop();
        }
        caller(args);
    }

    Constant null() {
        static Constant instance = std::make_shared<BuiltinImpl::NullType>(BuiltinImpl::NullType());
        return instance;
    }
}
