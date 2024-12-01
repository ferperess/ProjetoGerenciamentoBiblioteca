# Define a versão mínima do CMake necessária
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(Projeto)

# Adiciona os arquivos-fonte ao projeto
add_executable(Projeto
        bibliotecaLeitores.c
        bibliotecaLivros.c
        main.c
        biblioteca.h
)