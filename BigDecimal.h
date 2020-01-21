//
// Created by Patrick Norton on 21/1/20.
//

#ifndef RUNTIME_BIGDECIMAL_H
#define RUNTIME_BIGDECIMAL_H


#include "Bigint.h"

class BigDecimal {
private:
    Bigint value;
    size_t offset;
public:
    BigDecimal(Bigint, size_t);

    Bigint round() const;
    std::string toString() const;
};


#endif //RUNTIME_BIGDECIMAL_H
