//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_INTTOOLS_INL
#define RUNTIME_INTTOOLS_INL

#include "IntTools.h"
#include "Constants.h"


template<typename T>
T IntTools::bytesTo(std::vector<uint8_t> bytes) {
    constexpr size_t byteSize = Constants::bytesOf<T>;
    assert(bytes.size() == byteSize);

    T result = 0;
    for (std::size_t i = 0; i < byteSize; i++) {
        result |= (unsigned) bytes[i] << (byteSize - 1 - i) * 8;
    }

    return result;
}


template<typename T>
T IntTools::bytesTo(std::vector<uint8_t> bytes, size_t& start) {
    T result = 0;
    for (size_t i = 0; i < Constants::bytesOf<T>; i++) {
        result |= (unsigned) bytes[start + i] << (Constants::bytesOf<T> - 1 - i) * 8;
    }

    start += Constants::bytesOf<T>;

    return result;
}


template<typename T>
T IntTools::bytesTo(std::vector<uint8_t> bytes, uint32_t& start) {
    T result = 0;
    for (size_t i = 0; i < Constants::bytesOf<T>; i++) {
        result |= (unsigned) bytes[start + i] << (Constants::bytesOf<T> - 1 - i) * 8;
    }

    start += Constants::bytesOf<T>;

    return result;
}

#endif  // RUNTIME_INTTOOLS_INL
