//
// Created by Patrick Norton on 11/1/20.
//

#include <vector>
#include "Builtins.h"
#include "BuiltinImpl.h"
#include "IntUtils.h"
#include "StringUtils.h"
#include "Exception.h"
#include "Range.h"
#include "Runtime.h"


namespace Builtins {
    Type int_() {
        static Type instance = std::make_shared<Constants::IntType>();
        return instance;
    }

    Type str() {
        static Type instance = std::make_shared<Constants::StringType>();
        return instance;
    }

    Constants::Constant null() {
        return Constants::null();
    }

    Constants::Constant print() {
        static Constants::Constant instance = std::make_shared<Constants::Function>(BuiltinImpl::print);
        return instance;
    }

    Type range() {
        static Type instance = std::make_shared<Constants::RangeType>();
        return instance;
    }

    Constants::Constant iter() {
        static Constants::Constant instance = std::make_shared<Constants::Function>(BuiltinImpl::iter);
        return instance;
    }

    Constants::Constant input() {
        static Constants::Constant instance = std::make_shared<Constants::Function>(BuiltinImpl::input);
        return instance;
    }

    Type bool_() {
        static Type instance = std::make_shared<Constants::BoolType>();
        return instance;
    }

    Type stopIteration() {
        static Type instance = std::make_shared<BuiltinImpl::StopIteration>();
        return instance;
    }

    Constants::Constant value(size_t index) {
        static std::vector<Constants::Constant> values = {
                print(),
                nullptr,  // callable
                int_(),
                str(),
                bool_(),  // bool
                range(),
                nullptr,  // type
                iter(),
                input(),
        };
        return values[index];
    }
}
