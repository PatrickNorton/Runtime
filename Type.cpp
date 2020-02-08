//
// Created by Patrick Norton on 15/1/20.
//

#include "Type.h"

#include <utility>
#include "Runtime.h"

namespace Constants {
    _Type::_Type(std::unordered_map<Operator, Callable> operators, std::set<Type> supers) {
        this->operators = std::move(operators);
        this->supers = std::move(supers);
    }

    bool _Type::isSubclassOf(const Type& type) {
        if (shared_from_this() == type) {
            return true;
        }
        for (const auto& super : supers) {
            if (super->isSubclassOf(type)) {
                return true;
            }
        }
        return false;
    }

    bool _Type::isTypeOf(const Variable& var) {
        return var->getType()->isSubclassOf(this_ptr<_Type>());
    }

    Variable _Type::createNew(const std::vector<Variable>& args, Runtime* runtime) {
        operator()(args, runtime);
        return runtime->pop();
    }

    void _Type::operator()(const std::vector<Variable>& args, Runtime* runtime) {
        runtime->push(createNew(args, runtime));
    }
}
