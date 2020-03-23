//
// Created by Patrick Norton on 18/2/20.
//

#include "TempList.h"

#include <utility>
#include "Runtime.h"
#include "StringUtils.h"
#include "Builtins.h"
#include "DefaultMethods.h"

namespace Constants {

    void ListType::listStr(const ListPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        std::string result = "[";
        for (auto& i : self->internal) {
            result += i->str(runtime);
            result += ", ";
        }
        result.erase(result.end() - 2, result.end());
        result += "]";
        runtime->push(Constants::fromNative(result));
    }

    void ListType::listIndex(const ListPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1);
        runtime->push(self->internal[static_cast<size_t>(args[0]->toInt(runtime))]);
    }

    void ListType::listAdd(const ListPtr& self, const std::vector<Variable>& args, Runtime*) {
        assert(args.size() == 1);
        self->internal.push_back(args[0]);
    }

    GenericMethod<TempList> ListType::methodOf(Operator op) {
        static std::map<Operator, GenericMethod<TempList>> operators = {
                {Operator::STR, listStr},
                {Operator::GET_ATTR, listIndex},
                {Operator::ITER, listIter},
        };
        return operators.count(op) ? operators.at(op) : nullptr;
    }

    Variable ListType::createNew(const std::vector<Variable>& args, Runtime*) {
        return std::make_shared<TempList>(args);
    }

    GenericMethod<TempList> ListType::methodOf(const std::string& str) {
        static std::map<std::string, GenericMethod<TempList>> operators = {
                {"add", listAdd},
        };
        return operators.at(str);
    }

    void ListType::listIter(const ListPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        runtime->push(std::make_shared<ListIter>(self));
    }

    void ListIter::next(const std::shared_ptr<ListIter>& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        if (self->index == self->value->size()) {
            runtime->throwQuick(Builtins::stopIteration(), "");
            return;
        }
        runtime->push((*self->value)[self->index++]);
    }

    ListIter::ListIter(ListPtr value) : value(std::move(value)), index(0) {}

    Variable ListIter::operator[](std::pair<std::string, Runtime*> pair) {
        if (pair.first == "next") {
            return std::make_shared<GenericM<ListIter>>(this_ptr<ListIter>(), next);
        } else {
            throw std::runtime_error("Illegal name for operator");
        }
    }
}

TempList::TempList() = default;

TempList::TempList(std::vector<Variable> args) : internal(std::move(args)) {
}

Variable TempList::operator[](std::pair<std::string, Runtime*> pair) {
    return std::make_shared<Constants::GenericM<TempList>>(this_ptr<TempList>(), Constants::ListType::methodOf(pair.first));
}

Variable TempList::operator[](std::pair<Operator, Runtime*> pair) {
    auto method = Constants::ListType::methodOf(pair.first);
    if (method == nullptr) {
        method = reinterpret_cast<Constants::GenericMethod<TempList>>(DefaultMethods::of(pair.first));
    }
    return std::make_shared<Constants::GenericM<TempList>>(this_ptr<TempList>(), method);
}

Variable TempList::operator[](size_t index) {
    return internal[index];
}

size_t TempList::size() {
    return internal.size();
}
