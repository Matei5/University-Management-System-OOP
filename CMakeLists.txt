cmake_minimum_required(VERSION 3.27)
project(Proiect1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proiect1
        main.cpp
        src/AbstractStudent.cpp
        src/StudentAn1.cpp
        src/StudentAn2.cpp
        src/Profesor.cpp
        src/Examen.cpp
        src/MaterieAn1.cpp
        header.h)

target_include_directories (SrcP1 PUBLIC src)

