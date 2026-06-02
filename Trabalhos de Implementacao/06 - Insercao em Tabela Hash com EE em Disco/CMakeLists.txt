cmake_minimum_required(VERSION 4.2)
project(06___Insercao_em_Tabela_Hash_com_EE_em_Disco C)

set(CMAKE_C_STANDARD 11)

add_executable(06___Insercao_em_Tabela_Hash_com_EE_em_Disco
        encadeamento_exterior.c)

file(COPY clientes.dat tabHash.dat DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
