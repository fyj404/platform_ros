cmake_minimum_required(VERSION 3.0.2)
project(server)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
)

find_package(cmake_modules REQUIRED)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
add_definitions(${EIGEN_DEFINITIONS})

catkin_package(

)

aux_source_directory(. CPP_LIST)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}
  main.cpp
  client.cpp
  packing.cpp
  server.cpp
  ${CPP_LIST}
)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)
