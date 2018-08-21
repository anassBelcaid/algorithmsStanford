cmake_minimum_required(VERSION 2.8.2)
project(inversions)

#find Google test
find_package(GTest)

add_executable( inversions inversions.cpp)
add_executable( test tests.cpp)
target_link_libraries(test  ${GTEST_LIBRARIES})




