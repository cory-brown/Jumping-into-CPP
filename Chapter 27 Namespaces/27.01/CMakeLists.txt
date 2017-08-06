cmake_minimum_required(VERSION 3.7)
project(27_01)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp vectorOfInts.cpp vectorOfInts.h)
add_executable(27_01 ${SOURCE_FILES} vectorOfInts.cpp vectorOfInts.h)