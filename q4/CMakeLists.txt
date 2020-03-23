
cmake_minimum_required(VERSION 3.7)
project(q4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Werror")

add_executable(q4 main.cpp)
