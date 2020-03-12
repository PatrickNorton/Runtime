//
// Created by Patrick Norton on 11/1/20.
//

#ifndef RUNTIME_BYTECODE_H
#define RUNTIME_BYTECODE_H


#include <cstdint>

enum class Bytecode : uint8_t {
    NOP = 0x0,
    LOAD_NULL = 0x1,
    LOAD_CONST = 0x2,
    LOAD_VALUE = 0x3,
    LOAD_DOT = 0x4,
    LOAD_SUBSCRIPT = 0x5,
    LOAD_OP = 0x6,
    POP_TOP = 0x7,
    DUP_TOP = 0x8,
    SWAP_2 = 0x9,
    SWAP_3 = 0xA,
    SWAP_N = 0xB,
    STORE = 0xC,
    STORE_SUBSCRIPT = 0xD,
    STORE_ATTR = 0xE,
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
    BOOL_XOR = 0x23,
    IDENTICAL = 0x24,
    INSTANCEOF = 0x25,
    CALL_OP = 0x26,
    PACK_TUPLE = 0x27,
    UNPACK_TUPLE = 0x28,
    EQUAL = 0x29,
    LESS_THAN = 0x2A,
    GREATER_THAN = 0x2B,
    LESS_EQUAL = 0x2C,
    GREATER_EQUAL = 0x2D,
    CONTAINS = 0x2E,
    // Jumps, etc.
    JUMP = 0x30,
    JUMP_FALSE = 0x31,
    JUMP_TRUE = 0x32,
    JUMP_NN = 0x33,
    JUMP_NULL = 0x34,
    CALL_METHOD = 0x35,
    CALL_TOS = 0x36,
    TAIL_METHOD = 0x37,
    TAIL_TOS = 0x38,
    RETURN = 0x39,
    THROW = 0x3A,
    THROW_QUICK = 0x3B,
    ENTER_TRY = 0x3C,
    EXCEPT_N = 0x3D,
    FINALLY = 0x3E,
    END_TRY = 0x3F,
    // Markers
    FUNC_DEF = 0x40,
    CLASS_DEF = 0x41,
    END_CLASS = 0x42,
    // Loop stuff
    FOR_ITER = 0x50,
    LIST_CREATE = 0x51,
    SET_CREATE = 0x52,
    DICT_CREATE = 0x53,
    LIST_ADD = 0x54,
    SET_ADD = 0x55,
    DICT_ADD = 0x56,
    DOTIMES = 0x57,
};


// MUST BE KEPT UP-TO-DATE WITH THE ENUM
int bytecode_size(Bytecode bytecode);


#endif //RUNTIME_BYTECODE_H
