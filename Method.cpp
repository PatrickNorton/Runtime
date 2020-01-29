//
// Created by Patrick Norton on 23/1/20.
//

#include "Method.h"

#include <utility>
#include "Runtime.h"

namespace Constants {
    Method::Method(Variable self, NativeMethod method) {
        value = method;
        this->self = std::move(self);
    }

    void Method::operator()(const std::vector<Variable>& args, Runtime* runtime) {
        value(self, args, runtime);
    }

    Variable Method::operator[](std::pair<Operator, Runtime*> pair) {
        Operator op = pair.first;
        if (op == Operator::CALL) {
            return shared_from_this();
        } else {
            throw std::runtime_error("");
        }
    }

    template<typename T>
    GenericM<T>::GenericM(std::shared_ptr<T>, GenericMethod<T>) {

    }
}
