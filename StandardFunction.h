//
// Created by Patrick Norton on 22/1/20.
//

#ifndef RUNTIME_STANDARDFUNCTION_H
#define RUNTIME_STANDARDFUNCTION_H


#include "Constant.h"

namespace Constants {
    class StandardFunction : _Constant {
    private:
        uint32_t location;
    public:
        explicit StandardFunction(uint32_t location);
        Variable callOperator(Operator, std::vector<Variable>) override;
        explicit inline operator bool() override;
    };
}


#endif //RUNTIME_STANDARDFUNCTION_H
