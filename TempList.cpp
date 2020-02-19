//
// Created by Patrick Norton on 18/2/20.
//

#include "TempList.h"

#include <utility>
#include "Runtime.h"
#include "StringUtils.h"

namespace Constants {

    void ListType::listStr(const ListPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        std::string result = "[";
        for (int i = 0; i < self->internal.size(); i++) {
            result += self->internal[i]->str(runtime);
            if (i != self->internal.size() - 1) {
                result += ", ";
            }
        }
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
        };
        return operators.at(op);
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
}

TempList::TempList() = default;

TempList::TempList(std::vector<Variable> args) : internal(std::move(args)) {
}

Variable TempList::operator[](std::pair<std::string, Runtime*> pair) {
    return std::make_shared<Constants::GenericM<TempList>>(this_ptr<TempList>(), Constants::ListType::methodOf(pair.first));
}

Variable TempList::operator[](std::pair<Operator, Runtime*> pair) {
    return std::make_shared<Constants::GenericM<TempList>>(this_ptr<TempList>(), Constants::ListType::methodOf(pair.first));
}
