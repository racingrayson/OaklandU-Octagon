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
include ublox/ublox_gps/CMakeFiles/ublox_gps.dir/depend.make

# Include the progress variables for this target.
include ublox/ublox_gps/CMakeFiles/ublox_gps.dir/progress.make

# Include the compile flags for this target's objects.
include ublox/ublox_gps/CMakeFiles/ublox_gps.dir/flags.make

ublox/ublox_gps/CMakeFiles/ublox_gps.dir/src/gps.cpp.o: ublox/ublox_gps/CMakeFiles/ublox_gps.dir/flags.make
ublox/ublox_gps/CMakeFiles/ublox_gps.dir/src/gps.cpp.o: /home/joe/octagon/src/ublox/ublox_gps/src/gps.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joe/octagon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ublox/ublox_gps/CMakeFiles/ublox_gps.dir/src/gps.cpp.o"
	cd /home/joe/octagon/build/ublox/ublox_gps && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ublox_gps.dir/src/gps.cpp.o -c /home/joe/octagon/src/ublox/ublox_gps/src/gps.cpp

ublox/ublox_gps/CMakeFiles/ublox_gps.dir/src/gps.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ublox_gps.dir/src/gps.cpp.i"
	cd /home/joe/octagon/build/ublox/ublox_gps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joe/octagon/src/ublox/ublox_gps/src/gps.cpp > CMakeFiles/ublox_gps.dir/src/gps.cpp.i

ublox/ublox_gps/CMakeFiles/ublox_gps.dir/src/gps.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ublox_gps.dir/src/gps.cpp.s"
	cd /home/joe/octagon/build/ublox/ublox_gps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joe/octagon/src/ublox/ublox_gps/src/gps.cpp -o CMakeFiles/ublox_gps.dir/src/gps.cpp.s

# Object files for target ublox_gps
ublox_gps_OBJECTS = \
"CMakeFiles/ublox_gps.dir/src/gps.cpp.o"

# External object files for target ublox_gps
ublox_gps_EXTERNAL_OBJECTS =

/home/joe/octagon/devel/lib/libublox_gps.so: ublox/ublox_gps/CMakeFiles/ublox_gps.dir/src/gps.cpp.o
/home/joe/octagon/devel/lib/libublox_gps.so: ublox/ublox_gps/CMakeFiles/ublox_gps.dir/build.make
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/libtf.so
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/libtf2_ros.so
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/libactionlib.so
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/libmessage_filters.so
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/libtf2.so
/home/joe/octagon/devel/lib/libublox_gps.so: /home/joe/octagon/devel/lib/libublox_msgs.so
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/libroscpp.so
/home/joe/octagon/devel/lib/libublox_gps.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/joe/octagon/devel/lib/libublox_gps.so: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/librosconsole.so
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/joe/octagon/devel/lib/libublox_gps.so: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/joe/octagon/devel/lib/libublox_gps.so: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/librostime.so
/home/joe/octagon/devel/lib/libublox_gps.so: /opt/ros/kinetic/lib/libcpp_common.so
/home/joe/octagon/devel/lib/libublox_gps.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/joe/octagon/devel/lib/libublox_gps.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/joe/octagon/devel/lib/libublox_gps.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/joe/octagon/devel/lib/libublox_gps.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/joe/octagon/devel/lib/libublox_gps.so: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/joe/octagon/devel/lib/libublox_gps.so: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/joe/octagon/devel/lib/libublox_gps.so: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/joe/octagon/devel/lib/libublox_gps.so: ublox/ublox_gps/CMakeFiles/ublox_gps.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joe/octagon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/joe/octagon/devel/lib/libublox_gps.so"
	cd /home/joe/octagon/build/ublox/ublox_gps && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ublox_gps.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ublox/ublox_gps/CMakeFiles/ublox_gps.dir/build: /home/joe/octagon/devel/lib/libublox_gps.so

.PHONY : ublox/ublox_gps/CMakeFiles/ublox_gps.dir/build

ublox/ublox_gps/CMakeFiles/ublox_gps.dir/clean:
	cd /home/joe/octagon/build/ublox/ublox_gps && $(CMAKE_COMMAND) -P CMakeFiles/ublox_gps.dir/cmake_clean.cmake
.PHONY : ublox/ublox_gps/CMakeFiles/ublox_gps.dir/clean

ublox/ublox_gps/CMakeFiles/ublox_gps.dir/depend:
	cd /home/joe/octagon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joe/octagon/src /home/joe/octagon/src/ublox/ublox_gps /home/joe/octagon/build /home/joe/octagon/build/ublox/ublox_gps /home/joe/octagon/build/ublox/ublox_gps/CMakeFiles/ublox_gps.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ublox/ublox_gps/CMakeFiles/ublox_gps.dir/depend

