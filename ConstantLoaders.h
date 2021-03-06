//
// Created by Patrick Norton on 13/1/20.
//

#ifndef RUNTIME_CONSTANTLOADERS_H
#define RUNTIME_CONSTANTLOADERS_H


#include <vector>
#include "Constant.h"
#include "BaseFunction.h"
#include "FileInfo.h"


namespace ConstantLoaders {
    Constants::Constant loadStr(const std::vector<uint8_t>& data, size_t& index);
    Constants::Constant loadBuiltin(const std::vector<uint8_t>& data, size_t& index);
    Constants::Constant loadInt(const std::vector<uint8_t>& data, size_t& index);
    Constants::Constant loadBigint(const std::vector<uint8_t>& data, size_t& index);
    Constants::Constant loadDecimal(const std::vector<uint8_t>& data, size_t& index);
    uint32_t functionIndex(const std::vector<uint8_t>& data, size_t& index);
    uint32_t classIndex(const std::vector<uint8_t>& data, size_t& index);
    Constants::Constant loadBool(const std::vector<uint8_t>& data, size_t& index);
    Type loadClass(FileInfo*, const std::vector<uint8_t>& data, size_t& index, std::vector<BaseFunction>&);
    std::string loadStdStr(const std::vector<uint8_t>& data, size_t& index);
}


#endif //RUNTIME_CONSTANTLOADERS_H
