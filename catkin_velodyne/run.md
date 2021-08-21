cd /home/ustb/catkin_velodyne
source /home/ustb/catkin_velodyne/devel/setup.bash
roslaunch velodyne_pointcloud VLP16_points.launch
rosrun rviz rviz -f velodyne

cd /home/ustb/Documents/catkin_A_loam
source /home/ustb/Documents/catkin_A_loam/devel/setup.bash
 roslaunch aloam_velodyne aloam_velodyne_VLP_16.launch
