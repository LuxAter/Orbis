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
CMAKE_SOURCE_DIR = /home/arden/Programming/orbis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arden/Programming/orbis/build

# Include any dependencies generated for this target.
include src/CMakeFiles/orbis_shared.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/orbis_shared.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/orbis_shared.dir/flags.make

src/CMakeFiles/orbis_shared.dir/log.cpp.o: src/CMakeFiles/orbis_shared.dir/flags.make
src/CMakeFiles/orbis_shared.dir/log.cpp.o: ../src/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arden/Programming/orbis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/orbis_shared.dir/log.cpp.o"
	cd /home/arden/Programming/orbis/build/src && /sbin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/orbis_shared.dir/log.cpp.o -c /home/arden/Programming/orbis/src/log.cpp

src/CMakeFiles/orbis_shared.dir/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/orbis_shared.dir/log.cpp.i"
	cd /home/arden/Programming/orbis/build/src && /sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arden/Programming/orbis/src/log.cpp > CMakeFiles/orbis_shared.dir/log.cpp.i

src/CMakeFiles/orbis_shared.dir/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/orbis_shared.dir/log.cpp.s"
	cd /home/arden/Programming/orbis/build/src && /sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arden/Programming/orbis/src/log.cpp -o CMakeFiles/orbis_shared.dir/log.cpp.s

# Object files for target orbis_shared
orbis_shared_OBJECTS = \
"CMakeFiles/orbis_shared.dir/log.cpp.o"

# External object files for target orbis_shared
orbis_shared_EXTERNAL_OBJECTS =

liborbis_shared.so: src/CMakeFiles/orbis_shared.dir/log.cpp.o
liborbis_shared.so: src/CMakeFiles/orbis_shared.dir/build.make
liborbis_shared.so: external/spdlog/libspdlogd.so.1.5.0
liborbis_shared.so: external/fmt/libfmtd.a
liborbis_shared.so: src/CMakeFiles/orbis_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arden/Programming/orbis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../liborbis_shared.so"
	cd /home/arden/Programming/orbis/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/orbis_shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/orbis_shared.dir/build: liborbis_shared.so

.PHONY : src/CMakeFiles/orbis_shared.dir/build

src/CMakeFiles/orbis_shared.dir/clean:
	cd /home/arden/Programming/orbis/build/src && $(CMAKE_COMMAND) -P CMakeFiles/orbis_shared.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/orbis_shared.dir/clean

src/CMakeFiles/orbis_shared.dir/depend:
	cd /home/arden/Programming/orbis/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arden/Programming/orbis /home/arden/Programming/orbis/src /home/arden/Programming/orbis/build /home/arden/Programming/orbis/build/src /home/arden/Programming/orbis/build/src/CMakeFiles/orbis_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/orbis_shared.dir/depend
