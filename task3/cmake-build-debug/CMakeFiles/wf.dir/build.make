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
include CMakeFiles/wf.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/wf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wf.dir/flags.make

CMakeFiles/wf.dir/workflow/Factory.cpp.obj: CMakeFiles/wf.dir/flags.make
CMakeFiles/wf.dir/workflow/Factory.cpp.obj: ../workflow/Factory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\iivan\CPP_TASKS\task3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wf.dir/workflow/Factory.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\wf.dir\workflow\Factory.cpp.obj -c C:\Users\iivan\CPP_TASKS\task3\workflow\Factory.cpp

CMakeFiles/wf.dir/workflow/Factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wf.dir/workflow/Factory.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\iivan\CPP_TASKS\task3\workflow\Factory.cpp > CMakeFiles\wf.dir\workflow\Factory.cpp.i

CMakeFiles/wf.dir/workflow/Factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wf.dir/workflow/Factory.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\iivan\CPP_TASKS\task3\workflow\Factory.cpp -o CMakeFiles\wf.dir\workflow\Factory.cpp.s

# Object files for target wf
wf_OBJECTS = \
"CMakeFiles/wf.dir/workflow/Factory.cpp.obj"

# External object files for target wf
wf_EXTERNAL_OBJECTS =

libwf.a: CMakeFiles/wf.dir/workflow/Factory.cpp.obj
libwf.a: CMakeFiles/wf.dir/build.make
libwf.a: CMakeFiles/wf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\iivan\CPP_TASKS\task3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libwf.a"
	$(CMAKE_COMMAND) -P CMakeFiles\wf.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\wf.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wf.dir/build: libwf.a
.PHONY : CMakeFiles/wf.dir/build

CMakeFiles/wf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\wf.dir\cmake_clean.cmake
.PHONY : CMakeFiles/wf.dir/clean

CMakeFiles/wf.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\iivan\CPP_TASKS\task3 C:\Users\iivan\CPP_TASKS\task3 C:\Users\iivan\CPP_TASKS\task3\cmake-build-debug C:\Users\iivan\CPP_TASKS\task3\cmake-build-debug C:\Users\iivan\CPP_TASKS\task3\cmake-build-debug\CMakeFiles\wf.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wf.dir/depend

