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
include network/ipc/CMakeFiles/pipe_server_select.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include network/ipc/CMakeFiles/pipe_server_select.dir/compiler_depend.make

# Include the progress variables for this target.
include network/ipc/CMakeFiles/pipe_server_select.dir/progress.make

# Include the compile flags for this target's objects.
include network/ipc/CMakeFiles/pipe_server_select.dir/flags.make

network/ipc/CMakeFiles/pipe_server_select.dir/pipe_server_select.c.o: network/ipc/CMakeFiles/pipe_server_select.dir/flags.make
network/ipc/CMakeFiles/pipe_server_select.dir/pipe_server_select.c.o: ../network/ipc/pipe_server_select.c
network/ipc/CMakeFiles/pipe_server_select.dir/pipe_server_select.c.o: network/ipc/CMakeFiles/pipe_server_select.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bangme/bangme/bangme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object network/ipc/CMakeFiles/pipe_server_select.dir/pipe_server_select.c.o"
	cd /home/bangme/bangme/bangme/build/network/ipc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT network/ipc/CMakeFiles/pipe_server_select.dir/pipe_server_select.c.o -MF CMakeFiles/pipe_server_select.dir/pipe_server_select.c.o.d -o CMakeFiles/pipe_server_select.dir/pipe_server_select.c.o -c /home/bangme/bangme/bangme/network/ipc/pipe_server_select.c

network/ipc/CMakeFiles/pipe_server_select.dir/pipe_server_select.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pipe_server_select.dir/pipe_server_select.c.i"
	cd /home/bangme/bangme/bangme/build/network/ipc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bangme/bangme/bangme/network/ipc/pipe_server_select.c > CMakeFiles/pipe_server_select.dir/pipe_server_select.c.i

network/ipc/CMakeFiles/pipe_server_select.dir/pipe_server_select.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pipe_server_select.dir/pipe_server_select.c.s"
	cd /home/bangme/bangme/bangme/build/network/ipc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bangme/bangme/bangme/network/ipc/pipe_server_select.c -o CMakeFiles/pipe_server_select.dir/pipe_server_select.c.s

# Object files for target pipe_server_select
pipe_server_select_OBJECTS = \
"CMakeFiles/pipe_server_select.dir/pipe_server_select.c.o"

# External object files for target pipe_server_select
pipe_server_select_EXTERNAL_OBJECTS =

network/ipc/pipe_server_select: network/ipc/CMakeFiles/pipe_server_select.dir/pipe_server_select.c.o
network/ipc/pipe_server_select: network/ipc/CMakeFiles/pipe_server_select.dir/build.make
network/ipc/pipe_server_select: network/ipc/CMakeFiles/pipe_server_select.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bangme/bangme/bangme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pipe_server_select"
	cd /home/bangme/bangme/bangme/build/network/ipc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pipe_server_select.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
network/ipc/CMakeFiles/pipe_server_select.dir/build: network/ipc/pipe_server_select
.PHONY : network/ipc/CMakeFiles/pipe_server_select.dir/build

network/ipc/CMakeFiles/pipe_server_select.dir/clean:
	cd /home/bangme/bangme/bangme/build/network/ipc && $(CMAKE_COMMAND) -P CMakeFiles/pipe_server_select.dir/cmake_clean.cmake
.PHONY : network/ipc/CMakeFiles/pipe_server_select.dir/clean

network/ipc/CMakeFiles/pipe_server_select.dir/depend:
	cd /home/bangme/bangme/bangme/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bangme/bangme/bangme /home/bangme/bangme/bangme/network/ipc /home/bangme/bangme/bangme/build /home/bangme/bangme/bangme/build/network/ipc /home/bangme/bangme/bangme/build/network/ipc/CMakeFiles/pipe_server_select.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : network/ipc/CMakeFiles/pipe_server_select.dir/depend

