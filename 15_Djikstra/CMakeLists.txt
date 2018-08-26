cmake_minimum_required(VERSION 3.4)
project(Djikstra)
find_package(GTest)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(src)
file( GLOB src src/*.cpp)
add_executable(Djikstra  shortest_path.cpp ${src})

add_executable(tests test.cpp)
target_link_libraries(tests ${src} ${GTEST_LIBRARIES})

