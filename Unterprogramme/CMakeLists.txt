cmake_minimum_required(VERSION 3.28)
project(Unterprogramme C)

set(CMAKE_C_STANDARD 11)

add_executable(Unterprogramme main.c
        MyIO.c
        MyIO.h
        CounterModul.h
        CounterModul.c
)
