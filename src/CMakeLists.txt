cmake_minimum_required(VERSION 3.27)
project(SrcP1)

set(CMAKE_CXX_STANDARD 17)

add_executable(SrcP1
        src/AbstractStudent.cpp
        src/StudentAn1.cpp
        src/StudentAn2.cpp
        src/Profesor.cpp
        src/Examen.cpp
        src/MaterieAn1.cpp)
