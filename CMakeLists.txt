cmake_minimum_required(VERSION 3.29)
project(midterm)

set(CMAKE_CXX_STANDARD 20)

add_executable(midterm main.cpp
        Structs/Point.cpp
        Structs/Point.h
        Structs/Line.cpp
        Structs/Line.h
        Structs/Triangle.cpp
        Structs/Triangle.h
        Structs/EquilateralTriangle.cpp
        Structs/EquilateralTriangle.h
        Structs/PointsComparator.cpp)
