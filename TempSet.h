//
// Created by Patrick Norton on 22/2/20.
//

#ifndef RUNTIME_TEMPSET_H
#define RUNTIME_TEMPSET_H

#include <set>

#include "Variable.h"
#include "Method.h"
#include "Type.h"

namespace Constants {class SetType; class SetIter;}

class TempSet : public _Variable {
private:
    friend class Constants::SetType;
    friend class Constants::SetIter;
    std::set<Variable> internal;
public:
    TempSet();
    explicit TempSet(std::set<Variable>);
    Variable operator[] (std::pair<std::string, Runtime*>) override;
    Variable operator[] (std::pair<Operator, Runtime*>) override;
    size_t size();
};

typedef std::shared_ptr<TempSet> SetPtr;

namespace Constants {
    class SetType : public _Type {
    private:
        static void setStr(const SetPtr&, const std::vector<Variable>&, Runtime*);
        static void setAdd(const SetPtr&, const std::vector<Variable>&, Runtime*);
        static void setIter(const SetPtr&, const std::vector<Variable>&, Runtime*);

    public:
        Variable createNew(const std::vector<Variable>&, Runtime*) override;
        static GenericMethod<TempSet> methodOf(Operator);
        static GenericMethod<TempSet> methodOf(const std::string&);
    };

    class SetIter : public _Variable {
    private:
        SetPtr value;
        std::set<Variable>::iterator index = value->internal.begin();

        static void next(const std::shared_ptr<SetIter>&, const std::vector<Variable>&, Runtime*);

    public:
        explicit SetIter(SetPtr);
        Variable operator[] (std::pair<std::string, Runtime*>) override;
    };
}


#endif //RUNTIME_TEMPSET_H
