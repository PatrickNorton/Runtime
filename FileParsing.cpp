//
// Created by Patrick Norton on 12/1/20.
//

#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include "FileParsing.h"
#include "IntTools.h"
#include "Constants.h"
#include "Constant.h"
#include "ConstantBytes.h"
#include "ConstantLoaders.h"
#include "Function.h"
#include "BaseFunction.h"
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
            std::vector<uint32_t>& functions, std::vector<uint32_t>& classes,
            const std::vector<Constants::Constant>& imports) {
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
                return imports[IntTools::bytesTo<uint32_t>(data, index)];
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


FileInfo* parseFile(const std::string& name) {
    std::ifstream inStream(name, std::ios::in | std::ios::binary);
    auto thisFile = new FileInfo({}, {});  // Temporary file pointer, made correct at the end of the file
    if (!inStream.good()) {
        throw std::runtime_error("File \"" + name + "\" not found");
    }
    std::vector<uint8_t> data((std::istreambuf_iterator<char>(inStream)), std::istreambuf_iterator<char>());
    size_t index = 0;

    auto magicNumber = IntTools::bytesTo<uint32_t>(data, index);
    if (magicNumber != Constants::MAGIC_NUMBER) {
        throw std::runtime_error("File does not start with the magic number");
    }

    auto importCount = IntTools::bytesTo<uint32_t>(data, index);
    static std::unordered_map<std::string, FileInfo*> files {};
    std::vector<Constants::Constant> imports(importCount);
    if (importCount) {
        for (uint32_t i = 0; i < importCount; i++) {
            auto usedName = ConstantLoaders::loadStr(data, index)->str(nullptr);
            auto fullName = ConstantLoaders::loadStr(data, index)->str(nullptr);
            std::vector<std::string> names{};
            std::istringstream nameStream(fullName);
            std::string result;
            while (std::getline(nameStream, result, '.')) {
                names.push_back(result);
            }
            auto parentFolder = std::string(name.begin(), name.begin() + name.find_last_of('/'));
            auto fileName = parentFolder + "/" + names[0] + ".nbyte";
            auto otherFile = files.count(fileName) ? files.at(fileName) : parseFile(fileName);
            imports[i] = otherFile->getExport(names[1]);  //  TODO: Get nested dots
        }
    }

    auto exportCount = IntTools::bytesTo<uint32_t>(data, index);
    std::unordered_map<std::string, uint32_t> exports {};
    if (exportCount) {
        for (int i = 0; i < exportCount; i++) {
            auto exportName = ConstantLoaders::loadStr(data, index)->str(nullptr);
            auto constNo = IntTools::bytesTo<uint32_t>(data, index);
            exports[exportName] = constNo;
        }
    }

    auto constantCount = IntTools::bytesTo<uint32_t>(data, index);
    std::vector<Constants::Constant> constants(constantCount);
    std::vector<uint32_t> functionIndices {};
    std::vector<uint32_t> classIndices {};
    for (uint32_t i = 0; i < constantCount; i++) {
        constants[i] = loadConstant(data, index, functionIndices, classIndices, imports);
    }

    auto functionCount = IntTools::bytesTo<uint32_t>(data, index);
    std::vector<BaseFunction> functions(functionCount);
    for (uint32_t i = 0; i < functionCount; i++) {
        functions[i] = BaseFunction::parse(data, index);
    }

    auto classCount = IntTools::bytesTo<uint32_t>(data, index);
    std::vector<Constants::Constant> classes(classCount);
    for (auto& cls : classes) {
        cls = ConstantLoaders::loadClass(thisFile, data, index, functions);
    }

    size_t fnCount = 0, clsCount = 0;
    for (auto& constant : constants) {
        if (constant == tempFn()) {
            constant = std::make_shared<Constants::StdFunction>(thisFile, functionIndices[fnCount++]);
        } else if (constant == tempClass()) {
            constant = classes[clsCount++];
        }
    }

    *thisFile = {name, constants, functions, exports};
    files[name] = thisFile;
    return thisFile;
}
