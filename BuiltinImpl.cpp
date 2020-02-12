//
// Created by Patrick Norton on 12/1/20.
//

#include "BuiltinImpl.h"
#include "StringUtils.h"
#include "Exception.h"


namespace BuiltinImpl {

    std::string NullType::str(Runtime *) {
        return "null";
    }

    void print(const std::vector<Variable> &args, Runtime* runtime) {
        for (const auto& arg : args) {
            std::cout << arg->str(runtime) << std::endl;
        }
    }

    void input(const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1);
        std::cout << args[0]->str(runtime) << std::flush;
        std::string result;
        std::getline(std::cin, result);
        runtime->push(Constants::fromNative(result));
    }

    void iter(const std::vector<Variable>& args, Runtime* runtime) {
        assert(args.size() == 1);
        runtime->call(args[0], Operator::ITER, {});
    }

    Variable StopIteration::operator[](std::pair<Operator, Runtime*> pair) {
        if (pair.first == Operator::CALL) {
            return std::make_shared<Constants::Function>(create);
        } else {
            throw std::runtime_error("Not implemented");
        }
    }

    Variable StopIteration::createNew(const std::vector<Variable>& args, Runtime*) {
        assert(args.empty());
        return std::make_shared<Constants::Exception>("", Builtins::stopIteration());
    }

    void StopIteration::create(const std::vector<Variable>& args, Runtime* runtime) {
        runtime->push(Builtins::stopIteration()->createNew(args, runtime));
    }

    void ValueError::create(const std::vector<Variable>& args, Runtime* runtime) {
        runtime->push(Builtins::valueError()->createNew(args, runtime));
    }

    Variable ValueError::operator[](std::pair<Operator, Runtime*> pair) {
        if (pair.first == Operator::CALL) {
            return std::make_shared<Constants::Function>(create);
        } else {
            throw std::runtime_error("Not implemented");
        }
    }

    Variable ValueError::createNew(const std::vector<Variable>& args, Runtime* runtime) {
        return std::make_shared<Constants::Exception>("", Builtins::valueError());
    }


}
