cmake_minimum_required(VERSION 3.4)
project(TwoSum)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost)

include_directories(${BOOST_INCLUDE_DIRS})

add_executable(TwoSum two_sums.cpp)
add_executable(liveMedian live_median.cpp)

