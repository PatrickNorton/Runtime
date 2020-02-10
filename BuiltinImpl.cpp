//
// Created by Patrick Norton on 12/1/20.
//

#include "BuiltinImpl.h"
#include "StringUtils.h"


namespace BuiltinImpl {
    NullType::NullType() = default;

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
}
