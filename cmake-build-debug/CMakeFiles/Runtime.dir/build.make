# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/patricknorton/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/patricknorton/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/patricknorton/CLionProjects/Runtime

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/patricknorton/CLionProjects/Runtime/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Runtime.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Runtime.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Runtime.dir/flags.make

CMakeFiles/Runtime.dir/main.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Runtime.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/main.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/main.cpp

CMakeFiles/Runtime.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/main.cpp > CMakeFiles/Runtime.dir/main.cpp.i

CMakeFiles/Runtime.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/main.cpp -o CMakeFiles/Runtime.dir/main.cpp.s

CMakeFiles/Runtime.dir/Bytecode.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/Bytecode.cpp.o: ../Bytecode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Runtime.dir/Bytecode.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/Bytecode.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/Bytecode.cpp

CMakeFiles/Runtime.dir/Bytecode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/Bytecode.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/Bytecode.cpp > CMakeFiles/Runtime.dir/Bytecode.cpp.i

CMakeFiles/Runtime.dir/Bytecode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/Bytecode.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/Bytecode.cpp -o CMakeFiles/Runtime.dir/Bytecode.cpp.s

CMakeFiles/Runtime.dir/Runtime.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/Runtime.cpp.o: ../Runtime.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Runtime.dir/Runtime.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/Runtime.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/Runtime.cpp

CMakeFiles/Runtime.dir/Runtime.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/Runtime.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/Runtime.cpp > CMakeFiles/Runtime.dir/Runtime.cpp.i

CMakeFiles/Runtime.dir/Runtime.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/Runtime.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/Runtime.cpp -o CMakeFiles/Runtime.dir/Runtime.cpp.s

CMakeFiles/Runtime.dir/Variable.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/Variable.cpp.o: ../Variable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Runtime.dir/Variable.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/Variable.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/Variable.cpp

CMakeFiles/Runtime.dir/Variable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/Variable.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/Variable.cpp > CMakeFiles/Runtime.dir/Variable.cpp.i

CMakeFiles/Runtime.dir/Variable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/Variable.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/Variable.cpp -o CMakeFiles/Runtime.dir/Variable.cpp.s

CMakeFiles/Runtime.dir/Builtins.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/Builtins.cpp.o: ../Builtins.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Runtime.dir/Builtins.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/Builtins.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/Builtins.cpp

CMakeFiles/Runtime.dir/Builtins.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/Builtins.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/Builtins.cpp > CMakeFiles/Runtime.dir/Builtins.cpp.i

CMakeFiles/Runtime.dir/Builtins.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/Builtins.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/Builtins.cpp -o CMakeFiles/Runtime.dir/Builtins.cpp.s

CMakeFiles/Runtime.dir/Executor.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/Executor.cpp.o: ../Executor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Runtime.dir/Executor.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/Executor.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/Executor.cpp

CMakeFiles/Runtime.dir/Executor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/Executor.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/Executor.cpp > CMakeFiles/Runtime.dir/Executor.cpp.i

CMakeFiles/Runtime.dir/Executor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/Executor.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/Executor.cpp -o CMakeFiles/Runtime.dir/Executor.cpp.s

CMakeFiles/Runtime.dir/IntTools.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/IntTools.cpp.o: ../IntTools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Runtime.dir/IntTools.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/IntTools.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/IntTools.cpp

CMakeFiles/Runtime.dir/IntTools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/IntTools.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/IntTools.cpp > CMakeFiles/Runtime.dir/IntTools.cpp.i

CMakeFiles/Runtime.dir/IntTools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/IntTools.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/IntTools.cpp -o CMakeFiles/Runtime.dir/IntTools.cpp.s

CMakeFiles/Runtime.dir/Operator.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/Operator.cpp.o: ../Operator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Runtime.dir/Operator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/Operator.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/Operator.cpp

CMakeFiles/Runtime.dir/Operator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/Operator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/Operator.cpp > CMakeFiles/Runtime.dir/Operator.cpp.i

CMakeFiles/Runtime.dir/Operator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/Operator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/Operator.cpp -o CMakeFiles/Runtime.dir/Operator.cpp.s

CMakeFiles/Runtime.dir/BuiltinImpl.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/BuiltinImpl.cpp.o: ../BuiltinImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Runtime.dir/BuiltinImpl.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/BuiltinImpl.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/BuiltinImpl.cpp

CMakeFiles/Runtime.dir/BuiltinImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/BuiltinImpl.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/BuiltinImpl.cpp > CMakeFiles/Runtime.dir/BuiltinImpl.cpp.i

CMakeFiles/Runtime.dir/BuiltinImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/BuiltinImpl.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/BuiltinImpl.cpp -o CMakeFiles/Runtime.dir/BuiltinImpl.cpp.s

CMakeFiles/Runtime.dir/FileParsing.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/FileParsing.cpp.o: ../FileParsing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Runtime.dir/FileParsing.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/FileParsing.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/FileParsing.cpp

CMakeFiles/Runtime.dir/FileParsing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/FileParsing.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/FileParsing.cpp > CMakeFiles/Runtime.dir/FileParsing.cpp.i

CMakeFiles/Runtime.dir/FileParsing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/FileParsing.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/FileParsing.cpp -o CMakeFiles/Runtime.dir/FileParsing.cpp.s

CMakeFiles/Runtime.dir/FileInfo.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/FileInfo.cpp.o: ../FileInfo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Runtime.dir/FileInfo.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/FileInfo.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/FileInfo.cpp

CMakeFiles/Runtime.dir/FileInfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/FileInfo.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/FileInfo.cpp > CMakeFiles/Runtime.dir/FileInfo.cpp.i

CMakeFiles/Runtime.dir/FileInfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/FileInfo.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/FileInfo.cpp -o CMakeFiles/Runtime.dir/FileInfo.cpp.s

CMakeFiles/Runtime.dir/Constant.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/Constant.cpp.o: ../Constant.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Runtime.dir/Constant.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/Constant.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/Constant.cpp

CMakeFiles/Runtime.dir/Constant.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/Constant.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/Constant.cpp > CMakeFiles/Runtime.dir/Constant.cpp.i

CMakeFiles/Runtime.dir/Constant.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/Constant.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/Constant.cpp -o CMakeFiles/Runtime.dir/Constant.cpp.s

CMakeFiles/Runtime.dir/ConstantLoaders.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/ConstantLoaders.cpp.o: ../ConstantLoaders.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Runtime.dir/ConstantLoaders.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/ConstantLoaders.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/ConstantLoaders.cpp

CMakeFiles/Runtime.dir/ConstantLoaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/ConstantLoaders.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/ConstantLoaders.cpp > CMakeFiles/Runtime.dir/ConstantLoaders.cpp.i

CMakeFiles/Runtime.dir/ConstantLoaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/ConstantLoaders.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/ConstantLoaders.cpp -o CMakeFiles/Runtime.dir/ConstantLoaders.cpp.s

CMakeFiles/Runtime.dir/Bigint.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/Bigint.cpp.o: ../Bigint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Runtime.dir/Bigint.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/Bigint.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/Bigint.cpp

CMakeFiles/Runtime.dir/Bigint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/Bigint.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/Bigint.cpp > CMakeFiles/Runtime.dir/Bigint.cpp.i

CMakeFiles/Runtime.dir/Bigint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/Bigint.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/Bigint.cpp -o CMakeFiles/Runtime.dir/Bigint.cpp.s

CMakeFiles/Runtime.dir/StdVariable.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/StdVariable.cpp.o: ../StdVariable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Runtime.dir/StdVariable.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/StdVariable.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/StdVariable.cpp

CMakeFiles/Runtime.dir/StdVariable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/StdVariable.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/StdVariable.cpp > CMakeFiles/Runtime.dir/StdVariable.cpp.i

CMakeFiles/Runtime.dir/StdVariable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/StdVariable.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/StdVariable.cpp -o CMakeFiles/Runtime.dir/StdVariable.cpp.s

CMakeFiles/Runtime.dir/Type.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/Type.cpp.o: ../Type.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Runtime.dir/Type.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/Type.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/Type.cpp

CMakeFiles/Runtime.dir/Type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/Type.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/Type.cpp > CMakeFiles/Runtime.dir/Type.cpp.i

CMakeFiles/Runtime.dir/Type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/Type.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/Type.cpp -o CMakeFiles/Runtime.dir/Type.cpp.s

CMakeFiles/Runtime.dir/Callable.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/Callable.cpp.o: ../Callable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/Runtime.dir/Callable.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/Callable.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/Callable.cpp

CMakeFiles/Runtime.dir/Callable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/Callable.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/Callable.cpp > CMakeFiles/Runtime.dir/Callable.cpp.i

CMakeFiles/Runtime.dir/Callable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/Callable.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/Callable.cpp -o CMakeFiles/Runtime.dir/Callable.cpp.s

CMakeFiles/Runtime.dir/StringUtils.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/StringUtils.cpp.o: ../StringUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/Runtime.dir/StringUtils.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/StringUtils.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/StringUtils.cpp

CMakeFiles/Runtime.dir/StringUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/StringUtils.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/StringUtils.cpp > CMakeFiles/Runtime.dir/StringUtils.cpp.i

CMakeFiles/Runtime.dir/StringUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/StringUtils.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/StringUtils.cpp -o CMakeFiles/Runtime.dir/StringUtils.cpp.s

CMakeFiles/Runtime.dir/IntUtils.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/IntUtils.cpp.o: ../IntUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/Runtime.dir/IntUtils.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/IntUtils.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/IntUtils.cpp

CMakeFiles/Runtime.dir/IntUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/IntUtils.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/IntUtils.cpp > CMakeFiles/Runtime.dir/IntUtils.cpp.i

CMakeFiles/Runtime.dir/IntUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/IntUtils.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/IntUtils.cpp -o CMakeFiles/Runtime.dir/IntUtils.cpp.s

CMakeFiles/Runtime.dir/BigDecimal.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/BigDecimal.cpp.o: ../BigDecimal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/Runtime.dir/BigDecimal.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/BigDecimal.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/BigDecimal.cpp

CMakeFiles/Runtime.dir/BigDecimal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/BigDecimal.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/BigDecimal.cpp > CMakeFiles/Runtime.dir/BigDecimal.cpp.i

CMakeFiles/Runtime.dir/BigDecimal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/BigDecimal.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/BigDecimal.cpp -o CMakeFiles/Runtime.dir/BigDecimal.cpp.s

CMakeFiles/Runtime.dir/StandardFunction.cpp.o: CMakeFiles/Runtime.dir/flags.make
CMakeFiles/Runtime.dir/StandardFunction.cpp.o: ../StandardFunction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object CMakeFiles/Runtime.dir/StandardFunction.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Runtime.dir/StandardFunction.cpp.o -c /Users/patricknorton/CLionProjects/Runtime/StandardFunction.cpp

CMakeFiles/Runtime.dir/StandardFunction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Runtime.dir/StandardFunction.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patricknorton/CLionProjects/Runtime/StandardFunction.cpp > CMakeFiles/Runtime.dir/StandardFunction.cpp.i

CMakeFiles/Runtime.dir/StandardFunction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Runtime.dir/StandardFunction.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patricknorton/CLionProjects/Runtime/StandardFunction.cpp -o CMakeFiles/Runtime.dir/StandardFunction.cpp.s

# Object files for target Runtime
Runtime_OBJECTS = \
"CMakeFiles/Runtime.dir/main.cpp.o" \
"CMakeFiles/Runtime.dir/Bytecode.cpp.o" \
"CMakeFiles/Runtime.dir/Runtime.cpp.o" \
"CMakeFiles/Runtime.dir/Variable.cpp.o" \
"CMakeFiles/Runtime.dir/Builtins.cpp.o" \
"CMakeFiles/Runtime.dir/Executor.cpp.o" \
"CMakeFiles/Runtime.dir/IntTools.cpp.o" \
"CMakeFiles/Runtime.dir/Operator.cpp.o" \
"CMakeFiles/Runtime.dir/BuiltinImpl.cpp.o" \
"CMakeFiles/Runtime.dir/FileParsing.cpp.o" \
"CMakeFiles/Runtime.dir/FileInfo.cpp.o" \
"CMakeFiles/Runtime.dir/Constant.cpp.o" \
"CMakeFiles/Runtime.dir/ConstantLoaders.cpp.o" \
"CMakeFiles/Runtime.dir/Bigint.cpp.o" \
"CMakeFiles/Runtime.dir/StdVariable.cpp.o" \
"CMakeFiles/Runtime.dir/Type.cpp.o" \
"CMakeFiles/Runtime.dir/Callable.cpp.o" \
"CMakeFiles/Runtime.dir/StringUtils.cpp.o" \
"CMakeFiles/Runtime.dir/IntUtils.cpp.o" \
"CMakeFiles/Runtime.dir/BigDecimal.cpp.o" \
"CMakeFiles/Runtime.dir/StandardFunction.cpp.o"

# External object files for target Runtime
Runtime_EXTERNAL_OBJECTS =

Runtime: CMakeFiles/Runtime.dir/main.cpp.o
Runtime: CMakeFiles/Runtime.dir/Bytecode.cpp.o
Runtime: CMakeFiles/Runtime.dir/Runtime.cpp.o
Runtime: CMakeFiles/Runtime.dir/Variable.cpp.o
Runtime: CMakeFiles/Runtime.dir/Builtins.cpp.o
Runtime: CMakeFiles/Runtime.dir/Executor.cpp.o
Runtime: CMakeFiles/Runtime.dir/IntTools.cpp.o
Runtime: CMakeFiles/Runtime.dir/Operator.cpp.o
Runtime: CMakeFiles/Runtime.dir/BuiltinImpl.cpp.o
Runtime: CMakeFiles/Runtime.dir/FileParsing.cpp.o
Runtime: CMakeFiles/Runtime.dir/FileInfo.cpp.o
Runtime: CMakeFiles/Runtime.dir/Constant.cpp.o
Runtime: CMakeFiles/Runtime.dir/ConstantLoaders.cpp.o
Runtime: CMakeFiles/Runtime.dir/Bigint.cpp.o
Runtime: CMakeFiles/Runtime.dir/StdVariable.cpp.o
Runtime: CMakeFiles/Runtime.dir/Type.cpp.o
Runtime: CMakeFiles/Runtime.dir/Callable.cpp.o
Runtime: CMakeFiles/Runtime.dir/StringUtils.cpp.o
Runtime: CMakeFiles/Runtime.dir/IntUtils.cpp.o
Runtime: CMakeFiles/Runtime.dir/BigDecimal.cpp.o
Runtime: CMakeFiles/Runtime.dir/StandardFunction.cpp.o
Runtime: CMakeFiles/Runtime.dir/build.make
Runtime: CMakeFiles/Runtime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Linking CXX executable Runtime"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Runtime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Runtime.dir/build: Runtime

.PHONY : CMakeFiles/Runtime.dir/build

CMakeFiles/Runtime.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Runtime.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Runtime.dir/clean

CMakeFiles/Runtime.dir/depend:
	cd /Users/patricknorton/CLionProjects/Runtime/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/patricknorton/CLionProjects/Runtime /Users/patricknorton/CLionProjects/Runtime /Users/patricknorton/CLionProjects/Runtime/cmake-build-debug /Users/patricknorton/CLionProjects/Runtime/cmake-build-debug /Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles/Runtime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Runtime.dir/depend

