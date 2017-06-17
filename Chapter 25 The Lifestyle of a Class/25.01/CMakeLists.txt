cmake_minimum_required(VERSION 3.7)
project(25_01)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        vectorOfInt.cpp
        vectorOfInt.h)

add_executable(25_01 ${SOURCE_FILES})