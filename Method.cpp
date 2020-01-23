//
// Created by Patrick Norton on 23/1/20.
//

#include "Method.h"

#include <utility>
#include "Runtime.h"

namespace Constants {
    Method::Method(Variable self, MethodPtr method) {
        value = method;
        this->self = std::move(self);
    }

    Variable Method::callOperator(Operator o, std::vector<Variable> args) {
        throw std::runtime_error("");
    }

    uint32_t Method::operator()(const std::vector<Variable>& args, Runtime* runtime) {
        runtime->callIsNative();
        value(self, args, runtime);
        return 0;
    }

    Variable Method::operator[](std::pair<Operator, Runtime*> pair) {
        Operator op = pair.first;
        if (op == Operator::CALL) {
            return shared_from_this();
        } else {
            throw std::runtime_error("");
        }
    }
}
