cmake_minimum_required(VERSION 3.5)

project(task1_smart_array1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task1_smart_array1 main.cpp
    smart_array.h smart_array.cpp)

include(GNUInstallDirs)
install(TARGETS task1_smart_array1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
