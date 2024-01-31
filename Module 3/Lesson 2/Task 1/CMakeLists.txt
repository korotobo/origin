cmake_minimum_required(VERSION 3.5)

project(neto3dot1enum LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(neto3dot1enum main.cpp)

include(GNUInstallDirs)
install(TARGETS neto3dot1enum
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
