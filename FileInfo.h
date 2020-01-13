//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_FILEINFO_H
#define RUNTIME_FILEINFO_H


#include <vector>
#include "Constant.h"

class FileInfo {
private:
    std::vector<Constants::Constant> constants;
    std::vector<std::vector<uint8_t>> functions;
public:
    FileInfo(std::vector<Constants::Constant> constants, std::vector<std::vector<uint8_t>> functions);

    void execute();
};


#endif //RUNTIME_FILEINFO_H
