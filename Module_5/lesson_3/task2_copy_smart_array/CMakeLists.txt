cmake_minimum_required(VERSION 3.5)

project(task2_copy_smart_array LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task2_copy_smart_array main.cpp
    smart_array.h smart_array.cpp)

include(GNUInstallDirs)
install(TARGETS task2_copy_smart_array
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
