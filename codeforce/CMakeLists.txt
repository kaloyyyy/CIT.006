cmake_minimum_required(VERSION 3.24)
project(codeforce)

set(CMAKE_CXX_STANDARD 17)

add_executable(codeforce main.cpp)

add_executable(test test.cpp)
add_executable(gluglu gluglu.cpp)