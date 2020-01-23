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
        uint32_t operator() (const std::vector<Variable>& , Runtime*) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
    };
}


#endif //RUNTIME_METHOD_H
