cmake_minimum_required(VERSION 3.15)
project(Runtime)

set(CMAKE_CXX_STANDARD 14)

add_executable(Runtime main.cpp Bytecode.cpp Bytecode.h Runtime.cpp Runtime.h Variable.cpp Variable.h Builtins.h Builtins.cpp Executor.cpp Executor.h IntTools.inl IntTools.h Operator.cpp Operator.h BuiltinImpl.cpp BuiltinImpl.h FileParsing.cpp FileParsing.h FileInfo.cpp FileInfo.h Constants.h Constant.cpp Constant.h ConstantBytes.h ConstantLoaders.cpp ConstantLoaders.h Bigint.cpp Bigint.h StdVariable.cpp StdVariable.h Type.cpp Type.h StringUtils.cpp StringUtils.h IntUtils.cpp IntUtils.h BigDecimal.cpp BigDecimal.h Function.cpp Function.h Method.h StackFrame.cpp StackFrame.h BaseFunction.cpp BaseFunction.h Tuple.cpp Tuple.h Exception.cpp Exception.h Range.cpp Range.h Exit.h ObjectIterator.cpp ObjectIterator.h TempList.cpp TempList.h TempSet.cpp TempSet.h TempDict.cpp TempDict.h DictUtils.h DictUtils.cpp CharUtils.cpp CharUtils.h Integer.cpp Integer.h)