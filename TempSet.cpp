//
// Created by Patrick Norton on 22/2/20.
//

#include "TempSet.h"

#include <utility>
#include "StringUtils.h"
#include "DefaultMethods.h"

namespace Constants {

    void SetType::setStr(const SetPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        std::string result = "{";
        for (auto& i : self->internal) {
            result += i->str(runtime);
            result += ", ";
        }
        result.erase(result.end() - 2, result.end());
        result += "}";
        runtime->push(Constants::fromNative(result));
    }

    void SetType::setAdd(const SetPtr& self, const std::vector<Variable>& args, Runtime*) {
        assert(args.size() == 1);
        self->internal.insert(args[0]);
    }

    void SetType::setIter(const SetPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        runtime->push(std::make_shared<SetIter>(self));
    }

    Variable SetType::createNew(const std::vector<Variable>& args, Runtime*) {
        return std::make_shared<TempSet>(std::set<Variable>(args.begin(), args.end()));
    }

    GenericMethod<TempSet> SetType::methodOf(Operator op) {
        static std::map<Operator, GenericMethod<TempSet>> operators = {
                {Operator::STR, setStr},
                {Operator::ITER, setIter},
        };
        return operators.count(op) ? operators.at(op) : nullptr;
    }

    GenericMethod<TempSet> SetType::methodOf(const std::string& str) {
        static std::map<std::string, GenericMethod<TempSet>> operators = {
                {"add", setAdd},
        };
        return operators.at(str);
    }

    void SetIter::next(const std::shared_ptr<SetIter>& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        runtime->push(*(self->index++));
    }

    SetIter::SetIter(SetPtr value) : value(std::move(value)) {
    }

    Variable SetIter::operator[](std::pair<std::string, Runtime*> pair) {
        if (pair.first == "next") {
            return std::make_shared<GenericM<SetIter>>(this_ptr<SetIter>(), next);
        } else {
            throw std::runtime_error("Illegal name for operator");
        }
    }
}

TempSet::TempSet() = default;

TempSet::TempSet(std::set<Variable> args) : internal(std::move(args)) {
}

Variable TempSet::operator[](std::pair<std::string, Runtime*> pair) {
    return std::make_shared<Constants::GenericM<TempSet>>(this_ptr<TempSet>(), Constants::SetType::methodOf(pair.first));
}

Variable TempSet::operator[](std::pair<Operator, Runtime*> pair) {
    auto method = Constants::SetType::methodOf(pair.first);
    if (method == nullptr) {
        method = reinterpret_cast<Constants::GenericMethod<TempSet>>(DefaultMethods::of(pair.first));
    }
    return std::make_shared<Constants::GenericM<TempSet>>(this_ptr<TempSet>(), method);
}

size_t TempSet::size() {
    return internal.size();
}