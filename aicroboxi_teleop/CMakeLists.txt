cmake_minimum_required(VERSION 2.8.3)
project(aicroboxi_teleop)

find_package(catkin REQUIRED geometry_msgs roscpp rospy)

catkin_package(
CATKIN_DEPENDS joy geometry_msgs roscpp rospy
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(teleop_joy nodes/teleop_joy.cpp)
target_link_libraries(teleop_joy ${catkin_LIBRARIES})
