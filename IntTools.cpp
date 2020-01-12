//
// Created by Patrick Norton on 12/1/20.
//

#include "IntTools.h"


template <>
uint32_t IntTools::bytesTo(std::vector<uint8_t> bytes) {
    constexpr std::size_t byteSize = 32 / 8;
    assert(bytes.size() == byteSize);

    uint32_t result = 0;
    for (std::size_t i = 0; i < byteSize; i++) {
        result |= (unsigned) bytes[i] << (byteSize - 1 - i) * 8;
    }

    return result;
}


template <>
uint16_t IntTools::bytesTo(std::vector<uint8_t> bytes) {
    constexpr std::size_t byteSize = 16 / 8;
    assert(bytes.size() == byteSize);

    uint16_t result = 0;
    for (std::size_t i = 0; i < byteSize; i++) {
        result |= (unsigned) bytes[i] << (byteSize - 1 - i) * 8;
    }

    return result;
}
