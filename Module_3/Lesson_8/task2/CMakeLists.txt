cmake_minimum_required(VERSION 3.5)

project(task2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task2 main.cpp
    figure.h figure.cpp
    triangle.h triangle.cpp
    triangle_rect.h triangle_rect.cpp
    triangle_isos.h triangle_isos.cpp
    triangle_equil.h triangle_equil.cpp
    square.h square.cpp
    rhomb.h rhomb.cpp
    rectangle.h rectangle.cpp
    quadrangle.h quadrangle.cpp
    parallelogram.h parallelogram.cpp
    my_exception.h my_exception.cpp)

include(GNUInstallDirs)
install(TARGETS task2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
