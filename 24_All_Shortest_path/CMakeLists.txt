cmake_minimum_required(VERSION 3.4)
project(allShortestPaths)

find_package(Boost)

include_directories(${BOOST_INCLUDE_DIRS})
include_directories(src)

file( GLOB src src/*.cpp) 

add_executable(allShortestPaths ${src} shortest_paths.cpp)

target_link_libraries(allShortestPaths ${BOOST_LIBRARIES})

