cmake_minimum_required(VERSION 3.15)
project(RyanSunye)

set(CMAKE_CXX_STANDARD 14)

add_executable(RyanSunye Calculator.cpp Calculator.h main.cpp)

add_executable(test test/Factest.cpp test/catch.hpp)

add_executable(test1 test/test1.cpp test/catch.hpp Calculator.h Calculator.cpp)