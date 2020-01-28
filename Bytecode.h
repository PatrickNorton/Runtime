//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_BYTECODE_H
#define RUNTIME_BYTECODE_H


#include <cstdint>

enum class Bytecode : std::uint8_t {
    NOP = 0x0,
    LOAD_NULL = 0x1,
    LOAD_CONST = 0x2,
    LOAD_VALUE = 0x3,
    LOAD_DOT = 0x4,
    LOAD_SUBSCRIPT = 0x5,
    POP_TOP = 0x6,
    DUP_TOP = 0x7,
    SWAP_2 = 0x8,
    SWAP_3 = 0x9,
    SWAP_N = 0xA,
    STORE = 0xB,
    STORE_SUBSCRIPT = 0xC,
    STORE_ATTR = 0xD,
    // Binary operators
    PLUS = 0x10,
    MINUS = 0x11,
    TIMES = 0x12,
    DIVIDE = 0x13,
    MOD = 0x14,
    SUBSCRIPT = 0x15,
    POWER = 0x16,
    L_BITSHIFT = 0x17,
    R_BITSHIFT = 0x18,
    BITWISE_AND = 0x19,
    BITWISE_OR = 0x1A,
    BITWISE_XOR = 0x1B,
    COMPARE = 0x1C,
    DEL_SUBSCRIPT = 0x1D,
    U_MINUS = 0x1E,
    BITWISE_NOT = 0x1F,
    BOOL_AND = 0x20,
    BOOL_OR = 0x21,
    BOOL_NOT = 0x22,
    IDENTICAL = 0x23,
    INSTANCEOF = 0x24,
    CALL_OP = 0x25,
    PACK_TUPLE = 0x26,
    UNPACK_TUPLE = 0x27,
    EQUAL = 0x28,
    LESS_THAN = 0x29,
    GREATER_THAN = 0x2A,
    LESS_EQUAL = 0x2B,
    GREATER_EQUAL = 0x2C,
    // Jumps, etc.
    JUMP = 0x30,
    JUMP_FALSE = 0x31,
    JUMP_TRUE = 0x32,
    JUMP_NN = 0x33,
    CALL_METHOD = 0x34,
    CALL_TOS = 0x35,
    TAIL_METHOD = 0x36,
    TAIL_TOS = 0x37,
    RETURN = 0x38,
    THROW = 0x39,
    THROW_QUICK = 0x3A,
    ENTER_TRY = 0x3B,
    EXCEPT_N = 0x3C,
    FINALLY = 0x3D,
    END_TRY = 0x3E,
    // Markers
    FUNC_DEF = 0x40,
    CLASS_DEF = 0x41,
    END_CLASS = 0x42,
};


// MUST BE KEPT UP-TO-DATE WITH THE ENUM
int bytecode_size(Bytecode bytecode);


#endif //RUNTIME_BYTECODE_H
