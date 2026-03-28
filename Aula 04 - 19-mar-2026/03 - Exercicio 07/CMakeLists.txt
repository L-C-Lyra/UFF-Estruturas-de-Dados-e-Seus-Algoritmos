cmake_minimum_required(VERSION 4.2)
project(03___Exercicio_07 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(03___Exercicio_07
        arvore-binaria.c
        arvore-binaria.h
        pilhas-vetores.c
        pilhas-vetores.h
        ordem-simetrica-nrecursiva.c)
