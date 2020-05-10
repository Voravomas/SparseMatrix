cmake_minimum_required(VERSION 3.15)
project(SparseMatrix)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB SOURCES
        header/*.h
        src/*.cpp
        test/*.cpp
        )

add_executable(SparseMatrix ${SOURCES})
target_link_libraries(SparseMatrix ${GTEST_LIBRARIES} pthread)