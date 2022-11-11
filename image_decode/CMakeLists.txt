cmake_minimum_required(VERSION 3.0.2)
project(image_decode)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  rospy
  sensor_msgs
  std_msgs
)

catkin_package(
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

FIND_PACKAGE(OpenCV REQUIRED)
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(image_decode1 main1.cpp)
target_link_libraries(image_decode1 ${catkin_LIBRARIES}) 
target_link_libraries(image_decode1 ${OpenCV_LIBRARIES})

ADD_EXECUTABLE(image_decode2 main2.cpp)
target_link_libraries(image_decode2 ${catkin_LIBRARIES}) 
target_link_libraries(image_decode2 ${OpenCV_LIBRARIES})

ADD_EXECUTABLE(image_decode3 main3.cpp)
target_link_libraries(image_decode3 ${catkin_LIBRARIES}) 
target_link_libraries(image_decode3 ${OpenCV_LIBRARIES})

ADD_EXECUTABLE(image_decode4 main4.cpp)
target_link_libraries(image_decode4 ${catkin_LIBRARIES}) 
target_link_libraries(image_decode4 ${OpenCV_LIBRARIES})

ADD_EXECUTABLE(image_decode5 main5.cpp)
target_link_libraries(image_decode5 ${catkin_LIBRARIES}) 
target_link_libraries(image_decode5 ${OpenCV_LIBRARIES})

ADD_EXECUTABLE(image_decode6 main6.cpp)
target_link_libraries(image_decode6 ${catkin_LIBRARIES}) 
target_link_libraries(image_decode6 ${OpenCV_LIBRARIES})
