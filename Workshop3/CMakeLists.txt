cmake_minimum_required(VERSION 3.29)
project(Workshop3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Workshop3 main.cpp
        Ex1/Vehicule.cpp
        Ex1/Bus.cpp
        Ex1/Bus.h
        Ex1/SchoolBus.cpp
        Ex1/SchoolBus.h
        Ex2/House.cpp
        Ex2/House.h
        Ex2/Room.cpp
        Ex2/Room.h
        Ex2/Bathroom.cpp
        Ex2/Bathroom.h
        Ex2/Bedroom.cpp
        Ex2/Bedroom.h
        Ex3/Objet2D.cpp
        Ex3/Objet2D.h
        Ex3/Rectangle.cpp
        Ex3/Rectangle.h
        Ex3/Carre.cpp
        Ex3/Carre.h)
