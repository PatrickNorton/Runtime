//
// Created by Patrick Norton on 29/1/20.
//

#ifndef RUNTIME_METHOD_INL
#define RUNTIME_METHOD_INL


#include "Constant.h"
#include "Runtime.h"

namespace Constants {

    template<typename T>
    Method<T>::Method(self_t self, uint32_t index) : self(self), index(index) {
    }

    template<typename T>
    void Method<T>::operator() (const std::vector<Variable>& args, Runtime* runtime) {
        auto newArgs = args;
        newArgs.insert(newArgs.begin(), self->getType());
        newArgs.insert(newArgs.begin(), self);
        runtime->call(index, newArgs);
    }

    template<typename T>
    Variable Method<T>::operator[] (std::pair<Operator, Runtime*> pair) {
        if (pair.first == Operator::CALL) {
            return shared_from_this();
        } else {
            throw std::runtime_error("Operator not implemented");
        }
    }

    template<typename T>
    GenericM<T>::GenericM(std::shared_ptr<T> self, GenericMethod<T> value) : self(self), value(value) {
    }

    template<typename T>
    void GenericM<T>::operator()(const std::vector<Variable>& args, Runtime* runtime) {
        runtime->pushNativeFrame();
        value(self, args, runtime);
        runtime->popStack();
    }

    template<typename T>
    Variable GenericM<T>::operator[](std::pair<Operator, Runtime*> pair) {
        if (pair.first == Operator::CALL) {
            return shared_from_this();
        } else {
            throw std::runtime_error("Does not implement this operator");
        }
    }
}


#endif  // RUNTIME_METHOD_INL
