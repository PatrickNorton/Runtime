//
// Created by Patrick Norton on 15/1/20.
//

#ifndef RUNTIME_STDVARIABLE_H
#define RUNTIME_STDVARIABLE_H


#include <map>
#include "Variable.h"
#include "Type.h"
#include "FileInfo.h"

namespace Constants {
    class StdType;
}

class StdVariable final : public _Variable {
private:
    friend class Constants::StdType;
    std::shared_ptr<Constants::StdType> type;
    std::map<std::string, Variable> cache;
    std::map<Operator, Variable> opCache;
    std::map<std::shared_ptr<Constants::StdType>, Variable> supers;

public:
    StdVariable(std::shared_ptr<Constants::StdType>, const std::vector<Variable>&, Runtime*);
    Variable operator[] (std::pair<std::string, Runtime*>) override;
    Variable operator[] (std::pair<Operator, Runtime*>) override;
    Type getType() override;
    void set(const std::string&, const Variable&, Runtime*) override;
};

typedef std::shared_ptr<StdVariable> StdVariablePtr;

namespace Constants {
    class StdType final : public _Type {
    private:
        FileInfo* file;

        std::set<std::shared_ptr<StdType>> supers;

        std::set<std::string> vars;  // TODO: Static variables
        std::map<std::string, uint32_t> methods;
        std::map<std::string, uint32_t> staticMethods;
        std::map<Operator, uint32_t> operators;
        std::map<Operator, uint32_t> staticOperators;

        static void generify(const std::shared_ptr<StdType>&, const std::vector<Variable>&, Runtime*);

    public:
        StdType(FileInfo*, uint16_t, std::map<Operator, uint32_t>, std::map<Operator, uint32_t>,
                std::map<std::string, uint32_t>, std::map<std::string, uint32_t>);
        Variable operator[] (std::pair<std::string, Runtime*>) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
        Variable getMethod(const std::string&, StdVariablePtr);
        Variable getMethod(Operator, StdVariablePtr);
        Variable createNew(const std::vector<Variable>&, Runtime*) override;
    };
}


#endif //RUNTIME_STDVARIABLE_H
