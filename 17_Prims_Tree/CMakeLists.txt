cmake_minimum_required(VERSION 3.6)
project(Prim)

find_package(GTest)
include_directories(src)
include_directories(${GTEST_INCLUDE_DIRS})
file(GLOB src src/*.cpp)

add_executable(scheduling scheduling.cpp)
add_executable( primTree ${src} primTree.cpp)

