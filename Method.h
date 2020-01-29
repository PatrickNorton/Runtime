//
// Created by Patrick Norton on 23/1/20.
//

#ifndef RUNTIME_METHOD_H
#define RUNTIME_METHOD_H


#include "Constant.h"

namespace Constants {
    class Method : public _Constant {
    private:
        NativeMethod value;
        Variable self;
    public:
        Method(Variable, NativeMethod);
        void operator() (const std::vector<Variable>& , Runtime*) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
    };

    template <typename T>
    class GenericM : public _Constant {
    private:
        GenericMethod<T> value;
        std::shared_ptr<T> self;
    public:
        GenericM(std::shared_ptr<T>, GenericMethod<T>);
        void operator() (const std::vector<Variable>& , Runtime*) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
    };

    // Template definitions have to be in header file...
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


#endif //RUNTIME_METHOD_H
