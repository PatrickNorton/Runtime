//
// Created by Patrick Norton on 11/1/20.
//

#include <vector>
#include "Builtins.h"
#include "BuiltinImpl.h"
#include "IntUtils.h"
#include "StringUtils.h"
#include "Exception.h"


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

    Variable stopIteration() {
        static Variable instance = std::make_shared<Constants::Exception>("");
        return instance;
    }

    Constants::Constant value(size_t index) {
        static std::vector<Constants::Constant> values = {
                print(),
                nullptr,  // callable
                int_(),
                str(),
                nullptr,  // bool
                nullptr,  // range
                nullptr,  // type
                nullptr,  // iter
        };
        return values[index];
    }
}
