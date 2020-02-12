//
// Created by Patrick Norton on 28/1/20.
//

#include "Tuple.h"
#include "Runtime.h"
#include "IntUtils.h"
#include "Method.h"

namespace Constants {

    Tuple::Tuple(std::vector<Variable> values) {
        this->values = std::move(values);
    }

    Variable Tuple::operator[](std::pair<Operator, Runtime *> op) {
        return std::make_shared<GenericM<Tuple>>(
                this_ptr<Tuple>(),
                TupleType::getOperator(op.first)
        );
    }

    bool Tuple::toBool(Runtime*) {
        return !values.empty();
    }

    void TupleType::tupleIndex(const TuplePtr& self, const std::vector<Variable> &argv, Runtime *runtime) {
        assert(argv.size() == 1);
        runtime->push(self->values[size_t(argv[0]->toInt(runtime))]);
    }

    void TupleType::tupleBool(const TupleType::TuplePtr& self, const std::vector<Variable>&, Runtime* runtime) {
        runtime->push(Constants::fromNative(!self->values.empty()));
    }

    Variable TupleType::createNew(const std::vector<Variable>& args, Runtime*) {
        return std::make_shared<Tuple>(args);
    }

    GenericMethod<Tuple> TupleType::getOperator(Operator o) {
        static std::map<Operator, GenericMethod<Tuple>> ops = {
                {Operator::BOOL, tupleBool},
                {Operator::GET_ATTR, tupleIndex},
        };
        return ops.at(o);
    }
}
