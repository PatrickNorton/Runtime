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

    namespace {
        void iterImpl(const std::vector<Variable>& args, Runtime* runtime) {
            assert(args.size() == 1);
            runtime->call(args[0], Operator::ITER, {});
        }

        void newStopIteration(const std::vector<Variable>& args, Runtime* runtime) {
            assert(args.empty());
            runtime->push(std::make_shared<Constants::Exception>("", stopIteration()));
        }
    }

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
        static Constants::Constant instance = std::make_shared<Constants::Function>(iterImpl);
        return instance;
    }

    Type stopIteration() {
        class StopIterType : public Constants::_Type {
        public:
            StopIterType() : _Type({}, {}) {
            }

            Variable operator[](std::pair<Operator, Runtime*> pair) override {
                if (pair.first == Operator::CALL) {
                    return std::make_shared<Constants::Function>(newStopIteration);
                } else {
                    throw std::runtime_error("Not implemented");
                }
            }
        };

        static Type instance = std::make_shared<StopIterType>();
        return instance;
    }

    Constants::Constant value(size_t index) {
        static std::vector<Constants::Constant> values = {
                print(),
                nullptr,  // callable
                int_(),
                str(),
                nullptr,  // bool
                range(),  // range
                nullptr,  // type
                iter(),  // iter
        };
        return values[index];
    }
}
