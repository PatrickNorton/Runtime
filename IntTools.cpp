//
// Created by Patrick Norton on 12/1/20.
//

#include "IntTools.h"
#include "Constants.h"


template <>
uint32_t IntTools::bytesTo(std::vector<uint8_t> bytes) {
    constexpr std::size_t byteSize = Constants::INT_32_BYTES;
    assert(bytes.size() == byteSize);

    uint32_t result = 0;
    for (std::size_t i = 0; i < byteSize; i++) {
        result |= (unsigned) bytes[i] << (byteSize - 1 - i) * 8;
    }

    return result;
}


template <>
uint16_t IntTools::bytesTo(std::vector<uint8_t> bytes) {
    constexpr std::size_t byteSize = Constants::INT_16_BYTES;
    assert(bytes.size() == byteSize);

    uint16_t result = 0;
    for (std::size_t i = 0; i < byteSize; i++) {
        result |= (unsigned) bytes[i] << (byteSize - 1 - i) * 8;
    }

    return result;
}


template <>
uint32_t IntTools::bytesTo(std::vector<uint8_t> bytes, size_t start) {

    uint32_t result = 0;
    for (std::size_t i = start; i < start + Constants::INT_32_BYTES; i++) {
        result |= (unsigned) bytes[i] << (Constants::INT_32_BYTES - 1 - (i - start)) * 8;
    }

    return result;
}


template <>
uint16_t IntTools::bytesTo(std::vector<uint8_t> bytes, size_t start) {

    uint16_t result = 0;
    for (std::size_t i = start; i < start + Constants::INT_16_BYTES; i++) {
        result |= (unsigned) bytes[i] << (Constants::INT_16_BYTES - 1 - (i - start)) * 8;
    }

    return result;
}
