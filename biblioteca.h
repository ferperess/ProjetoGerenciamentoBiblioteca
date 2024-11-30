/**
 * @file biblioteca.h
 * @brief Arquivo de cabeçalho contendo definições e declarações para o sistema de biblioteca
 * @authors Fenrnando Peres C. Gomes, Flabiano Henrique de Souza, João Vitor Costa e Silva, Lucas Sabino Guilherme
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

/**
 * @def MAX_LIVROS
 * @brief Número máximo de livros que podem ser cadastrados
 */
#define MAX_LIVROS 200

/**
* @brief Definições de limites e tamanhos para informações de leitores
*
* @def MAX_LEITORES
* Número máximo de leitores que podem ser cadastrados
* @def MAX_NOME
* Número máximo de caracteres para o nome
* @def MAX_NUMEROLEITOR
* Número máximo de caracteres para o numero de contato do leitor (11 dígitos + '\0')
* @def MAX_NUMEROFORMATADO
* Número máximo de caracteres para o numero de contato do leitor formatado ("(XX) XXXXX-XXXX" + '\0')
* @def MAX_DADOSLEITOR
* Número máximo de caracteres para exibição das informações do leitor
*/
#define MAX_LEITORES 512
#define MAX_NOME 512
#define MAX_NUMEROLEITOR 12
#define MAX_NUMEROFORMATADO 16
#define MAX_DADOSLEITOR 512


/**
 * @struct Livro
 * @brief Estrutura que representa um livro no sistema
 *
 * @var Livro::id
 * Identificador único do livro
 * @var Livro::anoPublicacao
 * Ano em que o livro foi publicado
 * @var Livro::titulo
 * Título do livro
 * @var Livro::autor
 * Nome do autor do livro
 * @var Livro::totalExemplares
 * Quantidade total de exemplares do livro
 * @var Livro::exemplaresDisponiveis
 * Quantidade de exemplares atualmente disponíveis
 */
typedef struct {
    int id;
    int anoPublicacao;
    char titulo[100];
    char autor[100];
    int totalExemplares;
    int exemplaresDisponiveis;
} Livro;

/**
 * @struct InfoLeitor
 * @brief Estrutura que representa um leitor no sistema
 *
 * @var InfoLeitor::nomeLeitor
 * Nome completo do leitor
 * @var InfoLeitor::numeroLeitorFormatado
 * Número de telefone do leitor no formato (XX) XXXXX-XXXX
 */
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

/**
 * @brief Adiciona um novo livro ao sistema
 * @return void
 */
void cadastrarLivro();

/**
 * @brief Valida o nome do autor
 * @param autor String contendo o nome do autor a ser validado
 * @return int Retorna 1 se válido, 0 se inválido
 */
int validarAutor(autor);

/**
 * @brief Exibe o cabeçalho da tabela de livros
 */
void cabecalhoTabelaLivros();

/**
 * @brief Lista todos os livros cadastrados no sistema
 */
void exibirLivro();

/**
 * @brief Lista todos os livros cadastrados no sistema
 */
void listarLivros();

/**
 * @brief Busca um livro por título ou autor
 */
void buscarLivro();


/**
 * @brief Realiza o empréstimo de um livro
 */
void emprestarLivro();

/**
 * @brief Registra a devolução de um livro
 */
void devolverLivro();

/**
 * @brief Remove um livro do sistema
 */
void removerLivro();

/**
 * @brief Carrega os dados dos livros do arquivo
 */
void carregarLivros();

/**
 * @brief Salva os dados dos livros em arquivo
 */
void salvarLivros();

/**
 * @brief Exibe o cabeçalho formatado da tabela de leitores
 *
 * Formata e exibe o cabeçalho para a listagem dos leitores cadastrados
 */
void cabecalhoTabelaLeitores();

/**
 * @brief Exibe as informações de um leitor específico
 *
 * Mostra os dados detalhados do leitor que foi buscado no sistema
 */
void exibirLeitores();

/**
 * @brief Lista todos os leitores cadastrados
 *
 * Exibe uma lista completa de todos os leitores que estão cadastrados no arquivo
 */
void listarLeitores();

/**
 * @brief Valida o nome do leitor
 *
 * Verifica se o nome do leitor é válido, checando se não contém números
 * e se não está vazio
 *
 * @param nomeLeitor Nome do leitor a ser validado
 * @return int Retorna 1 se o nome for válido, 0 caso contrário
 */
int validarNomeLeitor(nomeLeitor);

/**
 * @brief Cadastra um novo leitor no sistema
 *
 * Solicita e registra as informações de um novo leitor no sistema
 */
void cadastrarLeitor();

/**
 * @brief Remove um leitor do sistema
 *
 * Remove o registro de um leitor do arquivo de leitores cadastrados
 */
void removerLeitor();

/**
 * @brief Carrega os dados dos leitores
 *
 * Lê e carrega as informações dos leitores a partir do arquivo de cadastro
 */
void carregarLeitores();

/**
 * @brief Salva os dados dos leitores
 *
 * Salva as informações dos leitores no arquivo de cadastro
 */
void salvarLeitores();

#endif