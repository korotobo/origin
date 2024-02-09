cmake_minimum_required(VERSION 3.5)

project(task1_directives LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task1_directives main.cpp
    add.h add.cpp)

include(GNUInstallDirs)
install(TARGETS task1_directives
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
