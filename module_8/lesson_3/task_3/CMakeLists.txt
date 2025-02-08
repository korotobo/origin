cmake_minimum_required(VERSION 3.16)

project(task_3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/error.log
    ${CMAKE_CURRENT_BINARY_DIR}/error.log COPYONLY)

add_executable(task_3 main.cpp)

include(GNUInstallDirs)
install(TARGETS task_3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
