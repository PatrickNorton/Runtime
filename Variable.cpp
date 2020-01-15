//
// Created by Patrick Norton on 11/1/20.
//

#include <vector>
#include "Builtins.h"
#include "Variable.h"

std::string _Variable::str() {
    return callOperator(Operator::STR, {})->str();
}

Bigint _Variable::toInt() {
    return callOperator(Operator::INT, {})->toInt();
}
