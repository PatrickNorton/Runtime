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
#include "StringUtils.h"
#include "IntUtils.h"


namespace ConstantLoaders {
    Constants::Constant loadStr(const std::vector<uint8_t>& data, size_t& index) {
        auto size = IntTools::bytesTo<uint32_t>(data, index);
        index += Constants::INT_32_BYTES;
        std::vector<char> value {};
        value.reserve(size);
        for (uint32_t i = 0; i < size; i++) {
            unsigned char chr;
            do {
                chr = data[index++];
                value.push_back(chr);
            } while (chr >= 0b11000000);  // UTF-8 min value for continuation byte
        }
        return Constants::fromNative(std::string(value.begin(), value.end()), true);
    }

    Constants::Constant loadBuiltin(const std::vector<uint8_t>& data, size_t& index) {
        auto builtinIndex = IntTools::bytesTo<uint32_t>(data, index);
        index += Constants::INT_32_BYTES;
        return Builtins::value(builtinIndex);
    }

    Constants::Constant loadInt(const std::vector<uint8_t>& data, size_t& index) {
        auto value = IntTools::bytesTo<uint32_t>(data, index);
        index += Constants::INT_32_BYTES;
        return Constants::fromNative(Bigint(value));
    }

    Constants::Constant loadBigint(const std::vector<uint8_t>& data, size_t& index) {
        auto count = IntTools::bytesTo<uint32_t>(data, index);
        index += Constants::INT_32_BYTES;
        std::vector<uint32_t> values(count);
        for (uint32_t i = 0; i < count; i++) {
            auto val = IntTools::bytesTo<uint32_t>(data, index);
            values[i] = val;
            index += Constants::INT_32_BYTES;
        }
        return Constants::fromNative(Bigint(values, false));
    }

    Constants::Constant loadDecimal(const std::vector<uint8_t> &data, size_t &index) {
        auto count = IntTools::bytesTo<uint32_t>(data, index);
        index += Constants::INT_32_BYTES;
        auto scale = IntTools::bytesTo<uint32_t>(data, index);
        index += Constants::INT_32_BYTES;
        std::vector<uint32_t> values(count);
        for (uint32_t i = 0; i < count; i++) {
            auto val = IntTools::bytesTo<uint32_t>(data, index);
            values[i] = val;
            index += Constants::INT_32_BYTES;
        }
        return Constants::fromNative(BigDecimal(Bigint(values, false), scale));
    }

    uint32_t functionIndex(const std::vector<uint8_t>& data, size_t& index) {
        auto fnIndex = IntTools::bytesTo<uint32_t>(data, index);
        index += Constants::INT_32_BYTES;
        return fnIndex;
    }

    Constants::Constant loadBool(const std::vector<uint8_t>& data, size_t& index) {
        auto value = data[index++];
        return Constants::fromNative(bool(value));
    }
}