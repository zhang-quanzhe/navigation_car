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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ustb/catkin_velodyne/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ustb/catkin_velodyne/build

# Include any dependencies generated for this target.
include sbg_ros_rec/CMakeFiles/ellipse.dir/depend.make

# Include the progress variables for this target.
include sbg_ros_rec/CMakeFiles/ellipse.dir/progress.make

# Include the compile flags for this target's objects.
include sbg_ros_rec/CMakeFiles/ellipse.dir/flags.make

sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o: sbg_ros_rec/CMakeFiles/ellipse.dir/flags.make
sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o: /home/ustb/catkin_velodyne/src/sbg_ros_rec/src/ellipse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ustb/catkin_velodyne/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o"
	cd /home/ustb/catkin_velodyne/build/sbg_ros_rec && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ellipse.dir/src/ellipse.cpp.o -c /home/ustb/catkin_velodyne/src/sbg_ros_rec/src/ellipse.cpp

sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ellipse.dir/src/ellipse.cpp.i"
	cd /home/ustb/catkin_velodyne/build/sbg_ros_rec && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ustb/catkin_velodyne/src/sbg_ros_rec/src/ellipse.cpp > CMakeFiles/ellipse.dir/src/ellipse.cpp.i

sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ellipse.dir/src/ellipse.cpp.s"
	cd /home/ustb/catkin_velodyne/build/sbg_ros_rec && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ustb/catkin_velodyne/src/sbg_ros_rec/src/ellipse.cpp -o CMakeFiles/ellipse.dir/src/ellipse.cpp.s

sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o.requires:

.PHONY : sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o.requires

sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o.provides: sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o.requires
	$(MAKE) -f sbg_ros_rec/CMakeFiles/ellipse.dir/build.make sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o.provides.build
.PHONY : sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o.provides

sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o.provides.build: sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o


# Object files for target ellipse
ellipse_OBJECTS = \
"CMakeFiles/ellipse.dir/src/ellipse.cpp.o"

# External object files for target ellipse
ellipse_EXTERNAL_OBJECTS =

/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: sbg_ros_rec/CMakeFiles/ellipse.dir/build.make
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /opt/ros/melodic/lib/libroscpp.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /opt/ros/melodic/lib/librosconsole.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /opt/ros/melodic/lib/librostime.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /opt/ros/melodic/lib/libcpp_common.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: /home/ustb/catkin_velodyne/devel/lib/libsbgECom.a
/home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse: sbg_ros_rec/CMakeFiles/ellipse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ustb/catkin_velodyne/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse"
	cd /home/ustb/catkin_velodyne/build/sbg_ros_rec && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ellipse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sbg_ros_rec/CMakeFiles/ellipse.dir/build: /home/ustb/catkin_velodyne/devel/lib/sbg_driver_2/ellipse

.PHONY : sbg_ros_rec/CMakeFiles/ellipse.dir/build

sbg_ros_rec/CMakeFiles/ellipse.dir/requires: sbg_ros_rec/CMakeFiles/ellipse.dir/src/ellipse.cpp.o.requires

.PHONY : sbg_ros_rec/CMakeFiles/ellipse.dir/requires

sbg_ros_rec/CMakeFiles/ellipse.dir/clean:
	cd /home/ustb/catkin_velodyne/build/sbg_ros_rec && $(CMAKE_COMMAND) -P CMakeFiles/ellipse.dir/cmake_clean.cmake
.PHONY : sbg_ros_rec/CMakeFiles/ellipse.dir/clean

sbg_ros_rec/CMakeFiles/ellipse.dir/depend:
	cd /home/ustb/catkin_velodyne/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ustb/catkin_velodyne/src /home/ustb/catkin_velodyne/src/sbg_ros_rec /home/ustb/catkin_velodyne/build /home/ustb/catkin_velodyne/build/sbg_ros_rec /home/ustb/catkin_velodyne/build/sbg_ros_rec/CMakeFiles/ellipse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sbg_ros_rec/CMakeFiles/ellipse.dir/depend

