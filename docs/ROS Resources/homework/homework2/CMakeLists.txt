cmake_minimum_required(VERSION 2.8.3)
project(homework2)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
)

add_service_files(
  FILES
  StringCat.srv
)

generate_messages()

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

# Topic subscriber and publisher
add_executable(homework2_pubsub
  src/pubsub_node.cpp
)
target_link_libraries(homework2_pubsub
  ${catkin_LIBRARIES}
)

# Service advertiser
add_executable(homework2_advertiser
  src/service_advertiser_node.cpp
)
add_dependencies(homework2_advertiser
  ${PROJECT_NAME}_gencpp
)
target_link_libraries(homework2_advertiser
  ${catkin_LIBRARIES}
)

# Service client
add_executable(homework2_client
  src/service_client_node.cpp
)
add_dependencies(homework2_client
  ${PROJECT_NAME}_gencpp
)
target_link_libraries(homework2_client
  ${catkin_LIBRARIES}
)

################ Automated tester node --- DO NOT CHANGE
add_executable(test_homework2
  test/test_homework2.cpp
)
add_dependencies(test_homework2
  ${PROJECT_NAME}_gencpp
)
target_link_libraries(test_homework2
  ${catkin_LIBRARIES}
  ${GTEST_LIBRARIES}
)
