//
// Created by Patrick Norton on 12/1/20.
//

#include "FileInfo.h"
#include "Executor.h"

#include <utility>

FileInfo::FileInfo(std::vector<Constants::Constant> constants, std::vector<std::vector<uint8_t>> functions) {
    this->constants = std::move(constants);
    this->functions = std::move(functions);
}

void FileInfo::execute() {
    auto defaultFn = functions[0];
    ::execute(defaultFn, constants);
}
