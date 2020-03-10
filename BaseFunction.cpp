//
// Created by Patrick Norton on 27/1/20.
//

#include "BaseFunction.h"
#include "IntTools.h"
#include "Constants.h"

#include <utility>

BaseFunction::BaseFunction() : name(), localCount(), bytes() {
}

BaseFunction::BaseFunction(std::string name, uint16_t varCount, std::vector<uint8_t> values)
    : name(std::move(name)), localCount(varCount), bytes(std::move(values)) {
}

BaseFunction BaseFunction::parse(const std::vector<uint8_t>& data, size_t& index) {
    auto nameSize = IntTools::bytesTo<uint32_t>(data, index);
    std::vector<char> value {};
    value.reserve(nameSize);
    for (uint32_t i = 0; i < nameSize; i++) {
        unsigned char chr;
        do {
            chr = data[index++];
            value.push_back(chr);
        } while (chr >= 0b11000000);  // UTF-8 min value for continuation byte
    }
    std::string name(value.begin(), value.end());

    auto varCount = IntTools::bytesTo<uint16_t>(data, index);

    auto fnSize = IntTools::bytesTo<uint32_t>(data, index);
    std::vector<uint8_t> values(data.begin() + index, data.begin() + index + fnSize);
    index += fnSize;

    return {name, varCount, values};
}

const std::string& BaseFunction::getName() const {
    return name;
}

const uint16_t& BaseFunction::getLocalCount() const {
    return localCount;
}

const std::vector<uint8_t>& BaseFunction::getBytes() const {
    return bytes;
}

uint8_t BaseFunction::operator[](size_t index) const {
    return bytes[index];
}
