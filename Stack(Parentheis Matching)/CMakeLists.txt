cmake_minimum_required(VERSION 3.25)
project(Stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(Stack test.cpp Stack.h Stack.cpp)
