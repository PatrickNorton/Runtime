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
    T bytesTo(std::vector<uint8_t> bytes, size_t start);
}

#endif //RUNTIME_INTTOOLS_H
