cmake_minimum_required(VERSION 3.16)
project(SparseMatrix)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES
        header/*.h
        src/*.cpp
        test/*.cpp
        )


add_executable(SparseMatrix ${SOURCES})