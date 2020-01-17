//
// Created by Patrick Norton on 12/1/20.
//

#include "Executor.h"
#include "IntTools.h"
#include "IntUtils.h"

void parse(const Bytecode b, const std::vector<uint8_t>& bytes, Runtime& runtime) {
    switch (b) {

        case Bytecode::NOP:
            return;
        case Bytecode::LOAD_NULL:
            runtime.push(Constants::null());
            return;
        case Bytecode::LOAD_CONST:
            runtime.push(runtime.load_const(IntTools::bytesTo<uint16_t>(bytes)));
            return;
        case Bytecode::LOAD_VALUE:
            runtime.push(runtime.load_variable(IntTools::bytesTo<uint16_t>(bytes)));
            return;
        case Bytecode::LOAD_DOT:
            break;
        case Bytecode::LOAD_SUBSCRIPT: {
            auto operandCount = IntTools::bytesTo<uint16_t>(bytes);
            std::vector<Variable> args(operandCount);
            for (int i = 0; i < operandCount; i++) {
                args[operandCount - i - 1] = runtime.pop();
            }
            runtime.push(runtime.pop()->callOperator(Operator::GET_ATTR, args));
        }
            return;
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
            runtime.push(middle);
            runtime.push(oldTop);
            runtime.push(newTop);
        }
            return;
        case Bytecode::SWAP_N: {
            auto swapped = IntTools::bytesTo<uint16_t>(bytes);
            std::vector<Variable> popped(swapped);
            for (uint16_t i = 0; i < swapped; i++) {
                popped[i] = runtime.pop();
            }
            for (uint16_t i = swapped - 2; i >= 0; i--) {
                runtime.push(popped[i]);
            }
            runtime.push(popped[swapped-1]);
        }
            return;
        case Bytecode::STORE:
            runtime.store_variable(IntTools::bytesTo<uint16_t>(bytes), runtime.pop());
            return;
        case Bytecode::STORE_SUBSCRIPT: {
            auto result = runtime.pop();
            auto index = runtime.pop();
            auto stored = runtime.pop();
            stored->callOperator(Operator::SET_ATTR, {index, result});
        }
            return;
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
        case Bytecode::IDENTICAL: {
            Variable x = runtime.pop();
            Variable y = runtime.pop();
            runtime.push(Constants::fromNative(x == y));
        }
            return;
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
            if (!*runtime.pop()) {
                runtime.goTo(IntTools::bytesTo<uint32_t>(bytes));
            }
            return;
        case Bytecode::JUMP_TRUE:
            if (*runtime.pop()) {
                runtime.goTo(IntTools::bytesTo<uint32_t>(bytes));
            }
            return;
        case Bytecode::JUMP_NN: {
            if (runtime.pop() == Constants::null()) {
                runtime.goTo(IntTools::bytesTo<uint32_t>(bytes));
            }
        }
            return;
        case Bytecode::CALL_METHOD:
            break;
        case Bytecode::CALL_TOS: {
            auto argc = IntTools::bytesTo<uint16_t>(bytes);
            std::vector<Variable> argv(argc);
            for (uint16_t i = 0; i < argc; i++) {
                argv[argc - i - 1] = runtime.pop();
            }
            auto caller = runtime.pop();
            caller->callOperator(Operator::CALL, argv);
            // TODO: Push variable(s) back to stack
        }
            return;
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


void execute(const std::vector<uint8_t>& bytes, const std::vector<Constants::Constant>& constants) {
    auto runtime = Runtime(constants);
    while (runtime.currentPos() != bytes.size()) {
        auto b = static_cast<Bytecode>(bytes[runtime.currentPos()]);
        auto byteStart = runtime.currentPos() + 1;
        auto byteEnd = runtime.currentPos() + 1 + bytecode_size(b);
        std::vector<uint8_t> varBytes(bytes.begin() + byteStart, bytes.begin() + byteEnd);
        runtime.advance(bytecode_size(b) + 1);
        parse(b, varBytes, runtime);
    }
}