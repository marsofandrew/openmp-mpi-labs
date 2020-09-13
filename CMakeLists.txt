cmake_minimum_required(VERSION 3.17)
project(OpenMP_MPI)

set(CMAKE_CXX_STANDARD 14)

add_executable(OpenMP_MPI lab6/main.cpp lab6.1/main.cpp)