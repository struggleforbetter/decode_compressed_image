cmake_minimum_required( VERSION 2.8 )
project( decode_compressed_image )

set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  image_transport
  cv_bridge
)

catkin_package(
  
)
find_package(OpenCV REQUIRED)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable( decode_compressed_image src/main.cpp )

target_link_libraries(decode_compressed_image
    ${catkin_LIBRARIES}
    ${OpenCV_LIBS}
)

