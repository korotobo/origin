cmake_minimum_required(VERSION 3.5)

project(task2_sides_and_corners LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task2_sides_and_corners main.cpp)

include(GNUInstallDirs)
install(TARGETS task2_sides_and_corners
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
