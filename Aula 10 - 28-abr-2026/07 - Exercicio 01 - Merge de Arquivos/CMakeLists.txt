cmake_minimum_required(VERSION 4.2)
project(07___Exercicio_01___Merge_de_Arquivos C)

set(CMAKE_C_STANDARD 11)

add_executable(07___Exercicio_01___Merge_de_Arquivos
        merge.c)

file(COPY numeros1.txt numeros2.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
