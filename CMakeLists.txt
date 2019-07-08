cmake_minimum_required(VERSION 3.14)
project(elaborato_A_star)

set(CMAKE_CXX_STANDARD 11)

add_executable(elaborato_A_star main.cpp Mappa.cpp Mappa.h Punto.cpp Punto.h MapSearchNode.cpp MapSearchNode.h)