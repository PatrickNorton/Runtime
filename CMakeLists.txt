cmake_minimum_required(VERSION 3.15)
project(Runtime)

set(CMAKE_CXX_STANDARD 14)

add_executable(Runtime main.cpp Bytecode.cpp Bytecode.h Runtime.cpp Runtime.h Variable.cpp Variable.h Builtins.h Builtins.cpp Executor.cpp Executor.h IntTools.cpp IntTools.h Operator.cpp Operator.h BuiltinImpl.cpp BuiltinImpl.h)