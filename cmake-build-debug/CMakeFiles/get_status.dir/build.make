# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/abel/CLionProjects/ImagineCode_C++port

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abel/CLionProjects/ImagineCode_C++port/cmake-build-debug

# Utility rule file for get_status.

# Include the progress variables for this target.
include CMakeFiles/get_status.dir/progress.make

CMakeFiles/get_status:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/abel/CLionProjects/ImagineCode_C++port/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Get status from atmega328p"
	avrdude -p atmega328p -c avr-objcopy -P /dev/ttyACM0 -n -v

get_status: CMakeFiles/get_status
get_status: CMakeFiles/get_status.dir/build.make

.PHONY : get_status

# Rule to build all files generated by this target.
CMakeFiles/get_status.dir/build: get_status

.PHONY : CMakeFiles/get_status.dir/build

CMakeFiles/get_status.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/get_status.dir/cmake_clean.cmake
.PHONY : CMakeFiles/get_status.dir/clean

CMakeFiles/get_status.dir/depend:
	cd /home/abel/CLionProjects/ImagineCode_C++port/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abel/CLionProjects/ImagineCode_C++port /home/abel/CLionProjects/ImagineCode_C++port /home/abel/CLionProjects/ImagineCode_C++port/cmake-build-debug /home/abel/CLionProjects/ImagineCode_C++port/cmake-build-debug /home/abel/CLionProjects/ImagineCode_C++port/cmake-build-debug/CMakeFiles/get_status.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/get_status.dir/depend

