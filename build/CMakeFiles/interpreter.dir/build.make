# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nick/AsmEmulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/AsmEmulator/build

# Include any dependencies generated for this target.
include CMakeFiles/interpreter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/interpreter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/interpreter.dir/flags.make

CMakeFiles/interpreter.dir/AsmEmulator/main.cpp.o: CMakeFiles/interpreter.dir/flags.make
CMakeFiles/interpreter.dir/AsmEmulator/main.cpp.o: ../AsmEmulator/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/AsmEmulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/interpreter.dir/AsmEmulator/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpreter.dir/AsmEmulator/main.cpp.o -c /home/nick/AsmEmulator/AsmEmulator/main.cpp

CMakeFiles/interpreter.dir/AsmEmulator/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpreter.dir/AsmEmulator/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/AsmEmulator/AsmEmulator/main.cpp > CMakeFiles/interpreter.dir/AsmEmulator/main.cpp.i

CMakeFiles/interpreter.dir/AsmEmulator/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpreter.dir/AsmEmulator/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/AsmEmulator/AsmEmulator/main.cpp -o CMakeFiles/interpreter.dir/AsmEmulator/main.cpp.s

CMakeFiles/interpreter.dir/AsmEmulator/reader.cpp.o: CMakeFiles/interpreter.dir/flags.make
CMakeFiles/interpreter.dir/AsmEmulator/reader.cpp.o: ../AsmEmulator/reader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/AsmEmulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/interpreter.dir/AsmEmulator/reader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpreter.dir/AsmEmulator/reader.cpp.o -c /home/nick/AsmEmulator/AsmEmulator/reader.cpp

CMakeFiles/interpreter.dir/AsmEmulator/reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpreter.dir/AsmEmulator/reader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/AsmEmulator/AsmEmulator/reader.cpp > CMakeFiles/interpreter.dir/AsmEmulator/reader.cpp.i

CMakeFiles/interpreter.dir/AsmEmulator/reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpreter.dir/AsmEmulator/reader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/AsmEmulator/AsmEmulator/reader.cpp -o CMakeFiles/interpreter.dir/AsmEmulator/reader.cpp.s

CMakeFiles/interpreter.dir/AsmEmulator/instruction_set.cpp.o: CMakeFiles/interpreter.dir/flags.make
CMakeFiles/interpreter.dir/AsmEmulator/instruction_set.cpp.o: ../AsmEmulator/instruction_set.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/AsmEmulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/interpreter.dir/AsmEmulator/instruction_set.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpreter.dir/AsmEmulator/instruction_set.cpp.o -c /home/nick/AsmEmulator/AsmEmulator/instruction_set.cpp

CMakeFiles/interpreter.dir/AsmEmulator/instruction_set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpreter.dir/AsmEmulator/instruction_set.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/AsmEmulator/AsmEmulator/instruction_set.cpp > CMakeFiles/interpreter.dir/AsmEmulator/instruction_set.cpp.i

CMakeFiles/interpreter.dir/AsmEmulator/instruction_set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpreter.dir/AsmEmulator/instruction_set.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/AsmEmulator/AsmEmulator/instruction_set.cpp -o CMakeFiles/interpreter.dir/AsmEmulator/instruction_set.cpp.s

CMakeFiles/interpreter.dir/AsmEmulator/translator.cpp.o: CMakeFiles/interpreter.dir/flags.make
CMakeFiles/interpreter.dir/AsmEmulator/translator.cpp.o: ../AsmEmulator/translator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/AsmEmulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/interpreter.dir/AsmEmulator/translator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpreter.dir/AsmEmulator/translator.cpp.o -c /home/nick/AsmEmulator/AsmEmulator/translator.cpp

CMakeFiles/interpreter.dir/AsmEmulator/translator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpreter.dir/AsmEmulator/translator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/AsmEmulator/AsmEmulator/translator.cpp > CMakeFiles/interpreter.dir/AsmEmulator/translator.cpp.i

CMakeFiles/interpreter.dir/AsmEmulator/translator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpreter.dir/AsmEmulator/translator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/AsmEmulator/AsmEmulator/translator.cpp -o CMakeFiles/interpreter.dir/AsmEmulator/translator.cpp.s

CMakeFiles/interpreter.dir/AsmEmulator/vm/vm.cpp.o: CMakeFiles/interpreter.dir/flags.make
CMakeFiles/interpreter.dir/AsmEmulator/vm/vm.cpp.o: ../AsmEmulator/vm/vm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/AsmEmulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/interpreter.dir/AsmEmulator/vm/vm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpreter.dir/AsmEmulator/vm/vm.cpp.o -c /home/nick/AsmEmulator/AsmEmulator/vm/vm.cpp

CMakeFiles/interpreter.dir/AsmEmulator/vm/vm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpreter.dir/AsmEmulator/vm/vm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/AsmEmulator/AsmEmulator/vm/vm.cpp > CMakeFiles/interpreter.dir/AsmEmulator/vm/vm.cpp.i

CMakeFiles/interpreter.dir/AsmEmulator/vm/vm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpreter.dir/AsmEmulator/vm/vm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/AsmEmulator/AsmEmulator/vm/vm.cpp -o CMakeFiles/interpreter.dir/AsmEmulator/vm/vm.cpp.s

CMakeFiles/interpreter.dir/AsmEmulator/vm/cpu.cpp.o: CMakeFiles/interpreter.dir/flags.make
CMakeFiles/interpreter.dir/AsmEmulator/vm/cpu.cpp.o: ../AsmEmulator/vm/cpu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/AsmEmulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/interpreter.dir/AsmEmulator/vm/cpu.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpreter.dir/AsmEmulator/vm/cpu.cpp.o -c /home/nick/AsmEmulator/AsmEmulator/vm/cpu.cpp

CMakeFiles/interpreter.dir/AsmEmulator/vm/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpreter.dir/AsmEmulator/vm/cpu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/AsmEmulator/AsmEmulator/vm/cpu.cpp > CMakeFiles/interpreter.dir/AsmEmulator/vm/cpu.cpp.i

CMakeFiles/interpreter.dir/AsmEmulator/vm/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpreter.dir/AsmEmulator/vm/cpu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/AsmEmulator/AsmEmulator/vm/cpu.cpp -o CMakeFiles/interpreter.dir/AsmEmulator/vm/cpu.cpp.s

CMakeFiles/interpreter.dir/AsmEmulator/vm/memory.cpp.o: CMakeFiles/interpreter.dir/flags.make
CMakeFiles/interpreter.dir/AsmEmulator/vm/memory.cpp.o: ../AsmEmulator/vm/memory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/AsmEmulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/interpreter.dir/AsmEmulator/vm/memory.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpreter.dir/AsmEmulator/vm/memory.cpp.o -c /home/nick/AsmEmulator/AsmEmulator/vm/memory.cpp

CMakeFiles/interpreter.dir/AsmEmulator/vm/memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpreter.dir/AsmEmulator/vm/memory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/AsmEmulator/AsmEmulator/vm/memory.cpp > CMakeFiles/interpreter.dir/AsmEmulator/vm/memory.cpp.i

CMakeFiles/interpreter.dir/AsmEmulator/vm/memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpreter.dir/AsmEmulator/vm/memory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/AsmEmulator/AsmEmulator/vm/memory.cpp -o CMakeFiles/interpreter.dir/AsmEmulator/vm/memory.cpp.s

# Object files for target interpreter
interpreter_OBJECTS = \
"CMakeFiles/interpreter.dir/AsmEmulator/main.cpp.o" \
"CMakeFiles/interpreter.dir/AsmEmulator/reader.cpp.o" \
"CMakeFiles/interpreter.dir/AsmEmulator/instruction_set.cpp.o" \
"CMakeFiles/interpreter.dir/AsmEmulator/translator.cpp.o" \
"CMakeFiles/interpreter.dir/AsmEmulator/vm/vm.cpp.o" \
"CMakeFiles/interpreter.dir/AsmEmulator/vm/cpu.cpp.o" \
"CMakeFiles/interpreter.dir/AsmEmulator/vm/memory.cpp.o"

# External object files for target interpreter
interpreter_EXTERNAL_OBJECTS =

interpreter: CMakeFiles/interpreter.dir/AsmEmulator/main.cpp.o
interpreter: CMakeFiles/interpreter.dir/AsmEmulator/reader.cpp.o
interpreter: CMakeFiles/interpreter.dir/AsmEmulator/instruction_set.cpp.o
interpreter: CMakeFiles/interpreter.dir/AsmEmulator/translator.cpp.o
interpreter: CMakeFiles/interpreter.dir/AsmEmulator/vm/vm.cpp.o
interpreter: CMakeFiles/interpreter.dir/AsmEmulator/vm/cpu.cpp.o
interpreter: CMakeFiles/interpreter.dir/AsmEmulator/vm/memory.cpp.o
interpreter: CMakeFiles/interpreter.dir/build.make
interpreter: CMakeFiles/interpreter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nick/AsmEmulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable interpreter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/interpreter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/interpreter.dir/build: interpreter

.PHONY : CMakeFiles/interpreter.dir/build

CMakeFiles/interpreter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/interpreter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/interpreter.dir/clean

CMakeFiles/interpreter.dir/depend:
	cd /home/nick/AsmEmulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/AsmEmulator /home/nick/AsmEmulator /home/nick/AsmEmulator/build /home/nick/AsmEmulator/build /home/nick/AsmEmulator/build/CMakeFiles/interpreter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/interpreter.dir/depend

