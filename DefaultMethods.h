//
// Created by Patrick Norton on 23/3/20.
//

#ifndef RUNTIME_DEFAULTMETHODS_H
#define RUNTIME_DEFAULTMETHODS_H


#include "Operator.h"
#include "Variable.h"
#include "Constant.h"

namespace DefaultMethods {
    Constants::GenericMethod<_Variable> of(Operator value);
};


#endif //RUNTIME_DEFAULTMETHODS_H
