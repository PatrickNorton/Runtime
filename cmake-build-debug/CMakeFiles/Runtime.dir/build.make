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
"CMakeFiles/Runtime.dir/BuiltinImpl.cpp.o"

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
Runtime: CMakeFiles/Runtime.dir/build.make
Runtime: CMakeFiles/Runtime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/patricknorton/CLionProjects/Runtime/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Runtime"
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

