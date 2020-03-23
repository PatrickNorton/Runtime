//
// Created by Patrick Norton on 23/3/20.
//

#include "DefaultMethods.h"
#include "Runtime.h"
#include "IntUtils.h"
#include "StringUtils.h"


void defaultBool(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    assert(args.empty());
    runtime->push(Constants::fromNative(true));
}


void defaultEquals(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    for (const auto& arg : args) {
        if (arg != self) {
            runtime->push(Constants::fromNative(false));
            return;
        }
    }
    runtime->push(Constants::fromNative(true));
}


void defaultRepr(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    assert(args.empty());
    runtime->push(Constants::fromNative(self->getType()->str(runtime) + std::to_string(ptrdiff_t(self.get()))));
}


void defaultStr(const Variable& self, const std::vector<Variable>& args, Runtime* runtime) {
    assert(args.empty());
    runtime->call(self, Operator::REPR, args);
}


namespace DefaultMethods {
    Constants::GenericMethod<_Variable> of(Operator value) {
        static const std::unordered_map<Operator, Constants::GenericMethod<_Variable>> map = {
                {Operator::BOOL, defaultBool},
                {Operator::EQUALS, defaultEquals},
                {Operator::REPR, defaultRepr},
                {Operator::STR, defaultStr},
        };
        return map.at(value);
    }
}