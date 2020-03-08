//
// Created by Patrick Norton on 11/1/20.
//

#include "Bytecode.h"


// MUST BE KEPT UP-TO-DATE WITH THE ENUM
int bytecode_size(Bytecode bytecode) {
    switch (bytecode) {

        case Bytecode::NOP:
        case Bytecode::LOAD_NULL:
            return 0;
        case Bytecode::LOAD_CONST:
        case Bytecode::LOAD_VALUE:
        case Bytecode::LOAD_DOT:
        case Bytecode::LOAD_SUBSCRIPT:
        case Bytecode::LOAD_OP:
            return 2;
        case Bytecode::POP_TOP:
        case Bytecode::DUP_TOP:
        case Bytecode::SWAP_2:
        case Bytecode::SWAP_3:
            return 0;
        case Bytecode::SWAP_N:
            return 4;
        case Bytecode::STORE:
        case Bytecode::STORE_SUBSCRIPT:
        case Bytecode::STORE_ATTR:
            return 2;
        case Bytecode::PLUS:
        case Bytecode::MINUS:
        case Bytecode::TIMES:
        case Bytecode::DIVIDE:
        case Bytecode::MOD:
        case Bytecode::SUBSCRIPT:
        case Bytecode::POWER:
        case Bytecode::L_BITSHIFT:
        case Bytecode::R_BITSHIFT:
        case Bytecode::BITWISE_AND:
        case Bytecode::BITWISE_OR:
        case Bytecode::BITWISE_XOR:
        case Bytecode::COMPARE:
        case Bytecode::DEL_SUBSCRIPT:
        case Bytecode::U_MINUS:
        case Bytecode::BITWISE_NOT:
        case Bytecode::BOOL_AND:
        case Bytecode::BOOL_OR:
        case Bytecode::BOOL_NOT:
        case Bytecode::BOOL_XOR:
        case Bytecode::IDENTICAL:
        case Bytecode::INSTANCEOF:
        case Bytecode::EQUAL:
        case Bytecode::LESS_THAN:
        case Bytecode::GREATER_THAN:
        case Bytecode::LESS_EQUAL:
        case Bytecode::GREATER_EQUAL:
            return 0;
        case Bytecode::CALL_OP:
            return 2+2;
        case Bytecode::PACK_TUPLE:
        case Bytecode::UNPACK_TUPLE:
            return 0;
        case Bytecode::JUMP:
        case Bytecode::JUMP_FALSE:
        case Bytecode::JUMP_TRUE:
        case Bytecode::JUMP_NN:
        case Bytecode::JUMP_NULL:
            return 4;
        case Bytecode::CALL_METHOD:
        case Bytecode::CALL_TOS:
        case Bytecode::TAIL_METHOD:
        case Bytecode::TAIL_TOS:
        case Bytecode::RETURN:
            return 2;
        case Bytecode::THROW:
            return 0;
        case Bytecode::THROW_QUICK:
        case Bytecode::ENTER_TRY:
        case Bytecode::EXCEPT_N:
            return 2;
        case Bytecode::FINALLY:
        case Bytecode::END_TRY:
        case Bytecode::FUNC_DEF:
        case Bytecode::CLASS_DEF:
        case Bytecode::END_CLASS:
            return 0;
        case Bytecode::FOR_ITER:
            return 4;
        case Bytecode::LIST_CREATE:
        case Bytecode::SET_CREATE:
        case Bytecode::DICT_CREATE:
            return 2;
        case Bytecode::LIST_ADD:
        case Bytecode::SET_ADD:
        case Bytecode::DICT_ADD:
            return 0;
        case Bytecode::DOTIMES:
            return 4;
    }
}
