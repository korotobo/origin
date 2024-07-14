cmake_minimum_required(VERSION 3.5)

project(neto3dot2bills LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(neto3dot2bills main.cpp)

include(GNUInstallDirs)
install(TARGETS neto3dot2bills
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
