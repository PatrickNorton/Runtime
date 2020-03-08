//
// Created by Patrick Norton on 8/3/20.
//

#include "CharUtils.h"
#include "Runtime.h"
#include "StringUtils.h"
#include "Builtins.h"
#include "IntUtils.h"

namespace Constants {
    void CharType::charStr(const CharPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        runtime->push(Constants::fromNative(std::string(1, self->value)));
    }

    void CharType::charPlus(const CharPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1);
        runtime->push(Constants::fromNative(static_cast<char16_t>(self->value + args[0]->toChar(runtime))));
    }

    void CharType::charMinus(const CharPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1);
        runtime->push(Constants::fromNative(static_cast<char16_t>(self->value - args[0]->toChar(runtime))));
    }

    void CharType::charInt(const CharPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.empty());
        runtime->push(Constants::fromNative(Bigint(uint16_t(self->value))));
    }

    GenericMethod<CharConstant> CharType::charMethod(Operator op) {
        static const std::unordered_map<Operator, GenericMethod<CharConstant>> values = {
                {Operator::STR, charStr},
                {Operator::ADD, charPlus},
                {Operator::SUBTRACT, charMinus},
                {Operator::INT, charInt},
        };
        return values.at(op);
    }

    Variable CharType::createNew(const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1);
        return fromNative(args[0]->toChar(runtime));
    }

    CharConstant::CharConstant(char16_t value) : value(value) {
    }

    Type CharConstant::getType() {
        return Builtins::char_();
    }

    Variable CharConstant::operator[](std::pair<Operator, Runtime*> pair) {
        Operator op = pair.first;
        if (!methods.count(op)) {
            auto self = this_ptr<CharConstant>();
            methods[op] = std::make_shared<GenericM<CharConstant>>(std::move(self), CharType::charMethod(op));
        }
        return methods.at(op);
    }

    Constant fromNative(char16_t val) {
        return std::make_shared<CharConstant>(val);
    }
}
