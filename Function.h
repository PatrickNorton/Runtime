//
// Created by Patrick Norton on 22/1/20.
//

#ifndef RUNTIME_FUNCTION_H
#define RUNTIME_FUNCTION_H


#include "Constant.h"
#include "Runtime.h"

namespace Constants {
    class StdFunction : public _Constant {
    private:
        uint32_t index;
    public:
        explicit StdFunction(uint32_t index);
        uint32_t operator() (uint16_t, Runtime*) override;
        Variable operator[] (std::pair<uint16_t, Runtime*>) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
    };
}


#endif //RUNTIME_FUNCTION_H
