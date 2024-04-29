cmake_minimum_required(VERSION 3.27)
project(Proiect1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proiect1
        main.cpp
        header.h)

target_include_directories (SrcP1 PUBLIC src)

