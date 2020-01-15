//
// Created by Patrick Norton on 14/1/20.
//

#ifndef RUNTIME_BIGINT_H
#define RUNTIME_BIGINT_H


#include <vector>

class Bigint {
private:
    explicit Bigint(int i);

    typedef std::vector<uint32_t> __vec;
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
    explicit Bigint(int64_t);
    explicit Bigint(uint64_t);
    Bigint(std::vector<uint32_t>, bool);
    Bigint operator+(const Bigint&) const;
    Bigint operator-(const Bigint&) const;
    Bigint operator*(const Bigint&) const;
    Bigint operator/(const Bigint&) const;
    Bigint operator^(const Bigint&) const;
    Bigint operator|(const Bigint&) const;
    Bigint operator&(const Bigint&) const;
    Bigint operator>>(const size_t&) const;
    Bigint operator<<(const size_t&) const;
    bool operator==(const Bigint&) const;
    Bigint operator-() const;
    explicit operator bool() const;
    bool operator>(const Bigint&) const;
    bool operator<(const Bigint&) const;
};


#endif //RUNTIME_BIGINT_H
