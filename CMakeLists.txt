cmake_minimum_required(VERSION 3.15)
project(SparseMatrix)

set(CMAKE_CXX_STANDARD 17)

add_executable(SparseMatrix src/functions.cpp src/main.cpp src/sparseMatrix.cpp)
