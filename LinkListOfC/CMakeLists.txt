cmake_minimum_required(VERSION 3.25)
project(LinkListOfC)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinkListOfC LinkList.hpp LinkList.hpp Test.cpp)
