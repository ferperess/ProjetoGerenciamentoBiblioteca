#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

// Definições de constantes
#define MAX_LIVROS 100
#define MAX_LEITORES 256
#define MAX_NOME 256
#define MAX_NUMEROLEITOR 12    // 11 dígitos + '\n'
#define MAX_NUMEROFORMATADO 16  // "(XX) XXXXX-XXXX" + '\n'
#define MAX_DADOSLEITOR 256

// Definições para a tabela de exibição dos livros e leitores
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

// Estrutura de dados para os livros
typedef struct {
    int id;
    int anoPublicacao;
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

void adicionarLivro(); // Adiciona novo livro no arquivo
void cabecalhoTabelaLivros(); // Formatação para lista dos livros cadastrados
void exibirLivro(); // Exibe o livro buscado
void listarLivros(); // Lista os livros cadastrados no arquivo
void buscarLivro(); // Busca livro pelo nome do autor ou pelo título
void emprestarLivro(); // Emprestar o livro, marcando como indisponível no sistema
void exibirLivro(); // Exibe o livro procurado
void devolverLivro(); // Devolve livro e marca como disponível no sistema
void removerLivro(); // Remove livro do arquivo de livros cadastrados
void carregarLivros();  // Carrega os livros de um arquivo
void salvarLivros();    // Salva os livros cadastrados no arquivo

void cabecalhoTabelaLeitores(); // Formatação para lista dos leitores cadastrados
void exibirLeitores(); // Exibe o leitor buscado
void cadastrarLeitor(InfoLeitor *leitores); // Cadastra novo leitor
void removerLeitor(); // Remove leitor do do arquivo de leitores cadastrados
void carregarLeitores(); // Carrega os leitores cadastrados no arquivo
void salvarLeitores(); // Cadastra e salva os leitores no arquivo

#endif
