//
// Created by Patrick Norton on 12/1/20.
//

#include <utility>
#include <vector>
#include "Constant.h"
#include "BuiltinImpl.h"
#include "Runtime.h"

namespace Constants {
    std::string Function::str(Runtime *) {
        return std::string();
    }

    Function::Function(NativeCallable caller) {
        function = caller;
    }

    void Function::operator()(const std::vector<Variable>& args, Runtime *runtime) {
        function(args, runtime);
    }

    Variable Function::operator[](std::pair<Operator, Runtime *> pair) {
        if (pair.first == Operator::CALL) {
            return shared_from_this();
        } else {
            throw std::runtime_error("Not yet implemented");
        }
    }

    Constant null() {
        static Constant instance = std::make_shared<BuiltinImpl::NullType>(BuiltinImpl::NullType());
        return instance;
    }
}
