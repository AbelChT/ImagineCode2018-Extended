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

# Utility rule file for disassemble_main.cpp,.

# Include the progress variables for this target.
include CMakeFiles/disassemble_main.cpp,.dir/progress.make

CMakeFiles/disassemble_main.cpp,: main.cpp,-atmega328p.elf
	/usr/bin/avr-objdump -h -S main.cpp,-atmega328p.elf > main.cpp,.lst

disassemble_main.cpp,: CMakeFiles/disassemble_main.cpp,
disassemble_main.cpp,: CMakeFiles/disassemble_main.cpp,.dir/build.make

.PHONY : disassemble_main.cpp,

# Rule to build all files generated by this target.
CMakeFiles/disassemble_main.cpp,.dir/build: disassemble_main.cpp,

.PHONY : CMakeFiles/disassemble_main.cpp,.dir/build

CMakeFiles/disassemble_main.cpp,.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/disassemble_main.cpp,.dir/cmake_clean.cmake
.PHONY : CMakeFiles/disassemble_main.cpp,.dir/clean

CMakeFiles/disassemble_main.cpp,.dir/depend:
	cd /home/abel/CLionProjects/ImagineCode_C++port/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abel/CLionProjects/ImagineCode_C++port /home/abel/CLionProjects/ImagineCode_C++port /home/abel/CLionProjects/ImagineCode_C++port/cmake-build-debug /home/abel/CLionProjects/ImagineCode_C++port/cmake-build-debug /home/abel/CLionProjects/ImagineCode_C++port/cmake-build-debug/CMakeFiles/disassemble_main.cpp,.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/disassemble_main.cpp,.dir/depend
