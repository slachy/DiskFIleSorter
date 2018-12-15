cmake_minimum_required(VERSION 2.6)
project(DiskFileSorter)

set (CMAKE_CXX_STANDARD 14)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} Source Include)

ADD_LIBRARY(DiskFileSorter Source/DiskFileSorter.cpp)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests Test/DiskFileSorterTestSuite.cpp)
target_link_libraries (runTests ${GTEST_LIBRARIES} gtest_main pthread Logger)
