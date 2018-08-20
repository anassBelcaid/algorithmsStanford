cmake_minimum_required(VERSION 3.6)
project(QuickSort)
set( CMAKE_CXX_STANDARD 14)

find_package(GTest)

include_directories(${GTest_INCLUDE_DIRS})

add_executable(QuickSort QuickSort.cpp)

add_executable( test  test.cpp)
target_link_libraries(test ${GTEST_LIBRARIES})

