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
    Runtime runtime(this);
    Executor::execute(runtime);
}

const std::vector<Constants::Constant>& FileInfo::getConstants() const {
    return constants;
}

const std::vector<BaseFunction>& FileInfo::getFunctions() const {
    return functions;
}

FileInfo::FileInfo(std::string name, std::vector<Constants::Constant> constants, std::vector<BaseFunction> functions,
                   std::unordered_map<std::string, uint32_t> exports)
                   : name(std::move(name)), constants(std::move(constants)), functions(std::move(functions)), exports(std::move(exports)) {
}

Constants::Constant FileInfo::getExport(const std::string& exportName) const {
    return constants[exports.at(exportName)];
}
