cmake_minimum_required(VERSION 3.7)
project(23_01)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        TicTacToe.cpp
        TicTacToe.h)

add_executable(23_01 ${SOURCE_FILES})