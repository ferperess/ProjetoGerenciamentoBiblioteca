cmake_minimum_required(VERSION 3.29)
project(Projeto C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(Projeto
        main.c
        biblioteca.h
        bibliotecaLivros.c
        bibliotecaLeitores.c
)

# Inclui diretório para arquivos de cabeçalho
target_include_directories(Projeto PRIVATE .)