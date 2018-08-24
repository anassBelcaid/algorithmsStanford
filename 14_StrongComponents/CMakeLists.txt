cmake_minimum_required(VERSION 3.4)
project(StrongComponents)

set(CMAKE_CXX_STANDARD 17)
find_package(GTest REQUIRED)
find_package(Boost REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(src  graph.cpp strongcomponents.cpp)

add_executable(StrongComponents ${src} driver.cpp )

target_link_libraries(StrongComponents ${Boost_LIBRARY_DIRS} ${GTEST_LIBRARIES})

