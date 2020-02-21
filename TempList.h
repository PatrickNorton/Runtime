//
// Created by Patrick Norton on 18/2/20.
//

#ifndef RUNTIME_TEMPLIST_H
#define RUNTIME_TEMPLIST_H


#include "Variable.h"
#include "Type.h"


namespace Constants {class ListType;}

class TempList : public _Variable {
private:
    friend class Constants::ListType;
    std::vector<Variable> internal;
public:
    TempList();
    explicit TempList(std::vector<Variable>);
    Variable operator[] (std::pair<std::string, Runtime*>) override;
    Variable operator[] (std::pair<Operator, Runtime*>) override;
    Variable operator[] (size_t);
    size_t size();
};

typedef std::shared_ptr<TempList> ListPtr;

namespace Constants {
    class ListType : public _Type {
    private:
        static void listStr(const ListPtr&, const std::vector<Variable>&, Runtime*);
        static void listIndex(const ListPtr&, const std::vector<Variable>&, Runtime*);
        static void listAdd(const ListPtr&, const std::vector<Variable>&, Runtime*);
        static void listIter(const ListPtr&, const std::vector<Variable>&, Runtime*);

    public:
        Variable createNew(const std::vector<Variable>&, Runtime*) override;
        static GenericMethod<TempList> methodOf(Operator);
        static GenericMethod<TempList> methodOf(const std::string&);
    };

    class ListIter : public _Variable {
    private:
        size_t index{};
        ListPtr value;

        static void next(const std::shared_ptr<ListIter>&, const std::vector<Variable>&, Runtime*);

    public:
        explicit ListIter(ListPtr);
        Variable operator[] (std::pair<std::string, Runtime*>) override;
    };
}


#endif //RUNTIME_TEMPLIST_H
