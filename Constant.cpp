//
// Created by Patrick Norton on 12/1/20.
//

#include <utility>
#include <vector>
#include "Constant.h"
#include "Builtins.h"
#include "BuiltinImpl.h"

std::string Constants::Function::str() {
    return std::string();
}

Constants::Function::Function(void (*caller)(const std::vector<Variable>&)) {
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

Constants::Constant Constants::null() {
    static Constant instance = std::make_shared<BuiltinImpl::NullType>(BuiltinImpl::NullType());
    return instance;
}
