//
// Created by Patrick Norton on 13/1/20.
//

#include "ConstantLoaders.h"

#include <vector>
#include "IntTools.h"
#include "ConstantBytes.h"
#include "Builtins.h"
#include "StringUtils.h"
#include "IntUtils.h"
#include "StdVariable.h"


namespace ConstantLoaders {
    namespace {
        std::string getStr(const std::vector<uint8_t>& data, size_t& index) {
            auto size = IntTools::bytesTo<uint32_t>(data, index);
            std::vector<char> value {};
            value.reserve(size);
            for (uint32_t i = 0; i < size; i++) {
                unsigned char chr;
                do {
                    chr = data[index++];
                    value.push_back(chr);
                } while (chr >= 0b11000000);  // UTF-8 min value for continuation byte
            }
            return {value.begin(), value.end()};
        }
    }

    Constants::Constant loadStr(const std::vector<uint8_t>& data, size_t& index) {
        return Constants::fromNative(getStr(data, index), true);
    }

    Constants::Constant loadBuiltin(const std::vector<uint8_t>& data, size_t& index) {
        auto builtinIndex = IntTools::bytesTo<uint32_t>(data, index);
        return Builtins::value(builtinIndex);
    }

    Constants::Constant loadInt(const std::vector<uint8_t>& data, size_t& index) {
        auto value = IntTools::bytesTo<uint32_t>(data, index);
        return Constants::fromNative(Bigint(value));
    }

    Constants::Constant loadBigint(const std::vector<uint8_t>& data, size_t& index) {
        auto count = IntTools::bytesTo<uint32_t>(data, index);
        std::vector<uint32_t> values(count);
        for (uint32_t i = 0; i < count; i++) {
            auto val = IntTools::bytesTo<uint32_t>(data, index);
            values[i] = val;
        }
        return Constants::fromNative(Bigint(values, false));
    }

    Constants::Constant loadDecimal(const std::vector<uint8_t> &data, size_t &index) {
        auto count = IntTools::bytesTo<uint32_t>(data, index);
        auto scale = IntTools::bytesTo<uint32_t>(data, index);
        std::vector<uint32_t> values(count);
        for (uint32_t i = 0; i < count; i++) {
            auto val = IntTools::bytesTo<uint32_t>(data, index);
            values[i] = val;
        }
        return Constants::fromNative(BigDecimal(Bigint(values, false), scale));
    }

    uint32_t functionIndex(const std::vector<uint8_t>& data, size_t& index) {
        auto fnIndex = IntTools::bytesTo<uint32_t>(data, index);
        return fnIndex;
    }

    uint32_t classIndex(const std::vector<uint8_t>& data, size_t& index) {
        auto clsIndex = IntTools::bytesTo<uint32_t>(data, index);
        return clsIndex;
    }

    Constants::Constant loadBool(const std::vector<uint8_t>& data, size_t& index) {
        auto value = data[index++];
        return Constants::fromNative(bool(value));
    }

    namespace {
        std::map<Operator, uint32_t> getOperators(const std::vector<uint8_t>& data, size_t& index,
                                                  std::vector<BaseFunction>& functions) {
            std::map<Operator, uint32_t> operators {};
            auto byteSize = IntTools::bytesTo<uint32_t>(data, index);
            for (uint32_t i = 0; i < byteSize; i++) {
                auto op = static_cast<Operator>(data[index++]);
                auto methodSize = IntTools::bytesTo<uint32_t>(data, index);
                std::vector<uint8_t> values(data.begin() + index, data.begin() + index + methodSize);
                index += methodSize;
                operators[op] = functions.size();
                functions.emplace_back("", 0, values);
            }
            return operators;
        }

        std::map<std::string, uint32_t> getMethods(const std::vector<uint8_t>& data, size_t& index,
                                                   std::vector<BaseFunction>& functions) {
            std::map<std::string, uint32_t> methods {};
            auto byteSize = IntTools::bytesTo<uint32_t>(data, index);
            for (uint32_t i = 0; i < byteSize; i++) {
                auto name = getStr(data, index);
                auto methodSize = IntTools::bytesTo<uint32_t>(data, index);
                std::vector<uint8_t> values(data.begin() + index, data.begin() + index + methodSize);
                index += methodSize;
                methods[name] = functions.size();
                functions.emplace_back(name, 0, values);
            }
            return methods;
        }
    }

    Type loadClass(const std::vector<uint8_t>& data, size_t& index, std::vector<BaseFunction>& functions) {
        auto name = loadStr(data, index);
        if (IntTools::bytesTo<uint32_t>(data, index) != 0) { // No supers allowed yet
            throw std::runtime_error("Supers not allowed yet");
        }
        auto genericSize = IntTools::bytesTo<uint16_t>(data, index);
        auto operators = getOperators(data, index, functions);
        auto staticOperators = getOperators(data, index, functions);
        auto methods = getMethods(data, index, functions);
        auto staticMethods = getMethods(data, index, functions);

        return std::make_shared<Constants::StdType>(genericSize, operators, staticOperators, methods, staticMethods);
    }
}