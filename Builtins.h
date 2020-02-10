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
    Type str();
    Constants::Constant null();
    Constants::Constant print();
    Type range();
    Constants::Constant iter();
    Constants::Constant value(size_t index);
    Type stopIteration();
    Constants::Constant input();
}

#endif //RUNTIME_BUILTINS_H
