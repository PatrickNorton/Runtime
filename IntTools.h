//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_INTTOOLS_H
#define RUNTIME_INTTOOLS_H

#include <cstdint>
#include <vector>

namespace IntTools {
    template <typename T>
    T bytesTo(std::vector<uint8_t> bytes);

    template <typename T>
    T bytesTo(std::vector<uint8_t> bytes, size_t& start);

    template <typename T>
    T bytesTo(std::vector<uint8_t> bytes, uint32_t& start);
}

#include "IntTools.inl"

#endif //RUNTIME_INTTOOLS_H
