cmake_minimum_required(VERSION 3.4)
project(minCut)

#find Google test
find_package(GTest)

set(CMAKE_CXX_STANDARD 14)
#defining the src file
set(SRCS kargerCut.cpp)

add_executable( kargerCut ${SRCS}  kargerCut_driver.cpp)
add_executable( test  ${SRCS} tests.cpp)
target_link_libraries(test  ${GTEST_LIBRARIES})




