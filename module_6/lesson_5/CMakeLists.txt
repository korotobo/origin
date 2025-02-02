cmake_minimum_required(VERSION 3.16)

project(lesson_5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lesson_5 main.cpp)

# add_subdirectory(/... libpqxx-build)

include(GNUInstallDirs)
install(TARGETS lesson_5
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# target_compile_features(lesson_5 PRIVATE cxx_std_17)

target_link_libraries(lesson_5 pqxx)

