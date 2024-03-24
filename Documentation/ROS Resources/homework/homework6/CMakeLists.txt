cmake_minimum_required(VERSION 2.8.3)
project(homework6)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(test_homework6 test/test_homework6.cpp)
target_link_libraries(test_homework6
  ${catkin_LIBRARIES}
  ${GTEST_LIBRARIES}
)
