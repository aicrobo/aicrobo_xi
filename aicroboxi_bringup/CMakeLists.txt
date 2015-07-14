cmake_minimum_required(VERSION 2.8.3)
project(aicroboxi_bringup)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package()