//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_EXECUTOR_H
#define RUNTIME_EXECUTOR_H

#include "Bytecode.h"
#include "Runtime.h"

namespace Executor {
    void parse(const std::vector<uint8_t> &bytes, const Runtime &runtime);

    void execute(Runtime&);
}

#endif //RUNTIME_EXECUTOR_H
