//
// Created by Patrick Norton on 12/1/20.
//

#include "Executor.h"
#include "IntTools.h"

void parse(Bytecode b, const std::vector<uint8_t>& bytes, Runtime runtime) {
    assert(bytes.size() == bytecode_size(b));

    switch (b) {

        case Bytecode::NOP:
            return;
        case Bytecode::LOAD_NULL:
            runtime.push(Variable());
            return;
        case Bytecode::LOAD_CONST:
            runtime.push(runtime.load_const(IntTools::bytesTo<uint16_t>(bytes)));
            return;
        case Bytecode::LOAD_VALUE:
            runtime.push(runtime.load_const(IntTools::bytesTo<uint16_t>(bytes)));
            return;
        case Bytecode::LOAD_DOT:
            break;
        case Bytecode::LOAD_SUBSCRIPT:
            break;
        case Bytecode::POP_TOP:
            runtime.pop();
            return;
        case Bytecode::DUP_TOP:
            runtime.push(runtime.top());
            return;
        case Bytecode::SWAP_2: {
            auto oldTop = runtime.pop();
            auto newTop = runtime.pop();
            runtime.push(oldTop);
            runtime.push(newTop);
        }
            return;
        case Bytecode::SWAP_3: {
            auto oldTop = runtime.pop();
            auto middle = runtime.pop();
            auto newTop = runtime.pop();
            runtime.push(oldTop);
            runtime.push(middle);
            runtime.push(newTop);
        }
            return;
        case Bytecode::SWAP_N:
            break;
        case Bytecode::STORE:
            runtime.store_variable(IntTools::bytesTo<uint16_t>(bytes), runtime.pop());
            return;
        case Bytecode::STORE_SUBSCRIPT:
            break;
        case Bytecode::PLUS:
            break;
        case Bytecode::MINUS:
            break;
        case Bytecode::TIMES:
            break;
        case Bytecode::DIVIDE:
            break;
        case Bytecode::MOD:
            break;
        case Bytecode::SUBSCRIPT:
            break;
        case Bytecode::POWER:
            break;
        case Bytecode::L_BITSHIFT:
            break;
        case Bytecode::R_BITSHIFT:
            break;
        case Bytecode::BITWISE_AND:
            break;
        case Bytecode::BITWISE_OR:
            break;
        case Bytecode::BITWISE_XOR:
            break;
        case Bytecode::COMPARE:
            break;
        case Bytecode::DEL_SUBSCRIPT:
            break;
        case Bytecode::U_MINUS:
            break;
        case Bytecode::BITWISE_NOT:
            break;
        case Bytecode::BOOL_AND:
            break;
        case Bytecode::BOOL_OR:
            break;
        case Bytecode::BOOL_NOT:
            break;
        case Bytecode::IDENTICAL:
            break;
        case Bytecode::INSTANCEOF:
            break;
        case Bytecode::CALL_OP:
            break;
        case Bytecode::PACK_TUPLE:
            break;
        case Bytecode::UNPACK_TUPLE:
            break;
        case Bytecode::JUMP:
            runtime.goTo(IntTools::bytesTo<uint32_t>(bytes));
        case Bytecode::JUMP_FALSE:
            break;
        case Bytecode::JUMP_TRUE:
            break;
        case Bytecode::JUMP_NN:
            break;
        case Bytecode::CALL_METHOD:
            break;
        case Bytecode::CALL_TOS:
            break;
        case Bytecode::TAIL_METHOD:
            break;
        case Bytecode::TAIL_TOS:
            break;
        case Bytecode::RETURN:
            break;
        case Bytecode::THROW:
            break;
        case Bytecode::THROW_QUICK:
            break;
        case Bytecode::ENTER_TRY:
            break;
        case Bytecode::EXCEPT_N:
            break;
        case Bytecode::FINALLY:
            break;
        case Bytecode::END_TRY:
            break;
        case Bytecode::FUNC_DEF:
            break;
        case Bytecode::CLASS_DEF:
            break;
        case Bytecode::END_CLASS:
            break;
    }
    throw std::runtime_error("Bytecode not implemented yet");
}