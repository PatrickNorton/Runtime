//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_FILEINFO_H
#define RUNTIME_FILEINFO_H


#include <vector>
#include <unordered_map>
#include "Constant.h"
#include "BaseFunction.h"

class FileInfo {
private:
    std::string name;
    std::vector<Constants::Constant> constants;
    std::vector<BaseFunction> functions;
    std::unordered_map<std::string, uint32_t> exports;
public:
    FileInfo(std::string, std::vector<Constants::Constant>, std::vector<BaseFunction>, std::unordered_map<std::string, uint32_t>);
    FileInfo(std::vector<Constants::Constant> constants, std::vector<BaseFunction> functions);
    const std::vector<Constants::Constant>& getConstants() const;
    const std::vector<BaseFunction>& getFunctions() const;
    Constants::Constant getExport(const std::string&) const;

    void execute();
};


#endif //RUNTIME_FILEINFO_H
