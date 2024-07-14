cmake_minimum_required(VERSION 3.5)

project(task3_figures_methods LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task3_figures_methods main.cpp)

include(GNUInstallDirs)
install(TARGETS task3_figures_methods
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
