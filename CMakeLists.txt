cmake_minimum_required(VERSION 3.15)
project(Runtime)

set(CMAKE_CXX_STANDARD 14)

add_executable(Runtime main.cpp Bytecode.cpp Bytecode.h Runtime.cpp Runtime.h Variable.cpp Variable.h)