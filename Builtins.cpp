//
// Created by Patrick Norton on 11/1/20.
//

#include <vector>
#include "Builtins.h"
#include "BuiltinImpl.h"
#include "IntUtils.h"
#include "StringUtils.h"


namespace Builtins {

    Type int_() {
        static Type instance = std::make_shared<Constants::IntType>();
        return instance;
    }

    Variable str() {
        static Type instance = std::make_shared<Constants::StringType>();
        return instance;
    }

    Variable null() {
        return Constants::null();
    }

    Constants::Constant print() {
        static Constants::Constant instance = std::make_shared<Constants::Function>(BuiltinImpl::print);
        return instance;
    }

    Constants::Constant value(size_t index) {
        static std::vector<Constants::Constant> values = {
                print()
        };
        return values[index];
    }
}
