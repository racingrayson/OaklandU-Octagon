# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/joe/cmake-install/bin/cmake

# The command to remove a file.
RM = /home/joe/cmake-install/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joe/octagon/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joe/octagon/build

# Include any dependencies generated for this target.
include run_prog/CMakeFiles/gps_only.dir/depend.make

# Include the progress variables for this target.
include run_prog/CMakeFiles/gps_only.dir/progress.make

# Include the compile flags for this target's objects.
include run_prog/CMakeFiles/gps_only.dir/flags.make

run_prog/CMakeFiles/gps_only.dir/src/gps_only.cpp.o: run_prog/CMakeFiles/gps_only.dir/flags.make
run_prog/CMakeFiles/gps_only.dir/src/gps_only.cpp.o: /home/joe/octagon/src/run_prog/src/gps_only.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joe/octagon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object run_prog/CMakeFiles/gps_only.dir/src/gps_only.cpp.o"
	cd /home/joe/octagon/build/run_prog && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gps_only.dir/src/gps_only.cpp.o -c /home/joe/octagon/src/run_prog/src/gps_only.cpp

run_prog/CMakeFiles/gps_only.dir/src/gps_only.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gps_only.dir/src/gps_only.cpp.i"
	cd /home/joe/octagon/build/run_prog && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joe/octagon/src/run_prog/src/gps_only.cpp > CMakeFiles/gps_only.dir/src/gps_only.cpp.i

run_prog/CMakeFiles/gps_only.dir/src/gps_only.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gps_only.dir/src/gps_only.cpp.s"
	cd /home/joe/octagon/build/run_prog && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joe/octagon/src/run_prog/src/gps_only.cpp -o CMakeFiles/gps_only.dir/src/gps_only.cpp.s

# Object files for target gps_only
gps_only_OBJECTS = \
"CMakeFiles/gps_only.dir/src/gps_only.cpp.o"

# External object files for target gps_only
gps_only_EXTERNAL_OBJECTS =

/home/joe/octagon/devel/lib/run_prog/gps_only: run_prog/CMakeFiles/gps_only.dir/src/gps_only.cpp.o
/home/joe/octagon/devel/lib/run_prog/gps_only: run_prog/CMakeFiles/gps_only.dir/build.make
/home/joe/octagon/devel/lib/run_prog/gps_only: /opt/ros/kinetic/lib/libmessage_filters.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /opt/ros/kinetic/lib/libroscpp.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /opt/ros/kinetic/lib/librosconsole.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /opt/ros/kinetic/lib/librostime.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /opt/ros/kinetic/lib/libcpp_common.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/joe/octagon/devel/lib/run_prog/gps_only: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/joe/octagon/devel/lib/run_prog/gps_only: run_prog/CMakeFiles/gps_only.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joe/octagon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/joe/octagon/devel/lib/run_prog/gps_only"
	cd /home/joe/octagon/build/run_prog && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gps_only.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
run_prog/CMakeFiles/gps_only.dir/build: /home/joe/octagon/devel/lib/run_prog/gps_only

.PHONY : run_prog/CMakeFiles/gps_only.dir/build

run_prog/CMakeFiles/gps_only.dir/clean:
	cd /home/joe/octagon/build/run_prog && $(CMAKE_COMMAND) -P CMakeFiles/gps_only.dir/cmake_clean.cmake
.PHONY : run_prog/CMakeFiles/gps_only.dir/clean

run_prog/CMakeFiles/gps_only.dir/depend:
	cd /home/joe/octagon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joe/octagon/src /home/joe/octagon/src/run_prog /home/joe/octagon/build /home/joe/octagon/build/run_prog /home/joe/octagon/build/run_prog/CMakeFiles/gps_only.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : run_prog/CMakeFiles/gps_only.dir/depend

