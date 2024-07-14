cmake_minimum_required(VERSION 3.5)

project(a_complex_project LANGUAGES CXX)

add_executable(a_complex_project main.cpp
    figure.h figure.cpp
    triangle.h triangle.cpp
    triangle_rect.h triangle_rect.cpp
    triangle_isos.h triangle_isos.cpp
    triangle_equil.h triangle_equil.cpp
    square.h square.cpp
    rhomb.h rhomb.cpp
    rectangle.h rectangle.cpp
    quadrangle.h quadrangle.cpp
    parallelogram.h parallelogram.cpp)


