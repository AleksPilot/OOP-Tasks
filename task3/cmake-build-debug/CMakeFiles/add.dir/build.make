# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\iivan\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\iivan\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\iivan\CPP_TASKS\task3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\iivan\CPP_TASKS\task3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/add.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/add.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/add.dir/flags.make

CMakeFiles/add.dir/addons/block_append.cpp.obj: CMakeFiles/add.dir/flags.make
CMakeFiles/add.dir/addons/block_append.cpp.obj: ../addons/block_append.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\iivan\CPP_TASKS\task3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/add.dir/addons/block_append.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\add.dir\addons\block_append.cpp.obj -c C:\Users\iivan\CPP_TASKS\task3\addons\block_append.cpp

CMakeFiles/add.dir/addons/block_append.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/add.dir/addons/block_append.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\iivan\CPP_TASKS\task3\addons\block_append.cpp > CMakeFiles\add.dir\addons\block_append.cpp.i

CMakeFiles/add.dir/addons/block_append.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/add.dir/addons/block_append.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\iivan\CPP_TASKS\task3\addons\block_append.cpp -o CMakeFiles\add.dir\addons\block_append.cpp.s

# Object files for target add
add_OBJECTS = \
"CMakeFiles/add.dir/addons/block_append.cpp.obj"

# External object files for target add
add_EXTERNAL_OBJECTS =

libadd.a: CMakeFiles/add.dir/addons/block_append.cpp.obj
libadd.a: CMakeFiles/add.dir/build.make
libadd.a: CMakeFiles/add.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\iivan\CPP_TASKS\task3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libadd.a"
	$(CMAKE_COMMAND) -P CMakeFiles\add.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\add.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/add.dir/build: libadd.a
.PHONY : CMakeFiles/add.dir/build

CMakeFiles/add.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\add.dir\cmake_clean.cmake
.PHONY : CMakeFiles/add.dir/clean

CMakeFiles/add.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\iivan\CPP_TASKS\task3 C:\Users\iivan\CPP_TASKS\task3 C:\Users\iivan\CPP_TASKS\task3\cmake-build-debug C:\Users\iivan\CPP_TASKS\task3\cmake-build-debug C:\Users\iivan\CPP_TASKS\task3\cmake-build-debug\CMakeFiles\add.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/add.dir/depend
