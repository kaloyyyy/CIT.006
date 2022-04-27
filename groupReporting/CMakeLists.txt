cmake_minimum_required(VERSION 3.21)
project(groupReporting)

set(CMAKE_CXX_STANDARD 14)

add_executable(groupReporting main.cpp treeTraverse.cpp treeTraverse.h avlTree.cpp avlTree.h sort.cpp sort.h)
