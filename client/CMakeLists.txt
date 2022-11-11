cmake_minimum_required(VERSION 3.0.2)
project(client)

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

add_executable(client1
  main1.cpp
  client.cpp
  parsing.cpp
)
target_link_libraries(client1 ${catkin_LIBRARIES})

add_executable(client2
  main2.cpp
  client.cpp
  parsing.cpp
)
target_link_libraries(client2 ${catkin_LIBRARIES})

add_executable(client3
  main3.cpp
  client.cpp
  parsing.cpp
)
target_link_libraries(client3 ${catkin_LIBRARIES})
