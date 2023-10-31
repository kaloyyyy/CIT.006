cmake_minimum_required(VERSION 3.21)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
project(CIT_006)

set(CMAKE_CXX_STANDARD 14)

add_executable(CIT_006 main.cpp snake/main.cpp)

add_executable(exer1 exer1.cpp)
add_executable(snake_SnakeGame snake/main.cpp)