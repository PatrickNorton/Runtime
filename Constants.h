//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_CONSTANTS_H
#define RUNTIME_CONSTANTS_H

#include <cstddef>
#include <cstdint>

namespace Constants {
    constexpr const size_t INT_32_BYTES = 32/8;
    constexpr const size_t INT_16_BYTES = 16/8;
    constexpr const uint32_t MAGIC_NUMBER = 0x0ABADE66;
}

#endif //RUNTIME_CONSTANTS_H
