# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/thiago/Downloads/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/thiago/Downloads/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thiago/projetos/paa

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thiago/projetos/paa/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/paa.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/paa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/paa.dir/flags.make

CMakeFiles/paa.dir/main.c.o: CMakeFiles/paa.dir/flags.make
CMakeFiles/paa.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thiago/projetos/paa/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/paa.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/paa.dir/main.c.o   -c /home/thiago/projetos/paa/main.c

CMakeFiles/paa.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/paa.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/thiago/projetos/paa/main.c > CMakeFiles/paa.dir/main.c.i

CMakeFiles/paa.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/paa.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/thiago/projetos/paa/main.c -o CMakeFiles/paa.dir/main.c.s

CMakeFiles/paa.dir/main.c.o.requires:

.PHONY : CMakeFiles/paa.dir/main.c.o.requires

CMakeFiles/paa.dir/main.c.o.provides: CMakeFiles/paa.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/paa.dir/build.make CMakeFiles/paa.dir/main.c.o.provides.build
.PHONY : CMakeFiles/paa.dir/main.c.o.provides

CMakeFiles/paa.dir/main.c.o.provides.build: CMakeFiles/paa.dir/main.c.o


# Object files for target paa
paa_OBJECTS = \
"CMakeFiles/paa.dir/main.c.o"

# External object files for target paa
paa_EXTERNAL_OBJECTS =

paa: CMakeFiles/paa.dir/main.c.o
paa: CMakeFiles/paa.dir/build.make
paa: CMakeFiles/paa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thiago/projetos/paa/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable paa"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/paa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/paa.dir/build: paa

.PHONY : CMakeFiles/paa.dir/build

CMakeFiles/paa.dir/requires: CMakeFiles/paa.dir/main.c.o.requires

.PHONY : CMakeFiles/paa.dir/requires

CMakeFiles/paa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/paa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/paa.dir/clean

CMakeFiles/paa.dir/depend:
	cd /home/thiago/projetos/paa/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thiago/projetos/paa /home/thiago/projetos/paa /home/thiago/projetos/paa/cmake-build-debug /home/thiago/projetos/paa/cmake-build-debug /home/thiago/projetos/paa/cmake-build-debug/CMakeFiles/paa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/paa.dir/depend

