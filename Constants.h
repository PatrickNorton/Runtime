//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_CONSTANTS_H
#define RUNTIME_CONSTANTS_H

#include <cstddef>
#include <cstdint>

namespace Constants {  // TODO: Change namespace to not conflict with constant types
    template<typename T>
    constexpr const size_t bytesOf = std::numeric_limits<T>::digits / std::numeric_limits<uint8_t>::digits;

    constexpr const uint32_t MAGIC_NUMBER = 0x0ABADE66;

}

#endif //RUNTIME_CONSTANTS_H
