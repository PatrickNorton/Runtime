//
// Created by Patrick Norton on 15/1/20.
//

#include "StdVariable.h"
#include "Method.h"
#include "Function.h"

#include <utility>

StdVariable::StdVariable(std::shared_ptr<Constants::StdType> type, const std::vector<Variable>& args, Runtime* runtime) {
    this->type = std::move(type);
}

Variable StdVariable::operator[](std::pair<std::string, Runtime*> pair) {
    if (!cache.count(pair.first)) {
        cache[pair.first] = type->getMethod(pair.first, this_ptr<StdVariable>());
    }
    return cache.at(pair.first);
}

Variable StdVariable::operator[](std::pair<Operator, Runtime*> pair) {
    if (!opCache.count(pair.first)) {
        opCache[pair.first] = type->getMethod(pair.first, this_ptr<StdVariable>());
    }
    return opCache.at(pair.first);
}

Type StdVariable::getType() {
    return type;
}

namespace Constants {
    StdType::StdType(std::map<std::string, uint32_t> methods, std::map<std::string, uint32_t> staticM)
            : _Type({}) {
        this->methods = std::move(methods);
        this->staticMethods = std::move(staticM);
    }

    Variable StdType::getMethod(const std::string& name, StdVariablePtr self) {
        if (methods.count(name)) {
            return std::make_shared<Method<StdVariable>>(self, methods.at(name));
        } else {
            return (*this)[{name, nullptr}];
        }
    }

    Variable StdType::getMethod(Operator op, StdVariablePtr self) {
        return std::make_shared<Method<StdVariable>>(self, operators.at(op));
    }

    Variable StdType::operator[](std::pair<std::string, Runtime*> pair) {
        return std::make_shared<StdFunction>(staticMethods.at(pair.first));
    }

    Variable StdType::operator[](std::pair<Operator, Runtime*> pair) {
        return std::make_shared<StdFunction>(staticOperators.at(pair.first));
    }

    Variable StdType::createNew(const std::vector<Variable>& args, Runtime* runtime) {
        auto instance = std::make_shared<StdVariable>(this_ptr<StdType>(), args, runtime);
        if (operators.count(Operator::NEW)) {
            (*this->getMethod(Operator::NEW, instance))(args, runtime);
        } else {
            for (const auto& super : supers) {
                instance->supers[super] = super->createNew({}, runtime);
            }
        }
        return instance;
    }
}
