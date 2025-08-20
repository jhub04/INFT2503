cmake_minimum_required(VERSION 3.31)
project(oving6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(oving6 main.cpp
        ChessBoard.cpp
        ChessBoard.hpp
        ChessBoardPrint.cpp
        ChessBoardPrint.hpp)
