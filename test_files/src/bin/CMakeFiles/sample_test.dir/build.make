# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/pumaxh/C_program/C_progame_practice/test_files

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pumaxh/C_program/C_progame_practice/test_files/src

# Include any dependencies generated for this target.
include bin/CMakeFiles/sample_test.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/sample_test.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/sample_test.dir/flags.make

bin/CMakeFiles/sample_test.dir/test_main.cpp.o: bin/CMakeFiles/sample_test.dir/flags.make
bin/CMakeFiles/sample_test.dir/test_main.cpp.o: test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pumaxh/C_program/C_progame_practice/test_files/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/sample_test.dir/test_main.cpp.o"
	cd /home/pumaxh/C_program/C_progame_practice/test_files/src/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample_test.dir/test_main.cpp.o -c /home/pumaxh/C_program/C_progame_practice/test_files/src/test_main.cpp

bin/CMakeFiles/sample_test.dir/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample_test.dir/test_main.cpp.i"
	cd /home/pumaxh/C_program/C_progame_practice/test_files/src/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pumaxh/C_program/C_progame_practice/test_files/src/test_main.cpp > CMakeFiles/sample_test.dir/test_main.cpp.i

bin/CMakeFiles/sample_test.dir/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample_test.dir/test_main.cpp.s"
	cd /home/pumaxh/C_program/C_progame_practice/test_files/src/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pumaxh/C_program/C_progame_practice/test_files/src/test_main.cpp -o CMakeFiles/sample_test.dir/test_main.cpp.s

bin/CMakeFiles/sample_test.dir/test_main.cpp.o.requires:

.PHONY : bin/CMakeFiles/sample_test.dir/test_main.cpp.o.requires

bin/CMakeFiles/sample_test.dir/test_main.cpp.o.provides: bin/CMakeFiles/sample_test.dir/test_main.cpp.o.requires
	$(MAKE) -f bin/CMakeFiles/sample_test.dir/build.make bin/CMakeFiles/sample_test.dir/test_main.cpp.o.provides.build
.PHONY : bin/CMakeFiles/sample_test.dir/test_main.cpp.o.provides

bin/CMakeFiles/sample_test.dir/test_main.cpp.o.provides.build: bin/CMakeFiles/sample_test.dir/test_main.cpp.o


bin/CMakeFiles/sample_test.dir/sample1.cc.o: bin/CMakeFiles/sample_test.dir/flags.make
bin/CMakeFiles/sample_test.dir/sample1.cc.o: sample1.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pumaxh/C_program/C_progame_practice/test_files/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object bin/CMakeFiles/sample_test.dir/sample1.cc.o"
	cd /home/pumaxh/C_program/C_progame_practice/test_files/src/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample_test.dir/sample1.cc.o -c /home/pumaxh/C_program/C_progame_practice/test_files/src/sample1.cc

bin/CMakeFiles/sample_test.dir/sample1.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample_test.dir/sample1.cc.i"
	cd /home/pumaxh/C_program/C_progame_practice/test_files/src/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pumaxh/C_program/C_progame_practice/test_files/src/sample1.cc > CMakeFiles/sample_test.dir/sample1.cc.i

bin/CMakeFiles/sample_test.dir/sample1.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample_test.dir/sample1.cc.s"
	cd /home/pumaxh/C_program/C_progame_practice/test_files/src/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pumaxh/C_program/C_progame_practice/test_files/src/sample1.cc -o CMakeFiles/sample_test.dir/sample1.cc.s

bin/CMakeFiles/sample_test.dir/sample1.cc.o.requires:

.PHONY : bin/CMakeFiles/sample_test.dir/sample1.cc.o.requires

bin/CMakeFiles/sample_test.dir/sample1.cc.o.provides: bin/CMakeFiles/sample_test.dir/sample1.cc.o.requires
	$(MAKE) -f bin/CMakeFiles/sample_test.dir/build.make bin/CMakeFiles/sample_test.dir/sample1.cc.o.provides.build
.PHONY : bin/CMakeFiles/sample_test.dir/sample1.cc.o.provides

bin/CMakeFiles/sample_test.dir/sample1.cc.o.provides.build: bin/CMakeFiles/sample_test.dir/sample1.cc.o


bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o: bin/CMakeFiles/sample_test.dir/flags.make
bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o: sample1_unittest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pumaxh/C_program/C_progame_practice/test_files/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o"
	cd /home/pumaxh/C_program/C_progame_practice/test_files/src/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample_test.dir/sample1_unittest.cc.o -c /home/pumaxh/C_program/C_progame_practice/test_files/src/sample1_unittest.cc

bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample_test.dir/sample1_unittest.cc.i"
	cd /home/pumaxh/C_program/C_progame_practice/test_files/src/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pumaxh/C_program/C_progame_practice/test_files/src/sample1_unittest.cc > CMakeFiles/sample_test.dir/sample1_unittest.cc.i

bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample_test.dir/sample1_unittest.cc.s"
	cd /home/pumaxh/C_program/C_progame_practice/test_files/src/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pumaxh/C_program/C_progame_practice/test_files/src/sample1_unittest.cc -o CMakeFiles/sample_test.dir/sample1_unittest.cc.s

bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o.requires:

.PHONY : bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o.requires

bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o.provides: bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o.requires
	$(MAKE) -f bin/CMakeFiles/sample_test.dir/build.make bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o.provides.build
.PHONY : bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o.provides

bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o.provides.build: bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o


# Object files for target sample_test
sample_test_OBJECTS = \
"CMakeFiles/sample_test.dir/test_main.cpp.o" \
"CMakeFiles/sample_test.dir/sample1.cc.o" \
"CMakeFiles/sample_test.dir/sample1_unittest.cc.o"

# External object files for target sample_test
sample_test_EXTERNAL_OBJECTS =

bin/sample_test: bin/CMakeFiles/sample_test.dir/test_main.cpp.o
bin/sample_test: bin/CMakeFiles/sample_test.dir/sample1.cc.o
bin/sample_test: bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o
bin/sample_test: bin/CMakeFiles/sample_test.dir/build.make
bin/sample_test: bin/CMakeFiles/sample_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pumaxh/C_program/C_progame_practice/test_files/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable sample_test"
	cd /home/pumaxh/C_program/C_progame_practice/test_files/src/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sample_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/sample_test.dir/build: bin/sample_test

.PHONY : bin/CMakeFiles/sample_test.dir/build

bin/CMakeFiles/sample_test.dir/requires: bin/CMakeFiles/sample_test.dir/test_main.cpp.o.requires
bin/CMakeFiles/sample_test.dir/requires: bin/CMakeFiles/sample_test.dir/sample1.cc.o.requires
bin/CMakeFiles/sample_test.dir/requires: bin/CMakeFiles/sample_test.dir/sample1_unittest.cc.o.requires

.PHONY : bin/CMakeFiles/sample_test.dir/requires

bin/CMakeFiles/sample_test.dir/clean:
	cd /home/pumaxh/C_program/C_progame_practice/test_files/src/bin && $(CMAKE_COMMAND) -P CMakeFiles/sample_test.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/sample_test.dir/clean

bin/CMakeFiles/sample_test.dir/depend:
	cd /home/pumaxh/C_program/C_progame_practice/test_files/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pumaxh/C_program/C_progame_practice/test_files /home/pumaxh/C_program/C_progame_practice/test_files/src /home/pumaxh/C_program/C_progame_practice/test_files/src /home/pumaxh/C_program/C_progame_practice/test_files/src/bin /home/pumaxh/C_program/C_progame_practice/test_files/src/bin/CMakeFiles/sample_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/sample_test.dir/depend

