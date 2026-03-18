cmake_minimum_required(VERSION 3.16)

project(untitled3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(untitled3 main.cpp
    pieza.h
    piezas.cpp)

include(GNUInstallDirs)
install(TARGETS untitled3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
