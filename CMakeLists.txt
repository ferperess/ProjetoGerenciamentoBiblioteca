cmake_minimum_required(VERSION 3.29)
project(Projeto C)

set(CMAKE_C_STANDARD 11)

add_executable(Projeto main.c
        biblioteca.h
        bibliotecaLivros.c
        bibliotecaLeitores.c
)
