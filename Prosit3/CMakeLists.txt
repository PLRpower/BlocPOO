cmake_minimum_required(VERSION 3.29)
project(Prosit3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Prosit3 main.cpp
        Forme2D.h
        Polygone.cpp
        Polygone.h
        Point.cpp
        Point.h
        Triangle.cpp
        Triangle.h
        Rectangle.cpp
        Rectangle.h
        Carre.cpp
        Carre.h
        Cercle.cpp
        Cercle.h)
