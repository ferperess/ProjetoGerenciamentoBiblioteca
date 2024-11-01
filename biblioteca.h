#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

// Definições de constantes
#define MAX_LIVROS 200
#define MAX_LEITORES 512
#define MAX_NOME 512
#define MAX_NUMEROLEITOR 12    // 11 dígitos + '\n'
#define MAX_NUMEROFORMATADO 16  // "(XX) XXXXX-XXXX" + '\n'
#define MAX_DADOSLEITOR 512


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

// Declaração das variáveis globais
extern Livro livros[MAX_LIVROS];
extern int totalLivros;

extern InfoLeitor leitores[MAX_LEITORES];
extern int totalLeitores;

// Declaração das funções utilizadas no sistema

void adicionarLivro(); // Adiciona novo livro no arquivo
int validarAutor(autor); // Verifica se o usuário digitou algum número ou deixou o espaço vazio
void cabecalhoTabelaLivros(); // Formatação para lista dos livros cadastrados
void exibirLivro(); // Exibe o livro buscado
void listarLivros(); // Lista os livros cadastrados no arquivo
void buscarLivro(); // Busca livro pelo nome do autor ou pelo título
void emprestarLivro(); // Emprestar o livro, marcando como indisponível no sistema
void devolverLivro(); // Devolve livro e marca como disponível no sistema
void removerLivro(); // Remove livro do arquivo de livros cadastrados
void carregarLivros();  // Carrega os livros de um arquivo
void salvarLivros();    // Salva os livros cadastrados no arquivo

void cabecalhoTabelaLeitores(); // Formatação para lista dos leitores cadastrados
void exibirLeitores(); // Exibe o leitor buscado
int validarNomeLeitor(nomeLeitor); // Verifica se o usuário digitou algum número ou deixou o espaço vazio
void cadastrarLeitor(); // Cadastra novo leitor
void removerLeitor(); // Remove leitor do do arquivo de leitores cadastrados
void carregarLeitores(); // Carrega os leitores cadastrados no arquivo
void salvarLeitores(); // Cadastra e salva os leitores no arquivo

#endif
