//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_BUILTINS_H
#define RUNTIME_BUILTINS_H

#include <vector>
#include "Variable.h"
#include "Constant.h"

namespace Builtins {
    Type int_();
    Variable str();
    Variable null();
    Constants::Constant print();
    Constants::Constant value(size_t index);
    Variable stopIteration();
}

#endif //RUNTIME_BUILTINS_H
