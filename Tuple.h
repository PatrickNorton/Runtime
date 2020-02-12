//
// Created by Patrick Norton on 28/1/20.
//

#ifndef RUNTIME_TUPLE_H
#define RUNTIME_TUPLE_H


#include <map>
#include "Constant.h"
#include "Type.h"

namespace Constants {
    class Tuple;

    class TupleType : public _Type {
    private:
        friend class Tuple;
        typedef std::shared_ptr<Tuple> TuplePtr;
        static void tupleIndex(const TuplePtr&, const std::vector<Variable>&, Runtime*);
        static void tupleBool(const TuplePtr&, const std::vector<Variable>&, Runtime*);

        static GenericMethod<Tuple> getOperator(Operator o);

    public:
        Variable createNew(const std::vector<Variable>&, Runtime*) override;
    };

    class Tuple : public _Constant {
    private:
        friend class TupleType;
        std::vector<Variable> values;
    public:
        explicit Tuple(std::vector<Variable> values);
        bool toBool(Runtime*) override;
        Variable operator[] (std::pair<Operator, Runtime*>) override;
    };
}


#endif //RUNTIME_TUPLE_H
