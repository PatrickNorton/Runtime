//
// Created by Patrick Norton on 12/1/20.
//

#include "FileInfo.h"
#include "Executor.h"

#include <utility>

FileInfo::FileInfo(std::vector<Constants::Constant> constants, std::vector<BaseFunction> functions) {
    this->constants = std::move(constants);
    this->functions = std::move(functions);
}

void FileInfo::execute() {
    Runtime runtime(constants, functions);
    Executor::execute(runtime);
}
