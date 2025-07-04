cmake_minimum_required(VERSION 3.30)
project(proyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(proyecto main.cpp
        tablero.cpp
        tablero.h)
