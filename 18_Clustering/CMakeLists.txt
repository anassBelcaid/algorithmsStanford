cmake_minimum_required(VERSION 3.4)
project(Clustering)

find_package(Boost)

include_directories(${BOOST_INCLUDE_DIRS})

add_executable(Clustering clustering1.cpp)
target_link_libraries(Clustering ${BOOST_LIBRARIES})

add_executable(Clustering2 clustering2.cpp)
target_link_libraries(Clustering2 ${BOOST_LIBRARIES})
