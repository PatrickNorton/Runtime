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
#include "BaseFunction.h"
#include "Callable.h"
#include "Type.h"


namespace {
    Constants::Constant tempFn() {
        class TempFn : public Constants::_Constant {};
        static auto instance = std::make_shared<TempFn>();
        return instance;
    }

    Constants::Constant tempClass() {
        class TempClass : public Constants::_Constant {};
        static auto instance = std::make_shared<TempClass>();
        return instance;
    }

    Constants::Constant loadConstant(const std::vector<uint8_t>& data, size_t& index,
            std::vector<uint32_t>& functions, std::vector<uint32_t>& classes) {
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
                return tempFn();
            case ConstantBytes::BOOL:
                return ConstantLoaders::loadBool(data, index);
            case ConstantBytes::CLASS:
                classes.push_back(ConstantLoaders::classIndex(data, index));
                return tempClass();
        }
        throw std::runtime_error("Unhandled constant");
    }
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
    std::vector<uint32_t> functionIndices {};
    std::vector<uint32_t> classIndices {};
    for (uint32_t i = 0; i < constantCount; i++) {
        constants[i] = loadConstant(data, index, functionIndices, classIndices);
    }

    auto functionCount = IntTools::bytesTo<uint32_t>(data, index);
    index += Constants::INT_32_BYTES;
    std::vector<BaseFunction> functions(functionCount);
    for (uint32_t i = 0; i < functionCount; i++) {
        functions[i] = BaseFunction::parse(data, index);
    }

    auto classCount = IntTools::bytesTo<uint32_t>(data, index);
    index += Constants::INT_32_BYTES;
    std::vector<Constants::Constant> classes(classCount);
    for (auto& cls : classes) {
        cls = ConstantLoaders::loadClass(data, index, functions);
    }

    size_t fnCount = 0, fnTotalIndex = 0, clsCount = 0;
    for (auto& constant : constants) {
        if (constant == tempFn()) {
            fnTotalIndex += functionIndices[fnCount++];
            constant = std::make_shared<Constants::StdFunction>(fnTotalIndex);
        } else if (constant == tempClass()) {
            constant = classes[clsCount++];
        }
    }

    return FileInfo(constants, functions);
}
