cmake_minimum_required(VERSION 3.16)

project(task_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/filecommand.log
    ${CMAKE_CURRENT_BINARY_DIR}/filecommand.log COPYONLY)

add_executable(task_1 main.cpp)

include(GNUInstallDirs)
install(TARGETS task_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
