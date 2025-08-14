cmake_minimum_required(VERSION 3.31)
project(oving3)

set(CMAKE_CXX_STANDARD 20)

add_executable(oving3 main.cpp)
add_executable(oppgave12 oppgave12.cpp)
add_executable(oppgave3 oppgave3.cpp
        commodity.hpp
        commodity.cpp)
add_executable(oppgave4 oppgave4.cpp)