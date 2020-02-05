//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_CONSTANTBYTES_H
#define RUNTIME_CONSTANTBYTES_H


#include <cstdint>

enum class ConstantBytes : uint8_t {
    STR,
    INT,
    BIGINT,
    DECIMAL,
    IMPORT,
    BUILTIN,
    FUNCTION,
    BOOL,
    CLASS,
};


#endif //RUNTIME_CONSTANTBYTES_H
