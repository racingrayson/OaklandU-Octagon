cmake_minimum_required(VERSION 2.8.3)
project(gps_sim_project)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  ugv_course_libs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)





#################
## Test Script ##
#################
add_executable(test_gps_sim_project test/test_gps_project.cpp)
target_link_libraries(test_gps_sim_project ${catkin_LIBRARIES} ${GTEST_LIBRARIES})
