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


