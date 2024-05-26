CMAKE_MINIMUM_REQUIRED(VERSION 3.28.3 FATAL_ERROR)

SET(CMAKE_CXX_STANDARD 23)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

PROJECT(University)

ADD_EXECUTABLE(
    Cursework main.cpp
    Student.h
    Student.cpp
    List.h
    Triple.h
    University.h
    University.cpp
)