cmake_minimum_required(VERSION 3.6)
project(MineSweeper)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp Models/Board.cpp Models/Board.h Models/Square.cpp Models/Square.h helpers.cpp)
add_executable(MineSweeper ${SOURCE_FILES})