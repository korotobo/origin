cmake_minimum_required(VERSION 3.16)

project(task_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/errors.log
    ${CMAKE_CURRENT_BINARY_DIR}/errors.log COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/fatal_errors.log
    ${CMAKE_CURRENT_BINARY_DIR}/fatal_errors.log COPYONLY)    

add_executable(task_2 main.cpp)

include(GNUInstallDirs)
install(TARGETS task_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
