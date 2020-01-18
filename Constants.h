//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_CONSTANTS_H
#define RUNTIME_CONSTANTS_H

#include <cstddef>
#include <cstdint>

namespace Constants {  // TODO: Change namespace to not conflict with constant types
    constexpr const size_t INT_8_BITS = std::numeric_limits<uint8_t>::digits;
    constexpr const size_t INT_16_BITS = std::numeric_limits<uint16_t>::digits;
    constexpr const size_t INT_32_BITS = std::numeric_limits<uint32_t >::digits;

    constexpr const size_t INT_32_BYTES = INT_32_BITS/INT_8_BITS;
    constexpr const size_t INT_16_BYTES = INT_16_BITS/INT_8_BITS;
    constexpr const uint32_t MAGIC_NUMBER = 0x0ABADE66;
}

#endif //RUNTIME_CONSTANTS_H
