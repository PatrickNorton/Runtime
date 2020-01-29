//
// Created by Patrick Norton on 16/1/20.
//

#include "StringUtils.h"

#include <unordered_set>
#include <unordered_map>

#include "IntUtils.h"
#include "Runtime.h"
#include "Method.h"

namespace Constants {
    String::String(std::string value) {
        this->value = std::move(value);
    }

    std::string String::str(Runtime *) {
        return this->value;
    }

    void StringType::strAdd(const StringPtr& self, const std::vector<Variable> &args, Runtime *runtime) {
        std::string result = self->str(runtime);
        for (const auto &arg : args) {
            result += arg->str(runtime);
        }
        runtime->push(fromNative(result));
    }

    void StringType::strMul(const StringPtr& self, const std::vector<Variable> &args, Runtime *runtime) {
        assert(args.size() == 1);
        auto arg = args[0]->toInt(runtime);
        auto value = self->str(runtime);
        auto resultSize = arg * Bigint(value.size());
        if (resultSize > Bigint(std::numeric_limits<size_t>::max())) {
            throw std::runtime_error("Resulting string too big");
        }
        std::vector<char> result{};
        for (size_t i = 0; i < static_cast<size_t>(resultSize); i++) {
            result.insert(result.end(), value.begin(), value.end());
        }
        runtime->push(fromNative(std::string(result.begin(), result.end())));
    }

    void StringType::strBool(const StringPtr& self, const std::vector<Variable> &args, Runtime *runtime) {
        assert(args.empty());
        runtime->push(fromNative(!self->str(runtime).empty()));
    }

    void StringType::pushSelf(const StringPtr& self, const std::vector<Variable> &args, Runtime *runtime) {
        assert(args.empty());
        runtime->push(self);
    }

    GenericMethod<String> StringType::strMethod(Operator o) {
        static const std::unordered_map<Operator, GenericMethod<String>> strOperators {
                {Operator::ADD,      strAdd},
                {Operator::MULTIPLY, strMul},
                {Operator::BOOL,     strBool},
                {Operator::STR,      pushSelf},
        };
        return strOperators.at(o);
    }

    StringType::StringType() : _Type({}, {}) {
    }

    Variable String::operator[](std::pair<Operator, Runtime *> pair) {
        Operator op = pair.first;
        if (!methods.count(op)) {
            auto self = std::dynamic_pointer_cast<String>(shared_from_this());
            methods[op] = std::make_shared<GenericM<String>>(std::move(self), StringType::strMethod(op));
        }
        return methods.at(op);
    }

    Constant fromNative(const std::string &val) {
        return fromNative(val, false);
    }

    Constant fromNative(const std::string &val, bool intern) {
        static std::unordered_map<std::string, Constant> interns{};
        if (interns.count(val)) {
            return interns[val];
        } else {
            if (intern) {
                interns[val] = std::make_shared<String>(val);
                return interns[val];
            } else {
                return std::make_shared<String>(val);
            }
        }
    }
}
