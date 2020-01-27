//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_FILEINFO_H
#define RUNTIME_FILEINFO_H


#include <vector>
#include "Constant.h"
#include "BaseFunction.h"

class FileInfo {
private:
    std::vector<Constants::Constant> constants;
    std::vector<BaseFunction> functions;
public:
    FileInfo(std::vector<Constants::Constant> constants, std::vector<BaseFunction> functions);

    void execute();
};


#endif //RUNTIME_FILEINFO_H
