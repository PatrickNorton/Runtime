//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_BUILTINS_H
#define RUNTIME_BUILTINS_H

#include <vector>
#include "Variable.h"

namespace Builtins {
    Variable str;
    void print(std::vector<Variable> args);
}

#endif //RUNTIME_BUILTINS_H
