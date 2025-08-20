cmake_minimum_required(VERSION 3.31)
project(oving6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(oppgave1 main.cpp
        ChessBoard.cpp
        ChessBoard.hpp
        ChessBoardPrint.cpp
        ChessBoardPrint.hpp)

add_executable(oppgave2 webserver.cpp)
target_link_libraries(oppgave2 ${Boost_LIBRARIES})

