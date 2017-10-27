cmake_minimum_required(VERSION 3.8)
project(paa)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c
        ordena.h)

add_executable(paa ${SOURCE_FILES})