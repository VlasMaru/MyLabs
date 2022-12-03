cmake_minimum_required(VERSION 3.25.0)

set(PROJECT_NAME test)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

include_directories("inc/")

add_executable("${PROJECT_NAME}" Practic_2.cpp
                                inc/fuun.hpp
                                src/fuun.cpp)
