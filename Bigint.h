//
// Created by Patrick Norton on 14/1/20.
//

#ifndef RUNTIME_BIGINT_H
#define RUNTIME_BIGINT_H


#include <string>
#include <vector>

class Bigint {
private:
    static const Bigint ZERO;  // Prevent over-creation of 0s

    typedef uint32_t __num;
    typedef std::vector<__num> __vec;

    explicit Bigint(__vec) noexcept;
    Bigint(uint32_t, bool) noexcept;
    __vec values;
    bool sign{};  // True if negative, false if positive
    int8_t compareMagnitude(const Bigint& other) const;
    uint32_t getInt(size_t index) const;
    size_t numberOfTrailingZeros() const;
    static __vec add(const __vec& x, const __vec& y);
    static __vec _add(const __vec& x, const __vec& y);
    static __vec sub(const __vec& x, const __vec& y);
    static __vec mul(const __vec& x, const __vec& y);
    static std::string to_str(Bigint);

    static std::pair<Bigint, Bigint> div_rem(const Bigint& x, const Bigint& y);

    static Bigint valueOf(__vec val);

    static constexpr unsigned int NUM_BITS = std::numeric_limits<__num>::digits;

    size_t bitLength() const;
    uint32_t getLowestSetBit() const;

    size_t sizeWithoutLeadingZeros() const;
    static std::pair<Bigint, Bigint> divideKnuth(const Bigint& u, const Bigint& v);

    __num operator[](size_t);
public:
    Bigint() noexcept;
    explicit Bigint(size_t i) noexcept;
    explicit Bigint(int32_t i) noexcept;
    explicit Bigint(uint32_t i) noexcept;
    explicit Bigint(int64_t) noexcept;
    explicit Bigint(uint64_t) noexcept;
    explicit Bigint(std::string);
    Bigint(__vec, bool);
    Bigint operator+(const Bigint&) const;
    Bigint operator-(const Bigint&) const;
    Bigint operator*(const Bigint&) const;
    Bigint operator/(const Bigint&) const;
    Bigint operator^(const Bigint&) const;
    Bigint operator|(const Bigint&) const;
    Bigint operator&(const Bigint&) const;
    Bigint operator~() const;
    Bigint operator>>(const size_t&) const;
    Bigint operator<<(const size_t&) const;
    Bigint operator%(const Bigint&) const;
    Bigint& operator++();
    Bigint& operator--();
    Bigint operator++(int);
    Bigint operator--(int);

    Bigint& operator+=(const Bigint&);
    Bigint& operator-=(const Bigint&);
    Bigint& operator*=(const Bigint&);
    Bigint& operator/=(const Bigint&);
    Bigint& operator^=(const Bigint&);
    Bigint& operator|=(const Bigint&);
    Bigint& operator&=(const Bigint&);
    Bigint& operator>>=(const size_t&);
    Bigint& operator<<=(const size_t&);

    bool operator==(const Bigint&) const;
    bool operator!=(const Bigint&) const;
    Bigint operator-() const;
    explicit operator bool() const;
    bool operator>(const Bigint&) const;
    bool operator<(const Bigint&) const;
    bool operator>=(const Bigint&) const;
    bool operator<=(const Bigint&) const;

    explicit operator size_t() const;
    explicit operator int32_t() const;
    explicit operator uint32_t() const;
    explicit operator int64_t() const;
    explicit operator uint64_t() const;

    Bigint pow(const size_t&) const;
    Bigint pow(const Bigint&) const;
    Bigint abs() const;

    std::string to_string() const;
};

Bigint operator "" _B (unsigned long long) noexcept;

std::ostream& operator<<(std::ostream&, const Bigint&) noexcept;

#endif //RUNTIME_BIGINT_H
