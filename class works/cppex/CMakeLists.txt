cmake_minimum_required(VERSION 3.24)
project(cppex)

set(CMAKE_CXX_STANDARD 23)

add_executable(cppex main.cpp model/Animal.cpp model/Animal.h)
