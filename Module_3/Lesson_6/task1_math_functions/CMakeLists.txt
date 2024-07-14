cmake_minimum_required(VERSION 3.5)

project(task1_math_functions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task1_math_functions main.cpp
    math_func.h math_func.cpp)

include(GNUInstallDirs)
install(TARGETS task1_math_functions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
