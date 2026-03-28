cmake_minimum_required(VERSION 4.2)
project(03___Exercicio_08 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(03___Exercicio_08
        arvore-binaria.c
        arvore-binaria.h
        pilhas-vetores.c
        pilhas-vetores.h
        pos-ordem-nrecursiva.c)
