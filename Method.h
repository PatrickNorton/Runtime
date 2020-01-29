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
}

#include "Method.inl"


#endif //RUNTIME_METHOD_H
