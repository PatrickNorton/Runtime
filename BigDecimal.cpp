//
// Created by Patrick Norton on 21/1/20.
//

#include "BigDecimal.h"

#include <utility>

BigDecimal::BigDecimal(Bigint value, size_t offset) {
    this->value = std::move(value);
    this->offset = offset;
}

Bigint BigDecimal::round() const {
    static Bigint TEN = 10_B;
    auto result = TEN;
    for (size_t i = 0; i < offset; i++) {
        result *= TEN;
    }
    return value / result;
}

std::string BigDecimal::toString() const {
    auto valueString = value.to_string();
    if (offset > 0) {
        valueString.insert(valueString.length() - offset, ".");
    }
    return valueString;
}


BigDecimal operator ""_D(const char * value) {
    std::string trueValue {value};
    assert(std::count(trueValue.begin(), trueValue.end(), '.'));
    size_t dotIndex = trueValue.find('.');
    if (dotIndex == std::string::npos) {
        return BigDecimal(Bigint(trueValue), 0);
    } else {
        std::string bigintStr = std::string(trueValue.begin(), trueValue.begin() + dotIndex)
                + std::string(trueValue.end() - dotIndex, trueValue.end());
        return BigDecimal(Bigint(bigintStr), trueValue.size() - dotIndex);
    }
}
