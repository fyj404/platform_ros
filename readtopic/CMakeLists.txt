cmake_minimum_required(VERSION 3.0.2)
project(readtopic)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  geometry_msgs
  nav_msgs
  rosbag
  roscpp
  sensor_msgs
  std_msgs
  tf
  visualization_msgs
)
include_directories(include ${catkin_INCLUDE_DIRS} )


find_package(cmake_modules REQUIRED)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
add_definitions(${EIGEN_DEFINITIONS})


add_executable(ueReadNode ueReadNode.cpp)
target_link_libraries(ueReadNode ${catkin_LIBRARIES})

add_executable(ueReadCam ueReadCam.cpp)
target_link_libraries(ueReadCam ${catkin_LIBRARIES})

add_executable(ueCheckNode ueCheckNode.cpp)
target_link_libraries(ueCheckNode ${catkin_LIBRARIES})

#add_executable(airsimTrue src/airsimTrue.cpp)
#target_link_libraries(airsimTrue ${catkin_LIBRARIES})
