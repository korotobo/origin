cmake_minimum_required(VERSION 3.5)

project(task3_class_hierarchy1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task3_class_hierarchy1 main.cpp
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

include(GNUInstallDirs)
install(TARGETS task3_class_hierarchy1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
