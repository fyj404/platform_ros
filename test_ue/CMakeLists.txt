cmake_minimum_required(VERSION 3.0.2)
project(test_ue)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
)

catkin_package(
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}
  main.cpp
)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)

add_executable(ue_read_node ue_read_node.cpp)
target_link_libraries(ue_read_node ${catkin_LIBRARIES})

add_executable(ue_read_cam ue_read_cam.cpp)
target_link_libraries(ue_read_cam ${catkin_LIBRARIES})

add_executable(ue_check_node ue_check_node.cpp)
target_link_libraries(ue_check_node ${catkin_LIBRARIES})
