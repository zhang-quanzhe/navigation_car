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

# Utility rule file for loam_velodyne_test_data.tar.gz.

# Include the progress variables for this target.
include loam_velodyne/CMakeFiles/loam_velodyne_test_data.tar.gz.dir/progress.make

loam_velodyne/CMakeFiles/loam_velodyne_test_data.tar.gz:
	cd /home/ustb/catkin_velodyne/build/loam_velodyne && /usr/bin/python2 /opt/ros/melodic/share/catkin/cmake/test/download_checkmd5.py https://dl.dropboxusercontent.com/s/y4hn486461tfmpm/velodyne_loam_test_data.tar.gz /home/ustb/catkin_velodyne/build/loam_velodyne/velodyne_loam_test_data.tar.gz 3d5194e6981975588b7a93caebf79ba4 --ignore-error

loam_velodyne_test_data.tar.gz: loam_velodyne/CMakeFiles/loam_velodyne_test_data.tar.gz
loam_velodyne_test_data.tar.gz: loam_velodyne/CMakeFiles/loam_velodyne_test_data.tar.gz.dir/build.make

.PHONY : loam_velodyne_test_data.tar.gz

# Rule to build all files generated by this target.
loam_velodyne/CMakeFiles/loam_velodyne_test_data.tar.gz.dir/build: loam_velodyne_test_data.tar.gz

.PHONY : loam_velodyne/CMakeFiles/loam_velodyne_test_data.tar.gz.dir/build

loam_velodyne/CMakeFiles/loam_velodyne_test_data.tar.gz.dir/clean:
	cd /home/ustb/catkin_velodyne/build/loam_velodyne && $(CMAKE_COMMAND) -P CMakeFiles/loam_velodyne_test_data.tar.gz.dir/cmake_clean.cmake
.PHONY : loam_velodyne/CMakeFiles/loam_velodyne_test_data.tar.gz.dir/clean

loam_velodyne/CMakeFiles/loam_velodyne_test_data.tar.gz.dir/depend:
	cd /home/ustb/catkin_velodyne/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ustb/catkin_velodyne/src /home/ustb/catkin_velodyne/src/loam_velodyne /home/ustb/catkin_velodyne/build /home/ustb/catkin_velodyne/build/loam_velodyne /home/ustb/catkin_velodyne/build/loam_velodyne/CMakeFiles/loam_velodyne_test_data.tar.gz.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : loam_velodyne/CMakeFiles/loam_velodyne_test_data.tar.gz.dir/depend
