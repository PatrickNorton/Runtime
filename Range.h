//
// Created by Patrick Norton on 31/1/20.
//

#ifndef RUNTIME_RANGE_H
#define RUNTIME_RANGE_H


#include <map>
#include "Variable.h"
#include "Type.h"
#include "Method.h"

class Range;

typedef std::shared_ptr<Range> RangePtr;

namespace Constants {
    class RangeIterator : public _Variable {
    private:
        Bigint current;
        Bigint step;
        Bigint stop;

        static void next(const std::shared_ptr<RangeIterator>&, const std::vector<Variable>&, Runtime*);
    public:
        explicit RangeIterator(const RangePtr&);
        Variable operator[] (std::pair<std::string, Runtime*>) override;
    };

    class RangeType : public _Type {
    private:
        static void rangeStr(const RangePtr&, const std::vector<Variable>&, Runtime*);
        static void rangeEq(const RangePtr&, const std::vector<Variable>&, Runtime*);
        static void rangeContains(const RangePtr&, const std::vector<Variable>&, Runtime*);
        static void rangeAttr(const RangePtr&, const std::vector<Variable>&, Runtime*);
        static void rangeIter(const RangePtr&, const std::vector<Variable>&, Runtime*);

    public:
        Variable createNew(const std::vector<Variable>&, Runtime*) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;

        static GenericMethod<Range> rangeMethod(Operator);
    };
}

class Range : public _Variable {
private:
    friend class Constants::RangeType;
    friend class Constants::RangeIterator;
    Bigint start;
    Bigint stop;
    Bigint step;

    std::map<Operator, std::shared_ptr<Constants::GenericM<Range>>> methods;
public:
    Range(Bigint start, Bigint stop, Bigint step);
    Variable operator[] (std::pair<std::string, Runtime*>) override;
    Variable operator[] (std::pair<Operator, Runtime*>) override;
};


#endif //RUNTIME_RANGE_H
