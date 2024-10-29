#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

// Definições de constantes
#define MAX_LIVROS 100
#define MAX_LEITORES 256
#define MAX_NOME 256
#define MAX_NUMEROLEITOR 12    // 11 dígitos + '\n'
#define MAX_NUMEROFORMATADO 16  // "(XX) XXXXX-XXXX" + '\n'
#define MAX_DADOSLEITOR 256

// Estrutura de dados para os livros
typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    int disponivel; // 1 se disponível, 0 se emprestado
} Livro;

//Estrutura de dados para os leitores que pegarem livros
typedef struct {
    char nomeLeitor[MAX_NOME];
    char numeroLeitorFormatado[MAX_NUMEROFORMATADO];
} InfoLeitor;

// Declaração das funções utilizadas no sistema
void adicionarLivro();
void listarLivros();
void buscarLivro();
void emprestarLivro();
void cadastrarLeitor(InfoLeitor *leitores);
void devolverLivro();
void removerLivro();
void carregarLivros();  // Carrega os livros de um arquivo
void salvarLivros();    // Salva os livros cadastrados no arquivo
void carregarLeitores(); // Carrega os leitores cadastrados no arquivo
void salvarLeitores(); // Cadastra e salva os leitores no arquivo

#endif
