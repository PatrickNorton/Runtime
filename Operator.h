//
// Created by Patrick Norton on 12/1/20.
//

#ifndef RUNTIME_OPERATOR_H
#define RUNTIME_OPERATOR_H


enum class Operator {
    ADD,
    SUBTRACT,
    U_SUBTRACT,
    MULTIPLY,
    DIVIDE,
    FLOOR_DIV,
    POWER,
    EQUALS,
    NOT_EQUALS,
    GREATER_THAN,
    LESS_THAN,
    GREATER_EQUAL,
    LESS_EQUAL,
    LEFT_BITSHIFT,
    RIGHT_BITSHIFT,
    BITWISE_AND,
    BITWISE_OR,
    BITWISE_XOR,
    BITWISE_NOT,
    MODULO,
    BOOL_AND,
    BOOL_OR,
    BOOL_NOT,
    BOOL_XOR,
    IN,
    NOT_IN,
    CASTED,
    IS,
    IS_NOT,
    NULL_COERCE,
    NOT_NULL,
    OPTIONAL,
    INSTANCEOF,
    NOT_INSTANCEOF,
    SET_ATTR,
    SET_SLICE,
    GET_ATTR,
    GET_SLICE,
    DEL_ATTR,
    DEL_SLICE,
    COMPARE,
    CALL,
    STR,
    INT,
    BOOL,
    ITER,
    NEW,
};


#endif //RUNTIME_OPERATOR_H
