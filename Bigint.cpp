//
// Created by Patrick Norton on 14/1/20.
//

#include "Bigint.h"
#include "Constants.h"
#include "Integer.h"

#include <string>
#include <cmath>
#include <algorithm>
#include <utility>

namespace {
    const uint32_t MAX_MAG_LENGTH = std::numeric_limits<uint32_t>::max() / std::numeric_limits<uint32_t>::digits + 1;

    int intOf(char c) {
        if (!isdigit(c)) {
            throw std::invalid_argument("Given argument is not a digit");
        } else {
            return c - '0';
        }
    }
}

const Bigint Bigint::ZERO = 0_B;

Bigint::Bigint() noexcept {
    sign = false;
    values = {0};
}

Bigint::Bigint(int64_t value) noexcept {
    sign = value < 0;
    auto uValue = static_cast<uint64_t>(value);
    values = {};
    do {
        values.insert(values.begin(), static_cast<uint32_t>(uValue));
        uValue >>= NUM_BITS;
    } while (uValue > std::numeric_limits<uint32_t>::max());
}

Bigint::Bigint(int value) noexcept {
    sign = value < 0;
    auto uValue = static_cast<uint64_t>(value);
    values = {};
    do {
        values.insert(values.begin(), static_cast<uint32_t>(uValue));
        uValue >>= NUM_BITS;
    } while (uValue > std::numeric_limits<uint32_t>::max());
}

Bigint::Bigint(uint64_t value) noexcept {
    sign = value < 0;
    values = {};
    do {
        values.insert(values.begin(), static_cast<uint32_t>(value));
        value >>= NUM_BITS;
    } while (value > std::numeric_limits<uint32_t>::max());
}

Bigint::Bigint(std::vector<uint32_t> values, bool sign) {
    this->values = std::move(values);
    this->sign = sign;
}

Bigint::Bigint(__vec values) noexcept : values(std::move(values)), sign(false) {
}

Bigint::Bigint(uint32_t value, bool sign) noexcept : values({value}), sign(sign) {
}

Bigint::Bigint(std::string value) {
    size_t i = 0;
    if (value[0] == '+' || value[0] == '-') {
        sign = values[0] == '-';
        i++;
    }
    if (value.size() < 10 + i) {
        *this = Bigint(std::stoi(value));
        return;
    }
    sign = false;
    Bigint result = 0_B;
    for (; i < value.size(); i++) {
        auto iVal = intOf(value[i]);
        if (iVal != 0) {
            result += Bigint(iVal) * (10_B).pow(value.size() - i - 1);
        }
    }
    this->values = result.values;
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
            return 0_B;
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
        return 0_B;
    } else if (cmp > 0) {
        return Bigint(sub(values, other.values), sign);
    } else {  // cmp < 0
        return Bigint(sub(other.values, values), other.sign);
    }
}

Bigint Bigint::operator*(const Bigint& other) const {
    if (!*this || !other) {
        return 0_B;
    }
    bool resultSign = sign == other.sign;
    return Bigint(mul(values, other.values), resultSign);
}

Bigint Bigint::operator/(const Bigint& other) const {
    if (*this == other) {
        return Bigint(sign == other.sign ? 1 : -1);
    } else if (other.abs() > this->abs()) {
        return 0_B;
    } else {
        return div_rem(*this, other).first;
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
    return (-*this) - 1_B;
}

Bigint Bigint::operator<<(const size_t& other) const {
    if (!*this) {
        return 0_B;
    }
    if (other == 0) {
        return *this;
    }
    __vec result(values);
    size_t wholeShifts = other / NUM_BITS;
    __vec shifts(wholeShifts);
    result.insert(values.end(), shifts.begin(), shifts.end());
    size_t remainder = other % NUM_BITS;
    if (remainder) {
        bool carry = (result[0] >> remainder) != 0;
        size_t r2size = carry ? result.size() + 1 : result.size();
        __vec result2(r2size);
        if (carry) {
            result2[0] = result[0] >> remainder;
        }
        for (size_t i = 0; i < result.size(); i++) {
            result2[i + carry] = (result[i] << remainder) | (i + 1 < result.size() ? (result[i+1] >> remainder) : 0u);
        }
        return Bigint(result2, sign);
    } else {
        return Bigint(result, sign);
    }
}

Bigint Bigint::operator>>(const size_t& other) const {
    if (!*this) {
        return 0_B;
    }
    if (other == 0) {
        return *this;
    }
    constexpr auto intBytes = std::numeric_limits<uint32_t>::digits;
    __vec result(values);
    if (other > values.size() * intBytes) {
        return 0_B;
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

Bigint Bigint::operator%(const Bigint& other) const {
    return div_rem(*this, other).second;
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
            sum = x[xIndex] + y[yIndex] + (sum >> NUM_BITS);
            result[xIndex] = static_cast<uint32_t>(sum);
        }
    }

    // Copy remainder of longer number while carry propagation is required
    bool carry = sum >> NUM_BITS != 0;
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
        difference = big[bigIndex] - little[littleIndex] + (difference >> NUM_BITS);
        result[bigIndex] = difference;
    }

    // Subtract remainder of longer number while borrow propagates
    bool borrow = difference >> NUM_BITS != 0;
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
        auto a = m1[i];
        auto b = m2[i];
        if (a != b)
            return (a < b) ? -1 : 1;
    }
    return 0;
}

uint32_t Bigint::getInt(size_t index) const {
    if (index >= values.size()) {
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
        carry = product >> NUM_BITS;
        if (j == 0)
            break;
    }
    z[xStart] = carry;

    for (size_t i = xStart; i > 0; i--) {
        carry = 0;
        for (size_t j=yStart+1, k=yStart+1+i; j > 0; j--, k--) {
            uint64_t product = y[j-1] * x[i-1] + z[k] + carry;
            z[k] = product;
            carry = product >> NUM_BITS;
        }
        z[i-1] = carry;
    }

    // Strip leading zeroes
    size_t i;
    for (i = 0; z[i] == 0; i++);
    z.erase(z.begin(), z.begin() + i);

    return z;
}

Bigint::Bigint(size_t i) noexcept {
    sign = false;
    values = {};
    while (i > std::numeric_limits<__num>::max()) {
        values.insert(values.begin(), i);
        i >>= 32u;
    }
}

Bigint::Bigint(uint32_t i) noexcept {
    sign = false;
    values = {i};
}

Bigint::operator size_t() const {
    constexpr auto sizeBytes = std::numeric_limits<size_t>::digits;
    constexpr auto byteCount = 1 + (sizeBytes - 1) / NUM_BITS;  // Ceiling division
    size_t result = 0;
    for (size_t i = 0; i < byteCount; i++) {
        result |= values.size() > i ? values[values.size() - i - 1] << (NUM_BITS * i) : 0;
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

Bigint& Bigint::operator++() {
    static const Bigint ONE = 1_B;  // Prevent over-creation
    *this = *this + ONE;
    return *this;
}

Bigint& Bigint::operator--() {
    static const Bigint ONE = 1_B;  // Prevent over-creation
    *this = *this - ONE;
    return *this;
}

Bigint Bigint::operator++(int) {
    static const Bigint ONE = 1_B;  // Prevent over-creation
    Bigint temp = *this;
    ++*this;
    return temp;
}

Bigint Bigint::operator--(int) {
    static const Bigint ONE = 1_B;  // Prevent over-creation
    Bigint temp = *this;
    --*this;
    return temp;
}

// Inplace operators
Bigint& Bigint::operator+=(const Bigint& other) {
    *this = *this + other;
    return *this;
}

Bigint& Bigint::operator-=(const Bigint& other) {
    *this = *this - other;
    return *this;
}

Bigint& Bigint::operator*=(const Bigint& other) {
    *this = *this * other;
    return *this;
}

Bigint& Bigint::operator/=(const Bigint& other) {
    *this = *this / other;
    return *this;
}

Bigint& Bigint::operator^=(const Bigint& other) {
    *this = *this ^ other;
    return *this;
}

Bigint& Bigint::operator|=(const Bigint& other) {
    *this = *this | other;
    return *this;
}

Bigint& Bigint::operator&=(const Bigint& other) {
    *this = *this & other;
    return *this;
}

Bigint& Bigint::operator>>=(const size_t& other) {
    *this = *this >> other;
    return *this;
}

Bigint& Bigint::operator<<=(const size_t& other) {
    *this = *this << other;
    return *this;
}

bool Bigint::operator>=(const Bigint & other) const {
    return *this > other || *this == other;
}

bool Bigint::operator<=(const Bigint & other) const {
    return *this < other || *this == other;
}

std::string Bigint::to_string() const {
    if (values.empty()) {
        return "0";
    } else if (values.size() == 1) {
        return sign ? "-" + std::to_string(values[0]) : std::to_string(values[0]);
    } else {
        return to_str(*this);
    }
}

std::string Bigint::to_str(Bigint value) {
    if (!value) {
        return "0";
    }
    static const Bigint TEN = 10_B;
    std::string result {};
    if (value < ZERO) {
        value = -value;
        result.push_back('-');
    }
    while (value != ZERO) {
        result.push_back(std::to_string(int32_t(value % TEN))[0]);
        value /= TEN;
    }
    return result;
}

std::pair<Bigint, Bigint> Bigint::div_rem(Bigint x, Bigint y) {
    if (!y) {
        throw std::runtime_error("Cannot divide by 0");
    }

    if (!x) {
        return {0_B, 0_B};
    }

    auto cmp = x.compareMagnitude(y);

    if (cmp == 0) {
        return {1_B, 0_B};
    }

    if (cmp < 0) {
        return {0_B, x};
    }

    bool sign = x.sign ^ y.sign;
    if (x.values.size() == 1 && y.values.size() == 1) {
        return {Bigint(x.values[0] / y.values[0], sign), Bigint(x.values[0] % y.values[0])};
    }

    // Shift away some of it
    size_t shift = std::min(x.numberOfTrailingZeros(), y.numberOfTrailingZeros());
    x >>= shift;
    y >>= shift;
    return divideKnuth2(x, y);
}

/*
 * Taken from Knuth's Algorithm D.
 */
std::pair<Bigint, Bigint> Bigint::divideKnuth2(const Bigint& u, const Bigint& v) {
    bool resultSign = u.sign ^ v.sign;
    size_t uSize = u.sizeWithoutLeadingZeros();
    size_t vSize = v.sizeWithoutLeadingZeros();
    size_t n = vSize;
    size_t m = uSize - vSize;
    uint32_t d = (1u << (NUM_BITS - 1)) / Integer::numberOfLeadingZeros(v.values[vSize - 1]);
    /*
     * Normalize by shifting v left just enough so that its high-order
     * bit is on, and shift u left the same amount. We may have to append a
     * high-order digit on the dividend; we do that unconditionally.
     */
    Bigint vn = v.abs() << d;
    Bigint un = u.abs() << d;
    Bigint q = ZERO;
    q.values = __vec(m + 1);
    if (un.values.size() == u.values.size()) {
        un.values.push_back(0);
    }
    for (size_t j = m; j + 1 > 0; --j) {
        uint64_t qHat = (un[j+n] * NUM_BITS + un[j+n-1]) / vn[n - 1];
        uint64_t rHat = (un[j+n] * NUM_BITS + un[j+n-1]) % vn[n - 1];
        do {
            if (qHat == NUM_BITS || qHat * vn[n - 2] > rHat * NUM_BITS + un[n + j - 2]) {
                qHat--;
                rHat += vn[n-1];
            } else {
                break;
            }
        } while (rHat < NUM_BITS);
        // Multiply and subtract.
        for (size_t i = 0; i < n; i++) {
            uint64_t t = un[i+j] - qHat * vn[i];
            un.values[i+j] = t;
        }
        q.values[j] = qHat;
    }
    Bigint rem = ZERO;
    rem.values = __vec(un.values.size());
    for (size_t i = 0; i < un.values.size(); i++) {
        rem.values[i] = un[i] * m;
    }
    return {resultSign ? -q : q, rem};
}

size_t Bigint::numberOfTrailingZeros() const {
    if (!*this)
        return -1;
    size_t j, b;
    for (j=values.size()-1; (j > 0) && (values[j] == 0); j--)
        ;
    b = values[j];
    if (b == 0)
        return -1;
    size_t trailing0s = 0;
    for (; b % 2 == 0; b >>= 1u, trailing0s++);
    return ((values.size()-1-j)<<5u) + trailing0s;
}

Bigint Bigint::pow(const size_t& exponent) const {
    if (exponent < 0) {
        throw std::runtime_error("Negative exponent");
    }
    if (!*this) {
        return exponent == 0 ? 1_B : *this;
    }
    if (!exponent) {
        return 1_B;
    }

    auto partToSquare = this->abs();

    // Factor out powers of two from the base, as the exponentiation of
    // these can be done by left shifts only.
    // The remaining part can then be exponentiated faster.  The
    // powers of two will be multiplied back at the end.
    auto powersOfTwo = partToSquare.getLowestSetBit();
    auto bitsToShiftLong = static_cast<uint64_t>(powersOfTwo) * exponent;
    if (bitsToShiftLong > std::numeric_limits<uint32_t>::max()) {
        throw std::runtime_error("Overflow");
    }
    auto bitsToShift =static_cast<uint32_t>(bitsToShiftLong);

    uint32_t remainingBits;

    // Factor the powers of two out quickly by shifting right, if needed.
    if (powersOfTwo > 0) {
        partToSquare >>= powersOfTwo;
        remainingBits = partToSquare.bitLength();
        if (remainingBits == 1) {  // Nothing left but +/- 1?
            if (sign && (exponent & 1u) == 1) {
                return -1_B << bitsToShift;
            } else {
                return 1_B << bitsToShift;
            }
        }
    } else {
        remainingBits = partToSquare.bitLength();
        if (remainingBits == 1) { // Nothing left but +/- 1?
            if (sign && (exponent & 1u) == 1) {
                return -1_B;
            } else {
                return 1_B;
            }
        }
    }

    // This is a quick way to approximate the size of the result,
    // similar to doing log2[n] * exponent.  This will give an upper bound
    // of how big the result can be, and which algorithm to use.
    uint64_t scaleFactor = (uint64_t) remainingBits * exponent;

    // Use slightly different algorithms for small and large operands.
    // See if the result will safely fit into a long. (Largest 2^63-1)
    if (partToSquare.values.size() == 1 && scaleFactor <= 62) {
        // Small number algorithm.  Everything fits into a long.
        uint32_t newSign = sign && (exponent & 1u) == 1 ? -1 : 1;
        uint64_t result = 1;
        uint64_t baseToPow2 = partToSquare.values[0];

        uint32_t workingExponent = exponent;

        // Perform exponentiation using repeated squaring trick
        while (workingExponent != 0) {
            if ((workingExponent & 1u) == 1) {
                result = result * baseToPow2;
            }

            if ((workingExponent >>= 1u) != 0) {
                baseToPow2 = baseToPow2 * baseToPow2;
            }
        }

        // Multiply back the powers of two (quickly, by shifting left)
        if (powersOfTwo > 0) {
            if (bitsToShift + scaleFactor <= 62) { // Fits in long?
                return Bigint((result << bitsToShift) * newSign);
            } else {
                return Bigint(result * newSign) << bitsToShift;
            }
        } else {
            return Bigint(result * newSign);
        }
    } else {
        if (static_cast<uint64_t>(bitLength()) * exponent / std::numeric_limits<uint32_t>::digits > MAX_MAG_LENGTH) {
            throw std::runtime_error("Overflow");
        }

        // Large number algorithm.  This is basically identical to
        // the algorithm above, but calls multiply() and square()
        // which may use more efficient algorithms for large numbers.
        auto answer = 1_B;

        size_t workingExponent = exponent;
        // Perform exponentiation using repeated squaring trick
        while (workingExponent != 0) {
            if ((workingExponent & 1u) == 1) {
                answer *= partToSquare;
            }

            if ((workingExponent >>= 1u) != 0) {
                partToSquare *= partToSquare;
            }
        }
        // Multiply back the (exponentiated) powers of two (quickly,
        // by shifting left)
        if (powersOfTwo > 0) {
            answer <<= bitsToShift;
        }

        if (*this < ZERO && (exponent & 1u) == 1) {
            return -answer;
        } else {
            return answer;
        }
    }
}

Bigint Bigint::abs() const {
    return sign ? -*this : *this;
}

size_t Bigint::bitLength() const {
    size_t n;
    size_t len = values.size();
    if (len == 0) {
        n = 0; // offset by one to initialize
    } else {
        // Calculate the bit length of the magnitude
        size_t magBitLength = ((len - 1u) << 5u) + Integer::bitLengthForInt(values[0]);
        if (sign) {
            // Check if magnitude is a power of two
            bool pow2 = (Integer::bitCount(values[0]) == 1);
            for (size_t i=1; i < len && pow2; i++)
                pow2 = (values[i] == 0);

            n = (pow2 ? magBitLength - 1 : magBitLength);
        } else {
            n = magBitLength;
        }
    }
    return n + 1;
}

uint32_t Bigint::getLowestSetBit() const {
    uint32_t lsb = 0;
    if (sign) {
        lsb--;
    } else {
        // Search for lowest order nonzero int
        uint32_t i, b;
        for (i = 0; (b = getInt(i)) == 0; i++);
        lsb += (i << 5u) + Integer::numberOfTrailingZeros(b);
    }
    return lsb;
}

size_t Bigint::sizeWithoutLeadingZeros() const {
    for (size_t answer = values.size(); answer > 0; --answer) {
        if (values[answer - 1] != 0) {
            return answer - 1;
        }
    }
    return 0;
}

Bigint::__num Bigint::operator[](size_t i) {
    return values[i];
}

Bigint operator "" _B(unsigned long long val) noexcept {
    return Bigint(val);
}

std::ostream& operator<<(std::ostream& stream, const Bigint& val) noexcept {
    stream << val.to_string();
    return stream;
}
