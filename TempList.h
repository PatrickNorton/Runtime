//
// Created by Patrick Norton on 18/2/20.
//

#ifndef RUNTIME_TEMPLIST_H
#define RUNTIME_TEMPLIST_H


#include "Variable.h"
#include "Type.h"

class TempList;

typedef std::shared_ptr<TempList> ListPtr;

namespace Constants {
    class ListType : public _Type {
    private:
        static void listStr(const ListPtr&, const std::vector<Variable>&, Runtime*);
        static void listIndex(const ListPtr&, const std::vector<Variable>&, Runtime*);
        static void listAdd(const ListPtr&, const std::vector<Variable>&, Runtime*);

    public:
        Variable createNew(const std::vector<Variable>&, Runtime*) override;
        static GenericMethod<TempList> methodOf(Operator);
        static GenericMethod<TempList> methodOf(const std::string&);
    };
}


class TempList : public _Variable {
private:
    friend class Constants::ListType;
    std::vector<Variable> internal;
public:
    TempList();
    explicit TempList(std::vector<Variable>);
    Variable operator[] (std::pair<std::string, Runtime*>) override;
    Variable operator[] (std::pair<Operator, Runtime*>) override;
};


#endif //RUNTIME_TEMPLIST_H
