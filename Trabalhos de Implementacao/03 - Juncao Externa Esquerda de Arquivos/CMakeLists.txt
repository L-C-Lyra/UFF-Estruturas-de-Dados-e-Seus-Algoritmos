cmake_minimum_required(VERSION 4.2)
project(03___Juncao_Externa_Esquerda_de_Arquivos C)

set(CMAKE_C_STANDARD 11)

add_executable(03___Juncao_Externa_Esquerda_de_Arquivos
        left-outer-join.c)

file(COPY departamentos.txt funcionarios.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
