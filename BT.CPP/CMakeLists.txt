cmake_minimum_required(VERSION 3.22.1)

project("bt_cpp")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

include_directories(
  include
)

find_package(behaviortree_cpp)

add_library(robot SHARED src/robot.cpp)

add_executable(tree src/tree.cpp)

target_link_libraries(tree robot)
target_link_libraries(tree behaviortree_cpp)