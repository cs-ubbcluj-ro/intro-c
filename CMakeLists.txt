cmake_minimum_required(VERSION 4.1)
project(app C)

set(CMAKE_C_STANDARD 23)

add_executable(app
        main.c
        simple_programs.c
        planets.c
        planets.h
        simple_programs.h)
