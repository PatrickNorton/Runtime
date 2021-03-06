//
// Created by Patrick Norton on 31/1/20.
//

#include "Range.h"
#include "Runtime.h"
#include "StringUtils.h"
#include "IntUtils.h"
#include "Builtins.h"
#include "DefaultMethods.h"

#include <utility>

namespace Constants {

    void RangeType::rangeStr(const RangePtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        std::string str = "[" + self->start.to_string() + ":" + self->stop.to_string() + ":" + self->step.to_string() + "]";
        runtime->push(Constants::fromNative(str));
    }

    void RangeType::rangeEq(const RangePtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1 && RangeType().isTypeOf(args[0]));
        auto other = std::dynamic_pointer_cast<Range>(args[0]);
        runtime->push(Constants::fromNative(self->start == other->start && self->stop == other->stop && self->step == other->step));
    }

    void RangeType::rangeContains(const RangePtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1 && Builtins::int_()->isTypeOf(args[0]));
        const auto& val = args[0]->toInt(runtime);
        if (self->step < 0_B) {
            runtime->push(Constants::fromNative(val < self->start && val >= self->stop && (val - self->start) % -self->step == 0_B));
        } else {
            runtime->push(Constants::fromNative(val > self->start && val <= self->stop && (val - self->start) % self->step == 0_B));
        }
    }

    void RangeType::rangeAttr(const RangePtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1 && Builtins::int_()->isTypeOf(args[0]));
        const auto& val = args[0]->toInt(runtime);
        runtime->push(Constants::fromNative(self->start + val * self->step));
    }

    Variable RangeType::operator[](std::pair<Operator, Runtime*> pair) {
        if (pair.first == Operator::CALL) {
            return shared_from_this();
        } else {
            throw std::runtime_error("Invalid operator");
        }
    }

    Variable RangeType::createNew(const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 3);
        return std::make_shared<Range>(
                args[0]->toInt(runtime),
                args[1]->toInt(runtime),
                args[2]->toInt(runtime)
        );
    }

    void RangeType::rangeIter(const RangePtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        runtime->push(std::make_shared<RangeIterator>(self));
    }

    void RangeType::rangeSlice(const RangePtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 3);
        auto start = args[0]->toInt(runtime);
        auto stop = args[1]->toInt(runtime);
        auto step = args[2]->toInt(runtime);
        runtime->push(std::make_shared<Range>(
                self->start + start * step,
                self->start + stop * step,
                self->step * step
        ));
    }

    GenericMethod<Range> RangeType::rangeMethod(Operator o) {
        static std::map<Operator, GenericMethod<Range>> operators = {
                {Operator::STR, rangeStr},
                {Operator::EQUALS, rangeEq},
                {Operator::IN, rangeContains},
                {Operator::GET_ATTR, rangeAttr},
                {Operator::ITER, rangeIter},
                {Operator::GET_SLICE, rangeSlice},
        };
        return operators.count(o) ? operators.at(o) : nullptr;
    }

    RangeIterator::RangeIterator(const RangePtr& val) {
        this->current = val->start;
        this->step = val->step;
        this->stop = val->stop;
    }

    Variable RangeIterator::operator[](std::pair<std::string, Runtime*> pair) {
        if (pair.first == "next") {
            return std::make_shared<Constants::GenericM<RangeIterator>>(this_ptr<RangeIterator>(), next);
        } else {
            throw std::runtime_error("Not implemented");
        }
    }

    void RangeIterator::next(const std::shared_ptr<RangeIterator>& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        if (self->current >= self->stop) {
            runtime->throwQuick(Builtins::stopIteration(), "");
            return;
        }
        runtime->push(Constants::fromNative(self->current));
        self->current += self->step;
    }
}

Range::Range(Bigint start, Bigint stop, Bigint step) {
    this->start = std::move(start);
    this->stop = std::move(stop);
    this->step = std::move(step);

    methods = {};
}

Variable Range::operator[](std::pair<std::string, Runtime*>) {
    throw std::runtime_error("Not implemented");
}

Variable Range::operator[](std::pair<Operator, Runtime*> pair) {
    Operator op = pair.first;
    if (!methods.count(op)) {
        auto self = this_ptr<Range>();
        auto method = Constants::RangeType::rangeMethod(op);
        if (method == nullptr) {
            method = reinterpret_cast<Constants::GenericMethod<Range>>(DefaultMethods::of(op));
        }
        methods[op] = std::make_shared<Constants::GenericM<Range>>(std::move(self), method);
    }
    return methods.at(op);
}
