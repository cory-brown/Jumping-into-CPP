cmake_minimum_required(VERSION 3.7)
project(28_02)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp HTMLParser.cpp HTMLParser.h)

add_executable(28_02 ${SOURCE_FILES} HTMLParser.cpp HTMLParser.h)