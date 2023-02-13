cmake_minimum_required(VERSION 3.21)
project(groupReporting)

set(CMAKE_CXX_STANDARD 14)

add_executable(groupReporting main.cpp treeTraverse.cpp treeTraverse.h avlTree.cpp avlTree.h sort.cpp sort.h)

add_executable(test test.cpp)
add_executable(sample sample.cpp)
add_executable(sunny sunny.cpp)
add_executable(tutorials tutorials.cpp)
add_executable(main main.cpp)