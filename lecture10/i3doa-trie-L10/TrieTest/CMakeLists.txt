cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with source files, GTest and pthread lib
add_executable(testInsertSearch TrieTestInsertSearch.cpp)
add_executable(testRemove TrieTestRemove.cpp)
add_executable(testFindAll TrieTestFindAllWithPrefix.cpp)
target_link_libraries(testInsertSearch ${GTEST_LIBRARIES} pthread)
target_link_libraries(testRemove ${GTEST_LIBRARIES} pthread)
target_link_libraries(testFindAll ${GTEST_LIBRARIES} pthread)
