//
// Created by Patrick Norton on 22/1/20.
//

#include "Function.h"
#include "StringUtils.h"
#include <utility>

Constants::StdFunction::StdFunction(FileInfo* info, uint32_t index) : info(info), index(index) {
}

Constants::StdFunction::StdFunction(FileInfo* info, uint32_t index, FramePtr frame)
: info(info), index(index), frame(std::move(frame)) {
}

void Constants::StdFunction::operator()(const std::vector<Variable>& args, Runtime* runtime) {
    if (frame == nullptr) {
        runtime->call(index, info, args);
    } else {
        runtime->call(index, info, args, frame);
    }
}

Variable Constants::StdFunction::operator[](std::pair<std::string, Runtime*>) {
    throw std::runtime_error("Value not supported");
}

Variable Constants::StdFunction::operator[](std::pair<Operator, Runtime*> pair) {
    Operator op = pair.first;
    switch (op) {
        case Operator::CALL:
            return shared_from_this();
        case Operator::STR:
            return std::make_shared<GenericM<StdFunction>>(this_ptr<StdFunction>(), fnStr);
        default:
            throw std::runtime_error("Operator not supported");
    }
}

void Constants::StdFunction::fnStr(const FnPtr& self, const std::vector<Variable>& args, Runtime* runtime) {
    assert(args.empty());
    runtime->push(Constants::fromNative(runtime->fnName(self->index)));
}
