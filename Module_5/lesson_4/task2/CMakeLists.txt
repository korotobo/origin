cmake_minimum_required(VERSION 3.5)

project(task2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory(catch2)
find_package(Catch2 3 REQUIRED)

add_executable(task2 main.cpp)

include(GNUInstallDirs)
install(TARGETS task2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_link_libraries(task2 PRIVATE Catch2::Catch2WithMain)
