# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bangme/bangme/bangme

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bangme/bangme/bangme/build

# Include any dependencies generated for this target.
include a3/CMakeFiles/endian.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include a3/CMakeFiles/endian.dir/compiler_depend.make

# Include the progress variables for this target.
include a3/CMakeFiles/endian.dir/progress.make

# Include the compile flags for this target's objects.
include a3/CMakeFiles/endian.dir/flags.make

a3/CMakeFiles/endian.dir/endian.c.o: a3/CMakeFiles/endian.dir/flags.make
a3/CMakeFiles/endian.dir/endian.c.o: ../a3/endian.c
a3/CMakeFiles/endian.dir/endian.c.o: a3/CMakeFiles/endian.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bangme/bangme/bangme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object a3/CMakeFiles/endian.dir/endian.c.o"
	cd /home/bangme/bangme/bangme/build/a3 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT a3/CMakeFiles/endian.dir/endian.c.o -MF CMakeFiles/endian.dir/endian.c.o.d -o CMakeFiles/endian.dir/endian.c.o -c /home/bangme/bangme/bangme/a3/endian.c

a3/CMakeFiles/endian.dir/endian.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/endian.dir/endian.c.i"
	cd /home/bangme/bangme/bangme/build/a3 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bangme/bangme/bangme/a3/endian.c > CMakeFiles/endian.dir/endian.c.i

a3/CMakeFiles/endian.dir/endian.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/endian.dir/endian.c.s"
	cd /home/bangme/bangme/bangme/build/a3 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bangme/bangme/bangme/a3/endian.c -o CMakeFiles/endian.dir/endian.c.s

# Object files for target endian
endian_OBJECTS = \
"CMakeFiles/endian.dir/endian.c.o"

# External object files for target endian
endian_EXTERNAL_OBJECTS =

a3/endian: a3/CMakeFiles/endian.dir/endian.c.o
a3/endian: a3/CMakeFiles/endian.dir/build.make
a3/endian: a3/CMakeFiles/endian.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bangme/bangme/bangme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable endian"
	cd /home/bangme/bangme/bangme/build/a3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/endian.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
a3/CMakeFiles/endian.dir/build: a3/endian
.PHONY : a3/CMakeFiles/endian.dir/build

a3/CMakeFiles/endian.dir/clean:
	cd /home/bangme/bangme/bangme/build/a3 && $(CMAKE_COMMAND) -P CMakeFiles/endian.dir/cmake_clean.cmake
.PHONY : a3/CMakeFiles/endian.dir/clean

a3/CMakeFiles/endian.dir/depend:
	cd /home/bangme/bangme/bangme/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bangme/bangme/bangme /home/bangme/bangme/bangme/a3 /home/bangme/bangme/bangme/build /home/bangme/bangme/bangme/build/a3 /home/bangme/bangme/bangme/build/a3/CMakeFiles/endian.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : a3/CMakeFiles/endian.dir/depend

