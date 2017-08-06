cmake_minimum_required(VERSION 3.7)
project(28_03)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp XMLParser.cpp XMLParser.h)
add_executable(28_03 ${SOURCE_FILES} XMLParser.cpp XMLParser.h)