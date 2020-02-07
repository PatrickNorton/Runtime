//
// Created by Patrick Norton on 15/1/20.
//

#ifndef RUNTIME_STDVARIABLE_H
#define RUNTIME_STDVARIABLE_H


#include <map>
#include "Variable.h"
#include "Type.h"

namespace Constants {
    class StdType;
}

class StdVariable final : public _Variable {
private:
    std::shared_ptr<Constants::StdType> type;
    std::map<std::string, Variable> cache;
    std::map<Operator, Variable> opCache;

public:
    StdVariable(std::shared_ptr<Constants::StdType>, const std::vector<Variable>&, Runtime*);
    Variable operator[] (std::pair<std::string, Runtime*>) override;
    Variable operator[] (std::pair<Operator, Runtime*>) override;
    Type getType() override;
};

typedef std::shared_ptr<StdVariable> StdVariablePtr;

namespace Constants {
    class StdType final : public _Type {
    private:
        std::set<std::shared_ptr<StdType>> supers;

        std::map<std::string, uint32_t> methods;
        std::map<std::string, uint32_t> staticMethods;
        std::map<Operator, uint32_t> operators;
        std::map<Operator, uint32_t> staticOperators;

    public:
        StdType(std::map<std::string, uint32_t>, std::map<std::string, uint32_t>);
        void operator() (const std::vector<Variable>&, Runtime*) override;
        Variable operator[] (std::pair<std::string, Runtime*>) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
        Variable getMethod(const std::string&, StdVariablePtr);
        Variable getMethod(Operator, StdVariablePtr);
    };
}


#endif //RUNTIME_STDVARIABLE_H
