cmake_minimum_required(VERSION 3.4)
project(Knapsack)

find_package(Boost)

include_directories(${BOOST_INCLUDE_DIRS})

add_executable(Knapsack knapsack.cpp)

target_link_libraries(Knapsack ${BOOST_LIBRARIES})

