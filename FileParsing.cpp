//
// Created by Patrick Norton on 12/1/20.
//

#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "FileParsing.h"
#include "IntTools.h"
#include "Constants.h"
#include "Constant.h"
#include "ConstantBytes.h"


namespace ConstantLoaders {
    Constants::Constant loadStr(const std::vector<uint8_t>& data, size_t& index) {
        auto size = IntTools::bytesTo<uint32_t>(data, index);
        index += Constants::INT_32_BYTES;
        std::vector<char> value(size);
        for (uint32_t i = 0; i < size; i++) {
            unsigned char chr;
            do {
                chr = data[index++];
                value.push_back(chr);
            } while (chr >= 0b11000000);
        }
        std::unique_ptr<Constants::String> constant(new Constants::String(std::string(value.begin(), value.end())));
        return constant;
    }

}


Constants::Constant loadConstant(const std::vector<uint8_t>& data, size_t& index) {
    auto constantNum = static_cast<ConstantBytes>(data[index]);
    index++;
    switch (constantNum) {
        case ConstantBytes::STR:
            return ConstantLoaders::loadStr(data, index);
        case ConstantBytes::INT:
            break;
        case ConstantBytes::BIGINT:
            break;
        case ConstantBytes::DECIMAL:
            break;
        case ConstantBytes::IMPORT:
            break;
        case ConstantBytes::BUILTIN:
            break;
        case ConstantBytes::FUNCTION:
            break;
    }
    throw std::runtime_error("Unhandled constant");
}


FileInfo parseFile(const std::string& name) {
    std::ifstream inStream(name, std::ios::in | std::ios::binary);
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
    for (uint32_t i = 0; i < constantCount; i++) {
        constants[i] = loadConstant(data, index);
    }

    auto functionCount = IntTools::bytesTo<uint32_t>(data, index);
    index += Constants::INT_32_BYTES;
    std::vector<std::vector<uint8_t>> functions(functionCount);
    for (uint32_t i = 0; i < functionCount; i++) {
        auto functionLength = IntTools::bytesTo<uint32_t>(data, index);
        functions[i] = std::vector<uint8_t>(data[index], data[index + functionLength]);
        index += functionLength;
    }

    return FileInfo(constants, functions);
}
