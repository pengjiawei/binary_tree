# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\software\CLion 2017.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\software\CLion 2017.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\WORK\CLionWorkSpace\tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\WORK\CLionWorkSpace\tree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tree.dir/flags.make

CMakeFiles/tree.dir/main.cpp.obj: CMakeFiles/tree.dir/flags.make
CMakeFiles/tree.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\WORK\CLionWorkSpace\tree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tree.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tree.dir\main.cpp.obj -c D:\WORK\CLionWorkSpace\tree\main.cpp

CMakeFiles/tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tree.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\WORK\CLionWorkSpace\tree\main.cpp > CMakeFiles\tree.dir\main.cpp.i

CMakeFiles/tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tree.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\WORK\CLionWorkSpace\tree\main.cpp -o CMakeFiles\tree.dir\main.cpp.s

CMakeFiles/tree.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/tree.dir/main.cpp.obj.requires

CMakeFiles/tree.dir/main.cpp.obj.provides: CMakeFiles/tree.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\tree.dir\build.make CMakeFiles/tree.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/tree.dir/main.cpp.obj.provides

CMakeFiles/tree.dir/main.cpp.obj.provides.build: CMakeFiles/tree.dir/main.cpp.obj


# Object files for target tree
tree_OBJECTS = \
"CMakeFiles/tree.dir/main.cpp.obj"

# External object files for target tree
tree_EXTERNAL_OBJECTS =

tree.exe: CMakeFiles/tree.dir/main.cpp.obj
tree.exe: CMakeFiles/tree.dir/build.make
tree.exe: CMakeFiles/tree.dir/linklibs.rsp
tree.exe: CMakeFiles/tree.dir/objects1.rsp
tree.exe: CMakeFiles/tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\WORK\CLionWorkSpace\tree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tree.dir/build: tree.exe

.PHONY : CMakeFiles/tree.dir/build

CMakeFiles/tree.dir/requires: CMakeFiles/tree.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/tree.dir/requires

CMakeFiles/tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tree.dir/clean

CMakeFiles/tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\WORK\CLionWorkSpace\tree D:\WORK\CLionWorkSpace\tree D:\WORK\CLionWorkSpace\tree\cmake-build-debug D:\WORK\CLionWorkSpace\tree\cmake-build-debug D:\WORK\CLionWorkSpace\tree\cmake-build-debug\CMakeFiles\tree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tree.dir/depend

