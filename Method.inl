//
// Created by Patrick Norton on 29/1/20.
//

#ifndef RUNTIME_METHOD_INL
#define RUNTIME_METHOD_INL


#include "Constant.h"

namespace Constants {
    template<typename T>
    GenericM<T>::GenericM(std::shared_ptr<T> self, GenericMethod<T> value) : self(self), value(value) {
    }

    template<typename T>
    void GenericM<T>::operator()(const std::vector<Variable>& args, Runtime* runtime) {
        value(self, args, runtime);
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
