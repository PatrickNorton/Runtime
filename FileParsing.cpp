//
// Created by Patrick Norton on 12/1/20.
//

#include <fstream>
#include <vector>
#include <unordered_map>
#include "FileParsing.h"
#include "IntTools.h"
#include "Constants.h"
#include "Constant.h"
#include "ConstantBytes.h"
#include "ConstantLoaders.h"
#include "Function.h"


Constants::Constant loadConstant(const std::vector<uint8_t>& data, size_t& index, std::vector<uint32_t>& functions) {
    auto constantNum = static_cast<ConstantBytes>(data[index]);
    index++;
    switch (constantNum) {
        case ConstantBytes::STR:
            return ConstantLoaders::loadStr(data, index);
        case ConstantBytes::INT:
            return ConstantLoaders::loadInt(data, index);
        case ConstantBytes::BIGINT:
            return ConstantLoaders::loadBigint(data, index);
        case ConstantBytes::DECIMAL:
            return ConstantLoaders::loadDecimal(data, index);
        case ConstantBytes::IMPORT:
            break;
        case ConstantBytes::BUILTIN:
            return ConstantLoaders::loadBuiltin(data, index);
        case ConstantBytes::FUNCTION:
            functions.push_back(ConstantLoaders::functionIndex(data, index));
            return nullptr;
        case ConstantBytes::BOOL:
            return ConstantLoaders::loadBool(data, index);
    }
    throw std::runtime_error("Unhandled constant");
}


FileInfo parseFile(const std::string& name) {
    std::ifstream inStream(name, std::ios::in | std::ios::binary);
    if (!inStream.good()) {
        throw std::runtime_error("File \"" + name + "\" not found");
    }
    std::vector<uint8_t> data((std::istreambuf_iterator<char>(inStream)), std::istreambuf_iterator<char>());
    size_t index = 0;

    auto magicNumber = IntTools::bytesTo<uint32_t>(data, index);
    index += Constants::INT_32_BYTES;
    if (magicNumber != Constants::MAGIC_NUMBER) {
        throw std::runtime_error("File does not start with the magic number");
    }

    auto importCount = IntTools::bytesTo<uint32_t>(data, index);
    index += Constants::INT_32_BYTES;
    if (importCount) {
        throw std::runtime_error("Imports not yet supported");
    }

    auto exportCount = IntTools::bytesTo<uint32_t>(data, index);
    index += Constants::INT_32_BYTES;
    if (exportCount) {
        throw std::runtime_error("Imports not yet supported");
    }

    auto constantCount = IntTools::bytesTo<uint32_t>(data, index);
    index += Constants::INT_32_BYTES;
    std::vector<Constants::Constant> constants(constantCount);
    std::vector<uint32_t>functionIndices {};
    for (uint32_t i = 0; i < constantCount; i++) {
        constants[i] = loadConstant(data, index, functionIndices);
    }

    auto functionCount = IntTools::bytesTo<uint32_t>(data, index);
    index += Constants::INT_32_BYTES;
    std::vector<std::vector<uint8_t>> functions(functionCount);
    for (uint32_t i = 0; i < functionCount; i++) {
        auto functionLength = IntTools::bytesTo<uint32_t>(data, index);
        index += Constants::INT_32_BYTES;
        functions[i] = std::vector<uint8_t>(data.begin() + index, data.begin() + index + functionLength);
        index += functionLength;
    }

    size_t fnCount = 0;
    for (auto& constant : constants) {
        if (constant == nullptr) {
            int fnIndex = functionIndices[fnCount++];
            int fnTotalIndex = 0;
            for (size_t j = 0; j < fnIndex; j++) {
                fnTotalIndex += functions[j].size();
            }
            constant = std::make_shared<Constants::StdFunction>(fnTotalIndex);
        }
    }

    return FileInfo(constants, functions);
}
