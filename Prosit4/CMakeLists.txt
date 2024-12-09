cmake_minimum_required(VERSION 3.29)
project(Prosit4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Prosit4 main.cpp
        CLpoint.cpp
        CLpoint.h
        CLparcours.cpp
        CLparcours.h
        CLpoint2D.h
        CLpoint3D.h
        CLparcours3D.h
        CLparcours2D.h
)
