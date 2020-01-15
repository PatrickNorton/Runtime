//
// Created by Patrick Norton on 13/1/20.
//

#include "ConstantLoaders.h"

#include <vector>
#include "IntTools.h"
#include "Constants.h"
#include "Constant.h"
#include "ConstantBytes.h"
#include "Builtins.h"


namespace ConstantLoaders {
    Constants::Constant loadStr(const std::vector<uint8_t>& data, size_t& index) {
        auto size = IntTools::bytesTo<uint32_t>(data, index);
        index += Constants::INT_32_BYTES;
        std::vector<char> value {};
        for (uint32_t i = 0; i < size; i++) {
            unsigned char chr;
            do {
                chr = data[index++];
                value.push_back(chr);
            } while (chr >= 0b11000000);  // UTF-8 min value for continuation byte
        }
        std::shared_ptr<Constants::String> constant(new Constants::String(std::string(value.begin(), value.end())));
        return constant;
    }

    Constants::Constant loadBuiltin(const std::vector<uint8_t>& data, size_t& index) {
        auto builtinIndex = IntTools::bytesTo<uint32_t>(data, index);
        index += Constants::INT_32_BYTES;
        return Builtins::values[builtinIndex];
    }

    Constants::Constant loadInt(const std::vector<uint8_t>& data, size_t& index) {
        auto value = IntTools::bytesTo<uint32_t>(data, index);
        std::shared_ptr<Constants::IntConstant> constant(new Constants::IntConstant(value, Bigint(0)));
        index += Constants::INT_32_BYTES;
        return constant;
    }

    Constants::Constant loadBigint(const std::vector<uint8_t>& data, size_t& index) {
        auto count = IntTools::bytesTo<uint32_t>(data, index);
        index += Constants::INT_32_BYTES;
        std::vector<uint64_t> values(count / 2);
        for (uint32_t i = 0; i < count; i++) {
            auto val = IntTools::bytesTo<uint32_t>(data, index);
            if (i % 2) {
                values[i / 2] |= val;
            } else {
                values[i / 2] = static_cast<uint64_t>(val) << (unsigned) 32;
            }
            index += Constants::INT_32_BYTES;
        }
        return std::make_shared<Constants::IntConstant>(Constants::IntConstant(values, Bigint(0)));
    }
}