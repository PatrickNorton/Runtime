//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_BUILTINS_H
#define RUNTIME_BUILTINS_H

#include <vector>
#include "Variable.h"
#include "Constant.h"

namespace Builtins {
    extern const Variable str;
    extern Variable null;
    extern Constants::Constant print;
    extern const std::vector<Constants::Constant> values;
    void _print(const std::vector<Variable>&, Runtime*);

    Type int_();
}

#endif //RUNTIME_BUILTINS_H
