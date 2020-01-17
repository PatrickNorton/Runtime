//
// Created by Patrick Norton on 14/1/20.
//

#ifndef RUNTIME_BIGINT_H
#define RUNTIME_BIGINT_H


#include <vector>

class Bigint {
private:

    typedef uint32_t __num;
    typedef std::vector<__num> __vec;
    __vec values;
    bool sign;  // True if negative, false if positive
    int8_t compareMagnitude(const Bigint& other) const;
    uint32_t getInt(size_t index) const;
    static __vec add(const __vec& x, const __vec& y);
    static __vec _add(const __vec& x, const __vec& y);
    static __vec sub(const __vec& x, const __vec& y);
    static __vec mul(const __vec& x, const __vec& y);
    static __vec div(const __vec& x, const __vec& y);

    static Bigint valueOf(__vec val);

public:
    Bigint();
    explicit Bigint(size_t i);
    explicit Bigint(int32_t i);
    explicit Bigint(uint32_t i);
    explicit Bigint(int64_t);
    explicit Bigint(uint64_t);
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
    Bigint operator++() const;
    bool operator==(const Bigint&) const;
    bool operator!=(const Bigint&) const;
    Bigint operator-() const;
    explicit operator bool() const;
    bool operator>(const Bigint&) const;
    bool operator<(const Bigint&) const;

    explicit operator size_t() const;
    explicit operator int32_t() const;
    explicit operator uint32_t() const;
    explicit operator int64_t() const;
    explicit operator uint64_t() const;
};

Bigint operator "" _B (unsigned long long);


#endif //RUNTIME_BIGINT_H
