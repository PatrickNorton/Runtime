//
// Created by Patrick Norton on 24/2/20.
//

#include "TempDict.h"
#include "Method.h"
#include "StringUtils.h"
#include "Builtins.h"
#include "DefaultMethods.h"

TempDict::TempDict() : internal(), size() {
}

TempDict::TempDict(const std::vector<Variable>& keys, const std::vector<Variable>& values, Runtime* runtime)
: internal(highestOneBit(keys.size())), size(keys.size()) {
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
    auto method = Constants::DictType::methodOf(pair.first);
    if (method == nullptr) {
        method = reinterpret_cast<Constants::GenericMethod<TempDict>>(DefaultMethods::of(pair.first));
    }
    return std::make_shared<Constants::GenericM<TempDict>>(this_ptr<TempDict>(), method);
}

size_t TempDict::hash(const Variable& var, Runtime* runtime) {
    runtime->call(var, Operator::HASH, {});
    return runtime->pop()->toInt(runtime).operator size_t();
}

size_t TempDict::highestOneBit(size_t val) {
    if (!val) return 0;
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

void TempDict::grow(Runtime* runtime) {
    auto old = std::move(internal);
    internal = std::vector<DictUtils::DictPair>(old.empty() ? 1 : old.size() << 1u);
    for (auto& value : old) {
        if (value) {
            while (true) {
                internal[value.getHash() % internal.size()].emplace(value, runtime);
                if (!value.hasNext()) break;
                value = value.getNext();
            }
        }
    }
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
        if (result.size() == 1) {
            runtime->push(Constants::fromNative("{:}"));
            return;
        }
        result.erase(result.end() - 2, result.end());
        result += "}";
        runtime->push(Constants::fromNative(result));
    }

    void DictType::dictGet(const DictPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1);
        auto result = (*self)[{args[0], runtime}];
        if (result == nullptr) {
            runtime->throwQuick(Builtins::valueError(), "Key not found");
        }
        runtime->push(result);
    }

    void DictType::dictSet(const DictPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        if (self->size + 1 > 3*self->internal.size()/4) {
            self->grow(runtime);
        }
        assert(args.size() == 2);
        auto hash = TempDict::hash(args[0], runtime);
        bool wasChanged = self->internal[hash % self->internal.size()].emplace(args[0], args[1], hash, runtime);
        if (wasChanged) self->size++;
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
        return operators.count(op) ? operators.at(op) : nullptr;
    }

    GenericMethod<TempDict> DictType::methodOf(const std::string& str) {
        static std::map<std::string, GenericMethod<TempDict>> methods = {
                {"clear", dictClear},
        };
        return methods.at(str);
    }
}
