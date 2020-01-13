//
// Created by Patrick Norton on 12/1/20.
//

#include <utility>
#include <vector>
#include "Constant.h"
#include "Builtins.h"

Constants::String::String(std::string value) {
    this->value = std::move(value);
}

std::string Constants::String::str() {
    return this->value;
}

Variable Constants::String::callOperator(Operator o, std::vector<Variable> args) {
    throw std::runtime_error("Operators on strings not yet implemented");
}

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

Constants::IntConstant::IntConstant(uint32_t value) {
    values = {static_cast<int64_t>(value)};
}

Constants::IntConstant::IntConstant(std::vector<int64_t> values) {
    this->values = std::move(values);
}

std::string Constants::IntConstant::str() {
    return "";
}

Variable Constants::IntConstant::callOperator(Operator o, std::vector<Variable> args) {
    throw std::runtime_error("Operator not yet implemented");
}
