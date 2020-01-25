//
// Created by Patrick Norton on 12/1/20.
//

#include "Executor.h"
#include "IntTools.h"
#include "IntUtils.h"
#include "Type.h"

namespace Executor {
    void callOperator(Operator o, uint16_t argc, Runtime& runtime) {
        std::vector<Variable> argv = runtime.loadArgs(argc);
        auto caller = runtime.pop();
        runtime.call(caller, o, argv);
    }

    void parse(const Bytecode b, const std::vector<uint8_t> &bytes, Runtime &runtime) {
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
                callOperator(Operator::GET_ATTR, operandCount, runtime);
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
                runtime.push(popped[swapped - 1]);
            }
                return;
            case Bytecode::STORE:
                runtime.store_variable(IntTools::bytesTo<uint16_t>(bytes), runtime.pop());
                return;
            case Bytecode::STORE_SUBSCRIPT: {
                auto result = runtime.pop();
                auto index = runtime.pop();
                auto stored = runtime.pop();
                runtime.call(stored, Operator::SET_ATTR, {index, result});
            }
                return;
            case Bytecode::PLUS:
                callOperator(Operator::ADD, 1, runtime);
                return;
            case Bytecode::MINUS:
                callOperator(Operator::SUBTRACT, 1, runtime);
                return;
            case Bytecode::TIMES:
                callOperator(Operator::MULTIPLY, 1, runtime);
                return;
            case Bytecode::DIVIDE:
                callOperator(Operator::DIVIDE, 1, runtime);
                return;
            case Bytecode::MOD:
                callOperator(Operator::MODULO, 1, runtime);
                return;
            case Bytecode::SUBSCRIPT:
                callOperator(Operator::GET_ATTR, 1, runtime);
                return;
            case Bytecode::POWER:
                callOperator(Operator::POWER, 1, runtime);
                return;
            case Bytecode::L_BITSHIFT:
                callOperator(Operator::LEFT_BITSHIFT, 1, runtime);
                return;
            case Bytecode::R_BITSHIFT:
                callOperator(Operator::RIGHT_BITSHIFT, 1, runtime);
                return;
            case Bytecode::BITWISE_AND:
                callOperator(Operator::BITWISE_AND, 1, runtime);
                return;
            case Bytecode::BITWISE_OR:
                callOperator(Operator::BITWISE_OR, 1, runtime);
                return;
            case Bytecode::BITWISE_XOR:
                callOperator(Operator::BITWISE_XOR, 1, runtime);
                return;
            case Bytecode::COMPARE:
                callOperator(Operator::COMPARE, 1, runtime);
                return;
            case Bytecode::DEL_SUBSCRIPT:
                callOperator(Operator::DEL_ATTR, 2, runtime);
                return;
            case Bytecode::U_MINUS:
                callOperator(Operator::U_SUBTRACT, 0, runtime);
                return;
            case Bytecode::BITWISE_NOT:
                callOperator(Operator::BITWISE_NOT, 0, runtime);
                return;
            case Bytecode::BOOL_AND: {
                auto arg1 = runtime.pop()->toBool(&runtime);
                auto arg2 = runtime.pop()->toBool(&runtime);
                runtime.push(Constants::fromNative(arg2 && arg1));
            }
                return;
            case Bytecode::BOOL_OR: {
                auto arg1 = runtime.pop()->toBool(&runtime);
                auto arg2 = runtime.pop()->toBool(&runtime);
                runtime.push(Constants::fromNative(arg2 || arg1));
            }
                return;
            case Bytecode::BOOL_NOT:
                runtime.push(Constants::fromNative(!runtime.pop()->toBool(&runtime)));
                return;
            case Bytecode::IDENTICAL: {
                Variable x = runtime.pop();
                Variable y = runtime.pop();
                runtime.push(Constants::fromNative(x == y));
            }
                return;
            case Bytecode::INSTANCEOF: {
                Variable x = runtime.pop();
                Variable y = runtime.pop();
                runtime.push(Constants::fromNative(y->isTypeOf(x)));
            }
                return;
            case Bytecode::CALL_OP:
                break;
            case Bytecode::PACK_TUPLE:
                break;
            case Bytecode::UNPACK_TUPLE:
                break;
            case Bytecode::EQUAL:
                callOperator(Operator::EQUALS, 1, runtime);
                break;
            case Bytecode::LESS_THAN:
                callOperator(Operator::LESS_THAN, 1, runtime);
                return;
            case Bytecode::GREATER_THAN:
                callOperator(Operator::GREATER_THAN, 1, runtime);
                return;
            case Bytecode::LESS_EQUAL:
                callOperator(Operator::LESS_EQUAL, 1, runtime);
                return;
            case Bytecode::GREATER_EQUAL:
                callOperator(Operator::GREATER_EQUAL, 1, runtime);
                return;
            case Bytecode::JUMP:
                runtime.goTo(IntTools::bytesTo<uint32_t>(bytes));
                return;
            case Bytecode::JUMP_FALSE:
                if (!runtime.pop()->toBool(&runtime)) {
                    runtime.goTo(IntTools::bytesTo<uint32_t>(bytes));
                }
                return;
            case Bytecode::JUMP_TRUE:
                if (runtime.pop()->toBool(&runtime)) {
                    runtime.goTo(IntTools::bytesTo<uint32_t>(bytes));
                }
                return;
            case Bytecode::JUMP_NN:
                if (runtime.pop() == Constants::null()) {
                    runtime.goTo(IntTools::bytesTo<uint32_t>(bytes));
                }
                return;
            case Bytecode::CALL_METHOD:
                break;
            case Bytecode::CALL_TOS: {
                auto argc = IntTools::bytesTo<uint16_t>(bytes);
                runtime.call(argc);
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

    void execute(const std::vector<uint8_t> &bytes, const std::vector<Constants::Constant> &constants) {
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
}