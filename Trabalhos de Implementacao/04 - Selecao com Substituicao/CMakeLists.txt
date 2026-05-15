cmake_minimum_required(VERSION 4.2)
project(04___Selecao_com_Substituicao C)

set(CMAKE_C_STANDARD 11)

add_executable(04___Selecao_com_Substituicao
        geracao.c)

file(COPY entrada.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
