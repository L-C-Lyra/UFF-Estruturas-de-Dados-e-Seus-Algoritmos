cmake_minimum_required(VERSION 3.30)
project(02___Implementacao_01___TP C)

set(CMAKE_C_STANDARD 11)

add_executable(02___Implementacao_01___TP main.c
        TP_VD/TP_VD.h
        TP_VD/TP_VD.c
        TP_LSE/TP_LSE.h
        TP_LSE/TP_LSE.c)
