#!/bin/bash
#gnome-terminal --tab -e 'bash -c "roscore;exec bash"' 
#sleep 5 
#开启激光雷达
gnome-terminal --tab -e 'bash -c "roslaunch velodyne_pointcloud VLP16_points.launch;exec bash"' 
sleep 5
#TF变换static_transform_publisher x y z yaw pitch roll frame_id child_frame_id period_in_ms;
gnome-terminal --tab -e 'bash -c "rosrun tf static_transform_publisher 0 0 0 0 0 0 base_link laser_link 0;exec bash"' 
sleep 5
gnome-terminal --tab -e 'bash -c "rosrun tf static_transform_publisher 0 0 0 0 0 0 laser_link velodyne 0;exec bash"' 
sleep 5
gnome-terminal --tab -e 'bash -c "rosrun tf static_transform_publisher 0 0 0 0 0 0 base_link base_footprint 0;exec bash"' 
sleep 5
#建图
# gnome-terminal --tab -e 'bash -c "rosrun gmapping slam_gmapping;exec bash"'
# sleep 5
#
gnome-terminal --tab -e 'bash -c "rosrun laser_scan_matcher laser_scan_matcher_node _fixed_frame:=odom;exec bash"'
sleep 5
#gnome-terminal --tab -e 'bash -c "rosrun rviz rviz;exec bash"'
