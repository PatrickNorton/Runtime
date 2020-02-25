//
// Created by Patrick Norton on 24/2/20.
//

#include "TempDict.h"
#include "Method.h"
#include "StringUtils.h"

TempDict::TempDict() : internal() {
}

TempDict::TempDict(const std::vector<Variable>& keys, const std::vector<Variable>& values, Runtime* runtime)
: internal(highestOneBit(keys.size())) {
    assert(keys.size() == values.size());
    for (int i = 0; i < keys.size(); i++) {
        auto hash = TempDict::hash(keys[i], runtime);
        auto& result = internal[hash % internal.size()];
        if (!result) {
            result = {keys[i], values[i], hash};
        } else {
            result.emplace(keys[i], values[i], hash, runtime);
        }
    }
}

Variable TempDict::operator[](std::pair<std::string, Runtime*> pair) {
    return std::make_shared<Constants::GenericM<TempDict>>(this_ptr<TempDict>(), Constants::DictType::methodOf(pair.first));
}

Variable TempDict::operator[](std::pair<Operator, Runtime*> pair) {
    return std::make_shared<Constants::GenericM<TempDict>>(this_ptr<TempDict>(), Constants::DictType::methodOf(pair.first));
}

size_t TempDict::hash(const Variable& var, Runtime* runtime) {
    runtime->call(var, Operator::HASH, {});
    return runtime->pop()->toInt(runtime).operator size_t();
}

size_t TempDict::highestOneBit(size_t val) {
    size_t result = 0;
    for (; val > 0; val >>= 1u) {
        result++;
    }
    return 1u << result;
}

Variable TempDict::operator[](const std::pair<Variable, Runtime*>& pair) {
    auto hash = TempDict::hash(pair.first, pair.second);
    return internal[hash % internal.size()][pair];
}

namespace Constants {
    void DictType::dictStr(const DictPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        if (self->internal.empty()) {
            runtime->push(Constants::fromNative("{:}"));
            return;
        }
        std::string result = "{";
        for (auto& value : self->internal) {
            if (value) {
                while (true) {
                    result += value.getKey()->str(runtime);
                    result += ": ";
                    result += value.getValue()->str(runtime);
                    result += ", ";
                    if (!value.hasNext()) break;
                    value = value.getNext();
                }
            }
        }
        result.erase(result.end() - 2, result.end());
        result += "}";
        runtime->push(Constants::fromNative(result));
    }

    void DictType::dictGet(const DictPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1);
        auto result = (*self)[{args[0], runtime}];
        runtime->push(result);
    }

    void DictType::dictSet(const DictPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 2);
        auto hash = TempDict::hash(args[0], runtime);
        self->internal[hash % self->internal.size()].emplace(args[0], args[1], hash, runtime);
    }

    void DictType::dictClear(const DictPtr& self, const std::vector<Variable>& args, Runtime*) {
        assert(args.empty());
        self->internal = {};
    }

    GenericMethod<TempDict> DictType::methodOf(Operator op) {
        static std::map<Operator, GenericMethod<TempDict>> operators = {
                {Operator::STR, dictStr},
                {Operator::GET_ATTR, dictGet},
                {Operator::SET_ATTR, dictSet},
        };
        return operators.at(op);
    }

    GenericMethod<TempDict> DictType::methodOf(const std::string& str) {
        static std::map<std::string, GenericMethod<TempDict>> methods = {
                {"clear", dictClear},
        };
        return methods.at(str);
    }
}
