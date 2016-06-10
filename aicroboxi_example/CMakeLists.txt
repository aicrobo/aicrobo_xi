cmake_minimum_required(VERSION 2.8.3)
project(aicroboxi_example)

find_package(catkin REQUIRED COMPONENTS roscpp rospy geometry_msgs)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES aicroboxi_example
  CATKIN_DEPENDS roscpp rospy geometry_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(move nodes/move.cpp)
target_link_libraries(move ${catkin_LIBRARIES})