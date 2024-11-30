# Sistema de Gerenciamento de Biblioteca

## Descrição
Este é um sistema de gerenciamento de biblioteca desenvolvido em C. Ele permite o cadastro de livros e leitores, realiza empréstimos e devoluções, e oferece funcionalidades de busca e remoção.

Projeto para faculdade com os seguintes requisitos:  

- Objetivo Geral: Desenvolver um sistema para gerenciar o acervo de uma biblioteca,permitindo adicionar, remover, buscar e listar livros.
 
- Estrutura Base ( struct ): Informações sobre livros (ID, título, autor, ano de publicação, exemplares disponíveis).
   
- Funcionalidades: Cadastro de novos livros, remoção, busca por título ou autor, listagem de todos os livros, e persistência dos dados em arquivos

## Funcionalidades
- Cadastro e gerenciamento de livros
- Cadastro e gerenciamento de leitores
- Sistema de empréstimo e devolução
- Busca de livros por título ou autor
- Remoção de livros e leitores
- Listagem de todos os livros cadastrados
- Listagem de todos os leitores cadastrados

## Tecnologias Utilizadas
- Linguagem C
- Armazenamento em arquivos (.dat)

## Pré-requisitos
- Compilador C (GCC recomendado)
- Sistema operacional compatível (Windows, Linux, macOS)

## Instalação
1. Clone o repositório: https://github.com/ferperess/ProjetoGerenciamentoBiblioteca
2. Navegue até o diretório do projeto: cd ProjetoGerenciamentoBiblioteca
3. Compile o projeto usando o comando: `gcc main.c bibliotecaLivros.c bibliotecaLeitores.c -o biblioteca`

## Como Executar
Ainda no terminal ou prompt de comando, execute: './biblioteca'

## Como Usar
1. Execute o programa compilado
2. Siga as instruções no menu para navegar pelas funcionalidades
 - 1: Cadastrar leitor
 - 2: Listar leitores
 - 3: Adicionar livro
 - 4: Listar livros
 - 5: Buscar livro
 - 6: Emprestar livro
 - 7: Devolver livro
 - 8: Remover livro
 - 9: Remover leitor
 - 10: Sair

## Estrutura do Projeto
- `main.c`: Contém a função main e o menu principal
- `biblioteca.h`: Header file com definições de estruturas e protótipos de funções
- `bibliotecaLivros.c`: Implementações relacionadas ao gerenciamento de livros
- `bibliotecaLeitores.c`: Implementações relacionadas ao gerenciamento de leitores

## Documentação
Para uma documentação mais detalhada, incluindo o manual do usuário e a descrição completa das funções, consulte o arquivo MANUAL.md neste repositório.

## Autores
- Fernando Peres Colombo Gomes
- Flabiano Henrique de Souza
- João Vitor Costa e Silva
- Lucas Sabino Guilherme

