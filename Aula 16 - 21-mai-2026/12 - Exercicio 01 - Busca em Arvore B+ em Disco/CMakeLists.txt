cmake_minimum_required(VERSION 4.2)
project(12___Exercicio_01___Busca_em_Arvore_B__em_Disco C)

set(CMAKE_C_STANDARD 11)

add_executable(12___Exercicio_01___Busca_em_Arvore_B__em_Disco
        arvore_b_mais.c)

file(COPY clientes.dat indice.dat metadados.dat DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
