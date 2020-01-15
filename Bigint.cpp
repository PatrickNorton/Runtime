//
// Created by Patrick Norton on 14/1/20.
//

#include "Bigint.h"

Bigint::Bigint() {
    sign = false;
    values = {0};
}

Bigint::Bigint(int64_t value) {  // FIXME: Get casting right
    if (value < 0) {
        sign = true;
        values = {static_cast<uint32_t>(-value)};
    } else {
        sign = false;
        values = {static_cast<uint32_t>(value)};
    }
}

Bigint::Bigint(int value) {  // FIXME: Get casting right
    if (value < 0) {
        sign = true;
        values = {static_cast<uint32_t>(-value)};
    } else {
        sign = false;
        values = {static_cast<uint32_t>(value)};
    }
}

Bigint::Bigint(uint64_t value) {
    sign = false;
    if (value < std::numeric_limits<uint32_t>::max()) {
        values = {static_cast<uint32_t>(value)};
    } else {
        values = {static_cast<uint32_t>(value), static_cast<uint32_t>(value << (unsigned) 32)};
    }
}

Bigint::Bigint(std::vector<uint32_t> values, bool sign) {
    this->values = std::move(values);
    this->sign = sign;
}

Bigint Bigint::operator+(const Bigint& other) const {
    if (!*this) {
        return other;
    } else if (!other) {
        return *this;
    }
    auto cmp = compareMagnitude(other);
    if (sign == other.sign) {
        return Bigint(add(values, other.values), sign);
    } else {
        if (cmp == 0) {
            return Bigint(0);
        } else if (cmp > 0) {
            return Bigint(sub(values, other.values), sign);
        } else {  // cmp < 0
            return Bigint(sub(other.values, values), other.sign);
        }
    }
}

Bigint Bigint::operator-(const Bigint& other) const {
    if (!other) {
        return *this;
    }
    if (!*this) {
        return -other;
    }
    if (other.sign != sign) {
        return Bigint(add(values, other.values), sign);
    }
    auto cmp = compareMagnitude(other);
    if (cmp == 0) {
        return Bigint(0);
    } else if (cmp > 0) {
        return Bigint(sub(values, other.values), sign);
    } else {  // cmp < 0
        return Bigint(sub(other.values, values), other.sign);
    }
}

Bigint Bigint::operator*(const Bigint& other) const {
    if (!*this || !other) {
        return Bigint(0);
    }
    bool resultSign = sign == other.sign;
    return Bigint(mul(values, other.values), resultSign);
}

Bigint Bigint::operator/(const Bigint& other) const {
    if (*this == other) {
        return Bigint(sign == other.sign ? 1 : -1);
    } else if (other > *this) {
        return Bigint(0);
    } else {
        return Bigint(div(values, other.values), sign == other.sign);
    }
}

Bigint Bigint::operator^(const Bigint& other) const {
    __vec result(std::max(values.size(), other.values.size()));
    for (size_t i = 0; i < result.size(); i++) {
        result[i] = (getInt(result.size() - i - 1)
                     ^ other.getInt(result.size() - i - 1));
    }
    return valueOf(result);
}

Bigint Bigint::operator|(const Bigint& other) const {
    __vec result(std::max(values.size(), other.values.size()));
    for (size_t i = 0; i < result.size(); i++) {
        result[i] = (getInt(result.size() - i - 1)
                     | other.getInt(result.size() - i - 1));
    }
    return valueOf(result);
}

Bigint Bigint::operator&(const Bigint& other) const {
    __vec result(std::max(values.size(), other.values.size()));
    for (size_t i = 0; i < result.size(); i++) {
        result[i] = (getInt(result.size() - i - 1)
                     & other.getInt(result.size() - i - 1));
    }
    return valueOf(result);
}

Bigint Bigint::operator~() const {
    return (-*this) - Bigint(1);
}

Bigint Bigint::operator<<(const size_t& other) const {
    if (!*this) {
        return Bigint(0);
    }
    if (other == 0) {
        return *this;
    }
    constexpr auto intBytes = std::numeric_limits<uint32_t>::digits;
    __vec result(values);
    size_t wholeShifts = other / intBytes;
    __vec shifts(wholeShifts);
    result.insert(values.end(), shifts.begin(), shifts.end());
    size_t remainder = other % intBytes;
    if (remainder) {
        bool carry = (result[0] >> remainder) == 0;
        size_t r2size = carry ? values.size() : values.size() + 1;
        __vec result2(r2size);
        if (carry) {
            result2[0] = result[0] >> remainder;
        }
        for (size_t i = 0; i < result.size(); i++) {
            result2[i + carry] = (result[i] << remainder) | (result[i+1] >> remainder);
        }
        return Bigint(result2, sign);
    } else {
        return Bigint(result, sign);
    }
}

Bigint Bigint::operator>>(const size_t& other) const {
    if (!*this) {
        return Bigint(0);
    }
    if (other == 0) {
        return *this;
    }
    constexpr auto intBytes = std::numeric_limits<uint32_t>::digits;
    __vec result(values);
    if (other > values.size() * intBytes) {
        return Bigint(0);
    }
    size_t wholeShifts = other / intBytes;
    result.erase(result.end() - wholeShifts, result.end());
    size_t remainder = other % intBytes;
    if (remainder) {
        __vec result2(result.size());
        result2[0] = result[0] >> remainder;
        for (size_t i = 1; i < result.size(); i++) {
            result2[i] = result[i - 1] << remainder | result[i] >> remainder;
        }
        if (result2[0] == 0) {
            result2.erase(result2.begin(), result2.begin() + 1);
        }
        return Bigint(result2, sign);
    } else {
        return Bigint(result, sign);
    }
}

bool Bigint::operator==(const Bigint& other) const {
    if (!*this && !other) {
        return true;
    }
    return sign == other.sign && compareMagnitude(other) == 0;
}

bool Bigint::operator!=(const Bigint& other) const {
    return !operator==(other);
}

Bigint Bigint::operator-() const {
    return Bigint(values, !sign);
}

Bigint::operator bool() const {
    for (auto i : values) {
        if (i) return true;
    }
    return false;
}

bool Bigint::operator>(const Bigint& other) const {
    if (sign != other.sign) {
        return !sign;
    }
    auto cmp = compareMagnitude(other);
    return (cmp > 0) ^ sign;
}

bool Bigint::operator<(const Bigint& other) const {
    if (sign != other.sign) {
        return sign;
    }
    auto cmp = compareMagnitude(other);
    return (cmp < 0) ^ sign;
}

Bigint::__vec Bigint::add(const Bigint::__vec& x, const Bigint::__vec& y) {
    return x.size() >= y.size() ? _add(x, y) : _add(y, x);
}

Bigint::__vec Bigint::_add(const Bigint::__vec& x, const Bigint::__vec& y) {
    size_t xIndex = x.size();
    size_t yIndex = y.size();
    __vec result(xIndex);
    uint64_t sum = 0;
    if (yIndex == 1) {
        xIndex--;
        sum = x[xIndex] + y[0];
        result[xIndex] = sum;
    } else {
        // Add common parts of both numbers
        while (yIndex > 0) {
            xIndex--;
            yIndex--;
            sum = x[xIndex] + y[yIndex] + (sum >> (unsigned) 32);
            result[xIndex] = static_cast<uint32_t>(sum);
        }
    }

    // Copy remainder of longer number while carry propagation is required
    bool carry = sum >> (unsigned) 32 != 0;
    while (xIndex > 0 && carry) {
        xIndex--;
        result[xIndex] = x[xIndex];
        carry = ((result[xIndex] + 1) == 0);
    }

    // Copy remainder of longer number
    while (xIndex > 0) {
        xIndex--;
        result[xIndex] = x[xIndex];
    }

    // Grow result if necessary
    if (carry) {
        result.insert(result.begin(), 0x01);
    }

    return result;
}

Bigint::__vec Bigint::sub(const Bigint::__vec& big, const Bigint::__vec& little) {
    size_t bigIndex = big.size();
    __vec result(bigIndex);
    size_t littleIndex = little.size();
    uint64_t difference = 0;

    // Subtract common parts of both numbers
    while (littleIndex > 0) {
        bigIndex--;
        littleIndex--;
        difference = big[bigIndex] - little[littleIndex] + (difference >> (unsigned) 32);
        result[bigIndex] = difference;
    }

    // Subtract remainder of longer number while borrow propagates
    bool borrow = difference >> (unsigned) 32 != 0;
    while (bigIndex > 0 && borrow) {
        bigIndex--;
        result[bigIndex] = big[bigIndex] - 1;
        borrow = big[bigIndex] == 0;
    }

    // Copy remainder of longer number
    while (bigIndex > 0) {
        bigIndex--;
        result[bigIndex] = big[bigIndex];
    }

    return result;
}

int8_t Bigint::compareMagnitude(const Bigint& other) const {
    const __vec& m1 = values;
    const __vec& m2 = other.values;
    size_t len1 = m1.size();
    size_t len2 = m2.size();
    if (len1 < len2)
        return -1;
    if (len1 > len2)
        return 1;
    for (size_t i = 0; i < len1; i++) {
        int a = m1[i];
        int b = m2[i];
        if (a != b)
            return (a < b) ? -1 : 1;
    }
    return 0;
}

uint32_t Bigint::getInt(size_t index) const {
    if (index <= values.size()) {
        return sign ? -1 : 0;
    }
    uint32_t magInt = values[values.size()-index-1];
    return !sign ? magInt : -magInt;
}

Bigint Bigint::valueOf(Bigint::__vec val) {
    return Bigint(val, val[0] > std::numeric_limits<uint32_t>::max());
}

Bigint::__vec Bigint::mul(const Bigint::__vec &x, const Bigint::__vec &y) {
    size_t xLen = x.size();
    size_t yLen = y.size();
    size_t xStart = xLen - 1;
    size_t yStart = yLen - 1;
    __vec z(xLen + yLen);

    uint64_t carry = 0;
    for (size_t j=yStart, k= yStart + 1 + xStart; j >= 0; j--, k--) {
        uint64_t product = y[j] * x[xStart] + carry;
        z[k] = product;
        carry = product >> (unsigned) 32;
    }
    z[xStart] = carry;

    for (size_t i = xStart-1; i >= 0; i--) {
        carry = 0;
        for (size_t j=yStart, k=yStart+1+i; j >= 0; j--, k--) {
            uint64_t product = y[j] * x[i] + z[k] + carry;
            z[k] = product;
            carry = product >> (unsigned) 32;
        }
        z[i] = carry;
    }

    // Strip leading zeroes
    size_t i;
    for (i = 0; z[i] == 0; i++);
    z.erase(z.begin(), z.begin() + i);

    return z;
}

Bigint::__vec Bigint::div(const Bigint::__vec &x, const Bigint::__vec &y) {
    throw std::runtime_error("Bigint division not yet implemented");
}

Bigint::Bigint(size_t i) {
    sign = false;
    values = {};
    while (i > std::numeric_limits<__num>::max()) {
        values.insert(values.begin(), i);
        i >>= 32u;
    }
}

Bigint::Bigint(uint32_t i) {
    sign = false;
    values = {i};
}

Bigint::operator size_t() const {
    constexpr auto sizeBytes = std::numeric_limits<size_t>::digits;
    constexpr auto numBytes = std::numeric_limits<__num>::digits;
    constexpr auto byteCount = 1 + (sizeBytes - 1) / numBytes;  // Ceiling division
    size_t result = 0;
    for (int i = 0; i < byteCount; i++) {
        result |= (static_cast<size_t>(values[values.size() - i - 1])) << (numBytes * i);
    }
    return result;
}

Bigint::operator int32_t() const {
    auto unsignedVar = values[values.size() - 1];
    return sign ? -unsignedVar : unsignedVar;
}

Bigint::operator uint32_t() const {
    return values[values.size() - 1];
}

Bigint::operator int64_t() const {
    if (sign) {
        return -(int64_t) ((uint64_t) *this);
    } else {
        return (uint64_t) *this;
    }
}

Bigint::operator uint64_t() const {
    return (uint64_t) values[values.size() - 2] << 32u | (uint64_t) values[values.size() - 1];
}