cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with source files, GTest and pthread lib
add_executable(testListQueue testListQueue.cpp)
target_link_libraries(testListQueue ${GTEST_LIBRARIES} pthread)
