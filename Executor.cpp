//
// Created by Patrick Norton on 12/1/20.
//

#include "Executor.h"
#include "IntTools.h"
#include "IntUtils.h"
#include "Builtins.h"
#include "Exit.h"
#include "TempList.h"
#include "TempDict.h"

namespace Executor {
    void callOperator(Operator o, uint16_t argc, Runtime& runtime) {
        std::vector<Variable> argv = runtime.loadArgs(argc);
        auto caller = runtime.pop();
        runtime.call(caller, o, argv);
    }

    void parse(const Bytecode b, const std::vector<uint8_t> &bytes, Runtime &runtime) {
        switch (b) {

            case Bytecode::NOP:
                throw std::runtime_error("NOP not used as a value in any generated code yet, so an error occurred");
            case Bytecode::LOAD_NULL:
                runtime.push(Builtins::null());
                return;
            case Bytecode::LOAD_CONST:
                runtime.push(runtime.load_const(IntTools::bytesTo<uint16_t>(bytes)));
                return;
            case Bytecode::LOAD_VALUE:
                runtime.push(runtime.load_variable(IntTools::bytesTo<uint16_t>(bytes)));
                return;
            case Bytecode::LOAD_DOT: {
                auto dotVal = runtime.load_const(IntTools::bytesTo<uint16_t>(bytes));
                runtime.push((*runtime.pop())[{dotVal->str(&runtime), &runtime}]);
            }
                return;
            case Bytecode::LOAD_SUBSCRIPT: {
                auto operandCount = IntTools::bytesTo<uint16_t>(bytes);
                callOperator(Operator::GET_ATTR, operandCount, runtime);
            }
                return;
            case Bytecode::LOAD_OP: {
                auto top = runtime.pop();
                auto index = IntTools::bytesTo<uint16_t>(bytes);
                runtime.push(top->operator[]({static_cast<Operator>(index), &runtime}));
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
            case Bytecode::STORE_ATTR: {
                auto stored = runtime.pop();
                auto value = runtime.pop();
                auto attrName = runtime.load_const(IntTools::bytesTo<uint16_t>(bytes));
                value->set(attrName->str(&runtime), stored, &runtime);
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
                runtime.push(Constants::fromNative(
                        runtime.pop()->toBool(&runtime)
                        && runtime.pop()->toBool(&runtime)
                ));
            }
                return;
            case Bytecode::BOOL_OR: {
                runtime.push(Constants::fromNative(
                        runtime.pop()->toBool(&runtime)
                        || runtime.pop()->toBool(&runtime)
                ));
            }
                return;
            case Bytecode::BOOL_NOT:
                runtime.push(Constants::fromNative(!runtime.pop()->toBool(&runtime)));
                return;
            case Bytecode::BOOL_XOR: {
                runtime.push(Constants::fromNative(
                        runtime.pop()->toBool(&runtime)
                        ^ runtime.pop()->toBool(&runtime)
                ));
            }
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
            case Bytecode::CALL_OP: {
                static size_t index = 0;
                auto op = static_cast<Operator>(IntTools::bytesTo<uint16_t>(bytes, index));
                auto argc = IntTools::bytesTo<uint16_t>(bytes, index);
                auto argv = runtime.loadArgs(argc);
                runtime.call(runtime.pop(), op, argv);
            }
                return;
            case Bytecode::PACK_TUPLE:
                break;
            case Bytecode::UNPACK_TUPLE:
                break;
            case Bytecode::EQUAL:
                callOperator(Operator::EQUALS, 1, runtime);
                return;
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
            case Bytecode::CONTAINS:
                callOperator(Operator::IN, 1, runtime);
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
                if (runtime.pop() != Builtins::null()) {
                    runtime.goTo(IntTools::bytesTo<uint32_t>(bytes));
                }
                return;
            case Bytecode::JUMP_NULL:
                if (runtime.pop() == Builtins::null()) {
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
                runtime.popStack();
                return;
            case Bytecode::THROW: {
                runtime.throwExc(runtime.pop());
            }
                return;
            case Bytecode::THROW_QUICK: {
                auto message = runtime.pop();
                auto excType = runtime.pop();
                runtime.throwQuick(std::dynamic_pointer_cast<Constants::_Type>(excType), message->str(&runtime));
            }
                return;
            case Bytecode::ENTER_TRY: {
                auto excPos = IntTools::bytesTo<uint32_t>(bytes);
                while (static_cast<Bytecode>(runtime.currentFn()[excPos]) == Bytecode::EXCEPT_N) {
                    excPos++;
                    auto excType = runtime.load_const(IntTools::bytesTo<uint32_t>(runtime.currentFn(), excPos));
                    runtime.addExceptionHandler(excType, excPos);
                }
            }
                return;
            case Bytecode::EXCEPT_N:
                break;
            case Bytecode::FINALLY:
                break;
            case Bytecode::END_TRY: {
                auto count = IntTools::bytesTo<uint16_t>(bytes);
                for (uint16_t i = 0; i < count; i++) {
                    runtime.popHandler();  // FIXME: Pop the correct # of handlers when they are pre-popped through throw
                }
            }
                return;
            case Bytecode::FUNC_DEF:
                break;
            case Bytecode::CLASS_DEF:
                break;
            case Bytecode::END_CLASS:
                break;
            case Bytecode::FOR_ITER: {
                auto iterated = runtime.pop();
                auto jumpLoc = IntTools::bytesTo<uint32_t>(bytes);
                runtime.addExceptionHandler(Builtins::stopIteration(), jumpLoc);
                runtime.call(iterated, "next", {});
                if (runtime.currentPos() != jumpLoc) {
                    runtime.popHandler();
                    auto arg = runtime.pop();
                    runtime.push(iterated);
                    runtime.push(arg);
                }
            }
                return;
            case Bytecode::LIST_CREATE: {
                auto argc = IntTools::bytesTo<uint16_t>(bytes);
                runtime.push(Builtins::list()->createNew(runtime.loadArgs(argc), &runtime));
            }
                return;
            case Bytecode::SET_CREATE: {
                auto argc = IntTools::bytesTo<uint16_t>(bytes);
                runtime.push(Builtins::set()->createNew(runtime.loadArgs(argc), &runtime));
            }
                return;
            case Bytecode::DICT_CREATE: {
                auto count = IntTools::bytesTo<uint16_t>(bytes);
                std::vector<Variable> keys(count);
                std::vector<Variable> values(count);
                for (size_t i = 0; i < count; i++) {
                    values[count - i - 1] = runtime.pop();
                    keys[count - i - 1] = runtime.pop();
                }
                runtime.push(std::make_shared<TempDict>(keys, values, &runtime));
            }
                return;
            case Bytecode::LIST_ADD: {
                auto added = runtime.pop();
                auto list = runtime.pop();
                runtime.call(list, "add", {added});
                runtime.push(list);
            }
                return;
            case Bytecode::SET_ADD: {
                auto added = runtime.pop();
                auto set = runtime.pop();
                runtime.call(set, "add", {added});
                runtime.push(set);
            }
                return;
            case Bytecode::DICT_ADD: {
                auto value = runtime.pop();
                auto key = runtime.pop();
                auto dict = runtime.pop();
                runtime.call(dict, Operator::SET_ATTR, {key, value});
                runtime.push(dict);
            }
                return;
            case Bytecode::DOTIMES: {
                auto value = runtime.pop()->toInt(&runtime);
                auto jump = IntTools::bytesTo<uint32_t>(bytes);
                if (!value) {
                    runtime.goTo(jump);
                } else {
                    runtime.push(Constants::fromNative(--value));
                }
            }
                return;
            case Bytecode::LOAD_FUNCTION: {
                size_t i = 0;
                auto fnIndex = IntTools::bytesTo<uint16_t>(bytes, i);
                runtime.push(runtime.loadFn(fnIndex));
            }
                return;
        }
        throw std::runtime_error("Bytecode not implemented yet");
    }

    void execute(Runtime& runtime) {
        try {
            while (!runtime.isNative() && runtime.currentPos() != runtime.currentFn().size()) {
                try {
                    auto& bytes = runtime.currentFn();
                    auto b = static_cast<Bytecode>(bytes[runtime.currentPos()]);
                    auto byteStart = runtime.currentPos() + 1;
                    auto byteEnd = runtime.currentPos() + 1 + bytecode_size(b);
                    std::vector<uint8_t> varBytes(bytes.begin() + byteStart, bytes.begin() + byteEnd);
                    runtime.advance(bytecode_size(b) + 1);
                    parse(b, varBytes, runtime);
                } catch (NativeExc& error) {
                    runtime.throwQuick(error.getType(), error.getMessage());
                }
                if (runtime.currentPos() == runtime.currentFn().size() && !runtime.isBottomOfStack()) {
                    runtime.popStack();
                }
            }
        } catch (ThrownExc& error) {
            assert(runtime.isNative());
            runtime.popStack();
            runtime.throwQuick(error.getType(), error.getMessage());
        }
    }
}