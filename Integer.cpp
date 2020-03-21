//
// Created by Patrick Norton on 21/3/20.
//

#include "Integer.h"

namespace Integer {
    uint32_t bitCount(uint32_t i) {
        i = i - (i >> 1u & 0x55555555u);
        i = (i & 0x33333333u) + (i >> 2u & 0x33333333u);
        i = i + (i >> 4u) & 0x0f0f0f0fu;
        i = i + (i >> 8u);
        i = i + (i >> 16u);
        return i & 0x3fu;
    }

    uint32_t numberOfLeadingZeros(uint32_t i) {
        if (i <= 0)
            return i == 0 ? 32 : 0;
        size_t n = 31;
        if (i >= 1u << 16u) {
            n -= 16;
            i >>= 16u;
        }
        if (i >= 1u << 8u) {
            n -=  8;
            i >>= 8u;
        }
        if (i >= 1u << 4u) {
            n -=  4;
            i >>=  4u;
        }
        if (i >= 1u << 2u) {
            n -=  2;
            i >>=  2u;
        }
        return n - (i >> 1u);
    }

    uint32_t bitLengthForInt(uint32_t n) {
        return 32 - numberOfLeadingZeros(n);
    }

    uint32_t numberOfTrailingZeros(uint32_t i) {
        i = ~i & (i - 1);
        if (i <= 0) return i & 32u;
        size_t n = 1;
        if (i > 1u << 16u) {
            n += 16;
            i >>= 16u;
        }
        if (i > 1u << 8u) {
            n +=  8;
            i >>= 8u;
        }
        if (i > 1u << 4u) {
            n +=  4;
            i >>= 4u;
        }
        if (i > 1u << 2u) {
            n +=  2;
            i >>= 2u;
        }
        return n + (i >> 1u);
    }
}