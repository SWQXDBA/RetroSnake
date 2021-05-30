cmake_minimum_required(VERSION 3.17)
project(RetroSnake)

set(CMAKE_CXX_STANDARD 14)

add_executable(main.cpp RetroSnaker.cpp RetroSnaker.h test.cpp)