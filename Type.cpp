//
// Created by Patrick Norton on 15/1/20.
//

#include "Type.h"

#include <utility>

namespace Constants {
    _Type::_Type(std::unordered_map<Operator, Callable> operators) {
        this->operators = std::move(operators);
    }
}
