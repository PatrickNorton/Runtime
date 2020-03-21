//
// Created by Patrick Norton on 21/3/20.
//

#ifndef RUNTIME_INTEGER_H
#define RUNTIME_INTEGER_H

#include <cstdint>
#include <cstddef>


namespace Integer {
    uint32_t bitCount(uint32_t i);

    uint32_t numberOfLeadingZeros(uint32_t i);

    uint32_t bitLengthForInt(uint32_t n);

    uint32_t numberOfTrailingZeros(uint32_t i);
};


#endif //RUNTIME_INTEGER_H
