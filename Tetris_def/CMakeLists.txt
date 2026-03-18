cmake_minimum_required(VERSION 3.16)

project(Tetris_def LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Tetris_def main.cpp
    piezas.h
    Piezas.cpp)

include(GNUInstallDirs)
install(TARGETS Tetris_def
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
