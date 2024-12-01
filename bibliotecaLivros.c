/**
 * @file bibliotecaLivros.c
 * @brief Implementação das funções relacionadas ao gerenciamento de livros
 * @authors Fernando Peres C. Gomes, Flabiano Henrique de Souza, João Vitor Costa e Silva, Lucas Sabino Guilherme
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"

/**
 * @brief Array de livros
 */
Livro livros[MAX_LIVROS];

/**
 * @brief Variável para contagem do total de livros
 */
int totalLivros = 0;

 /**
 * @file bibliotecaLivros.c
 * @brief Implementação das funções de gerenciamento de livros
 */



/**
 * @brief Carrega os livros salvos em arquivo
 *
 * Lê os dados dos livros do arquivo livros.dat e os carrega na memória.
 * Se o arquivo não existir, exibe uma mensagem informativa.
 */
void carregarLivros() {

    FILE *file = fopen("livros.dat", "rb");
    if (file != NULL) {
        fread(&totalLivros, sizeof(int), 1, file);
        fread(livros, sizeof(Livro), totalLivros, file);
        fclose(file);
        printf("Dados carregados com sucesso!\n");
    } else {
        printf("Nenhum dado anterior encontrado.\n");
    }
}

/**
 * @brief Salva os livros em arquivo
 *
 * Salva todos os dados dos livros no arquivo livros.dat.
 * Exibe mensagem de sucesso ou erro conforme o resultado da operação.
 */
void salvarLivros() {

    FILE *file = fopen("livros.dat", "wb");
    if (file != NULL) {
        fwrite(&totalLivros, sizeof(int), 1, file);
        fwrite(livros, sizeof(Livro), totalLivros, file);
        fclose(file);
        printf("Dados salvos com sucesso!\n");
    } else {
        printf("Erro ao salvar os dados.\n");
    }
}

/**
 * @brief Valida o nome do autor
 *
 * @param autor String contendo o nome do autor a ser validado
 * @return int Retorna 1 se o nome for válido, 0 caso contrário
 */
int validarAutor(const char *autor) {

    /** @brief Verifica se o usuario não deixou a entrada vazia */
    if (strlen(autor) == 0) {
        printf("Digite o nome do autor.\n");
        return 0;
    }

    /** @brief Percorre cada caractere do nome do autor */
    for (int i = 0; i < strlen(autor); i++) {
        /** @brief Verifica se o caractere é uma letra, espaço ou ponto */
        if (!isalpha(autor[i]) && autor[i] != ' ' && autor[i] != '.' && autor[i] != '-') {
            return 0;
        }
    }

    return 1;

}

/**
 * @brief Adiciona um novo livro ao sistema
 *
 * Solicita ao usuário todas as informações necessárias para cadastrar
 * um novo livro e o adiciona ao sistema.
 */
void cadastrarLivro() {
    Livro novoLivro;

    printf("Digite o titulo do livro: ");
    fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
    strtok(novoLivro.titulo, "\n"); // Remove o '\n' no final

    /** @brief Loop para grantir que o usuário não insira números ou deixe espaços vazios */
    do {
    printf("Digite o autor do livro: ");
    fgets(novoLivro.autor, sizeof(novoLivro.autor), stdin);
    strtok(novoLivro.autor, "\n");

        if (!validarAutor(novoLivro.autor)) {
            printf("Nome do autor invalido. Por favor, insira apenas letras, espacos e pontos.\n");
            }
        } while (!validarAutor(novoLivro.autor));

    int anoValido = 0;
    while (!anoValido) {
        printf("Digite o ano de publicacao do livro (4 digitos): ");
        int confirmacao = scanf("%d", &novoLivro.anoPublicacao);
        while ( (getchar()) != '\n' ); /** @brief Limpa o buffer */

        /** @brief Verifica se o ano é um inteiro de 4 dígitos */
        if (confirmacao == 1 && novoLivro.anoPublicacao >= 1000 && novoLivro.anoPublicacao <= 9999) {
            anoValido = 1;
        } else {
            printf("O ano de publicacao deve possuir 4 numeros inteiros!\n");
        }
    }

    /** @brief Registra a quantidade de exemplares */
    do {
        printf("Digite a quantidade total de exemplares: ");
        if (scanf("%d", &novoLivro.totalExemplares) != 1) {
            printf("ERRO! Por favor, digite um numero valido.\n");
            while (getchar() != '\n'); /** @internal Limpa o buffer */
            novoLivro.totalExemplares = 0;
            continue;
        }

        if (novoLivro.totalExemplares <= 0) {
            printf("ERRO: A quantidade de exemplares deve ser maior que zero.\n");
        }
    } while (novoLivro.totalExemplares <= 0);


    if (totalLivros > 0){
    int livroExistente = 0;

    for (int i = 0; i < totalLivros; i++) {

        /** @brief Verifica se já existe um livro igual */
        if ((strcasecmp(novoLivro.autor, livros[i].autor) == 0) &&
            (strcasecmp(novoLivro.titulo, livros[i].titulo) == 0) &&
            (novoLivro.anoPublicacao == livros[i].anoPublicacao)) {

            livros[i].totalExemplares = livros[i].totalExemplares + novoLivro.totalExemplares ;
            livros[i].exemplaresDisponiveis = livros[i].exemplaresDisponiveis + novoLivro.totalExemplares;
            livroExistente = 1;
            }
    }

    if (!livroExistente) {  /** @brief Se o livro não existe, adiciona em outra linha */
        novoLivro.exemplaresDisponiveis = novoLivro.totalExemplares;
        novoLivro.id = totalLivros + 1;
        livros[totalLivros] = novoLivro;
        totalLivros++;
    }

} else {  /** @brief Caso seja o primeiro da biblioteca */
    novoLivro.exemplaresDisponiveis = novoLivro.totalExemplares;
    novoLivro.id = totalLivros + 1;
    livros[totalLivros] = novoLivro;
    totalLivros++;
}

    salvarLivros(); /** @brief Salvar livro recém-adicionado e exibe mensagem de sucesso */
}

/**
 * @brief Exibe o cabeçalho da tabela de livros
 */
void cabecalhoTabelaLivros() {
    printf("+-----+--------------------------------+-------------------------+-------------------+-----------------+\n");
    printf("| ID  | Titulo                         | Autor                   | Ano de Publicacao | Disponibilidade |\n");
    printf("+-----+--------------------------------+-------------------------+-------------------+-----------------+\n");
}


/**
 * @brief Exibe as informações de um livro específico
 *
 * @param livro Estrutura Livro contendo as informações a serem exibidas
 */
void exibirLivro(Livro livro) {

    printf("| %-3d | %-30s | %-23s | %-17d | %3d / %-7d   |\n",
              livro.id,
              livro.titulo,
              livro.autor,
              livro.anoPublicacao,
              livro.exemplaresDisponiveis,
              livro.totalExemplares);
    printf("+-----+--------------------------------+-------------------------+-------------------+-----------------+\n");
}


/**
 * @brief Lista todos os livros cadastrados no sistema
 */
void listarLivros() {

    if (totalLivros == 0) {
        printf("Sem livros cadastrados no sistema!\n");
        return;
    }
    printf("Lista de livros:\n");
    cabecalhoTabelaLivros();
    for (int i = 0; i < totalLivros; i++) {
        exibirLivro(livros[i]);
    }
}

/**
 * @brief Busca um livro pelo título ou autor
 */
void buscarLivro() {
    char tituloBusca[MAX_NOME];

   if (totalLivros == 0) {
       printf("Sem livros cadastrados no sistema\n");
       return;
   }

    printf("Digite o nome do autor ou titulo do livro que deseja buscar: ");
    fgets(tituloBusca, sizeof(tituloBusca), stdin);
    strtok(tituloBusca, "\n");

    int livroEncontrado = 0;  /** @brief Variável para verificar se algum livro foi encontrado */

    for (int i = 0; i < totalLivros; i++) {
        if ((strcasecmp(livros[i].titulo, tituloBusca) == 0) || (strcasecmp(livros[i].autor, tituloBusca) == 0)){
            if (!livroEncontrado) {
                printf("\n");
                cabecalhoTabelaLivros();
                livroEncontrado = 1;  /** @brief Marca que pelo menos um livro foi encontrado */
            }
            exibirLivro(livros[i]);
        }
    }

    if (!livroEncontrado) {
        printf("Livro nao encontrado.\n");
    }

    return;

}


/**
 * @brief Realiza o empréstimo de um livro
 */
void emprestarLivro() {

    int opcao;
    char buscaLeitor[MAX_DADOSLEITOR];
    char dadosLeitor[MAX_DADOSLEITOR];

    /** @brief Verifica se possui algum livro cadastrado */
    if(totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    do {
        printf("Leitor possui cadastro? \n1- SIM \n2- NAO\n");
        printf("Digite sua opcao: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Por favor, digite 1 ou 2.\n");
            while (getchar() != '\n'); /** @brief Limpa o buffer */
            continue;
        }
        while (getchar() != '\n'); /** @brief Limpa o buffer após o scanf */

        if (opcao == 1) {
            FILE *file = fopen("leitores.dat", "rb");
            if (file != NULL) {
                printf("Digite o nome completo do leitor: ");
                fgets(buscaLeitor, sizeof(buscaLeitor), stdin);
                buscaLeitor[strcspn(buscaLeitor, "\n")] = 0; /** @brief Remove a quebra de linha que pode ser capturada pelo fgets */

                int leitorEncontrado = 0; /** @brief Para verificar se o leitor foi encontrado */

                for(int i = 0; i < totalLeitores; i++) {
                    if (strcasecmp(buscaLeitor, leitores[i].nomeLeitor) == 0) {
                        printf("Dados encontrados!\n");
                        snprintf(dadosLeitor, sizeof(dadosLeitor), "Nome: %s\nContato: %s\n", leitores[i].nomeLeitor, leitores[i].numeroLeitorFormatado);
                        leitorEncontrado = 1;
                        break;
                    }
                }
                if (!leitorEncontrado) {
                    printf("\n\nLeitor nao encontrado! Cadastre o leitor!\n\n");
                    cadastrarLeitor(leitores);
                }
                fclose(file);
            } else {
                printf("ERRO: Nenhum arquivo disponivel para buscar leitores.\n");
            }
        }else if (opcao == 2) {
            cadastrarLeitor(leitores);
        }
        snprintf(dadosLeitor, sizeof(dadosLeitor), "Nome: %s\nContato: %s\n", leitores[totalLeitores - 1].nomeLeitor, leitores[totalLeitores - 1].numeroLeitorFormatado);
    } while(opcao != 1 && opcao != 2);

    /** @brief Limpa completamente o buffer antes de pedir a entrada */
    while ( (getchar()) != '\n' );

    /** @brief Mostra os livros disponíveis */
    listarLivros();

    char busca[MAX_NOME];
    int livroEncontrado = 0;


    printf("Digite o nome do autor ou titulo do livro que deseja emprestar: ");
    if (fgets(busca, sizeof(busca), stdin) != NULL) {
        busca[strcspn(busca, "\n")] = 0;


        for (int i = 0; i < totalLivros; i++) {
            if ((strcasecmp(busca, livros[i].titulo) == 0) || (strcasecmp(busca, livros[i].autor) == 0)) {
                livroEncontrado = 1;
                if (livros[i].exemplaresDisponiveis > 0) {
                    printf("\nLivro encontrado:\n");
                    cabecalhoTabelaLivros();
                    exibirLivro(livros[i]);

                    printf("\nConfirmar emprestimo? (1 - Sim, 2 - Nao): ");
                    scanf("%d", &opcao);
                    getchar();

                    if (opcao == 1) {
                        livros[i].exemplaresDisponiveis--;
                        printf("\nEmprestimo realizado com sucesso!\n");
                        printf("Detalhes do emprestimo:\n");
                        printf("%s", dadosLeitor);
                        printf("Livro: %s\n", livros[i].titulo);
                        printf("Exemplares restantes: %d/%d\n", livros[i].exemplaresDisponiveis, livros[i].totalExemplares);
                        salvarLivros();
                    } else {
                        printf("Emprestimo cancelado.\n");
                    }
                } else {
                    printf("Todos os exemplares deste livro estao emprestados.\n");
                }
                return;
            }
        }
    }

    if (!livroEncontrado) {
        printf("Livro nao encontrado.\n");
    }
}


/**
 * @brief Registra a devolução de um livro
 */
void devolverLivro() {
    char busca[MAX_NOME];
    int livroEncontrado = 0;


    if (totalLivros == 0) {
        printf("Sem livros emprestados no sistema!\n");
        return;
    }

    printf("\nLivros cadastrados:\n");
    listarLivros();

        printf("Digite o autor ou titulo do livro que deseja devolver: ");
        fgets(busca, sizeof(busca), stdin);
        strtok(busca, "\n");

        for (int i = 0; i < totalLivros; i++) {
            if ((strcasecmp(busca, livros[i].titulo) == 0) || (strcasecmp(busca, livros[i].autor) == 0)) {
                livroEncontrado = 1;

                if (livros[i].exemplaresDisponiveis < livros[i].totalExemplares) {
                    livros[i].exemplaresDisponiveis++;
                    printf("\nLivro devolvido com sucesso!\n");
                    printf("Detalhes atualizados do livro:\n");
                    cabecalhoTabelaLivros();
                    exibirLivro(livros[i]);
                    salvarLivros();
                    return;
                } else {
                    printf("\nTodos os exemplares deste livro ja estao disponiveis!\n");
                    return;
                }
            }
        }

        printf("Livro nao encontrado.\n");
    }


/**
* @brief Remove um livro do sistema
*/
    void removerLivro() {
        int escolha;
        int livroEncontrado = 0; /** @brief Verifica se o livro foi encontrado */
        char busca[MAX_NOME];

        if (totalLivros == 0) {
            printf("\nERRO! Nao ha livros cadastrados para remover.\n");
            return;
        }

        printf("Digite o nome do autor ou titulo do livro que deseja remover: ");
        fgets(busca, sizeof(busca), stdin);
        strtok(busca, "\n");

        for (int i = 0; i < totalLivros; i++) {
            if ((strcasecmp(busca, livros[i].titulo) == 0) || (strcasecmp(busca, livros[i].autor) == 0)) {
                livroEncontrado = 1;

                /** @brief Verifica se há exemplares emprestados */
                if (livros[i].exemplaresDisponiveis < livros[i].totalExemplares && livros[i].exemplaresDisponiveis > 0 ) {
                    printf("\nAVISO: Ha exemplares emprestados deste livro.\n");
                    cabecalhoTabelaLivros();
                    exibirLivro(livros[i]);

                    do {
                        printf("\nO que deseja fazer?\n");
                        printf("1 - Remover apenas os exemplares disponiveis\n");
                        printf("2 - Escolher quantidade\n");
                        printf("3 - Cancelar remocao\n");
                        printf("Digite sua escolha: ");
                        scanf("%d", &escolha);
                        while ( (getchar()) != '\n' );

                        if (escolha == 1) {
                            livros[i].totalExemplares = livros[i].totalExemplares - livros[i].exemplaresDisponiveis;
                            livros[i].exemplaresDisponiveis = 0;
                            printf("Exemplares disponiveis removidos com sucesso!\n");
                            salvarLivros();
                            return;
                        } else if (escolha == 2) {
                            int quantidade;
                            printf("Digite a quantidade de livros que deseja remover: ");
                            scanf("%d", &quantidade);
                            while ( (getchar()) != '\n' );
                            livros[i].totalExemplares = livros[i].totalExemplares - quantidade;
                            printf("Exemplares removidos com sucesso!\n");
                            salvarLivros();
                            return;
                        }else if (escolha == 3) {
                            printf("Remocao cancelada.\n");
                            return;
                        } else {
                            printf("Opcao invalida! Digite apenas 1 ou 2.\n");
                        }
                    } while (1);
                } else if (livros[i].exemplaresDisponiveis == livros[i].totalExemplares){

                    /** @brief Se todos os exemplares estão disponíveis, segue com a remoção normal */
                    do {
                        printf("\nO que deseja fazer?\n");
                        printf("1 - Remover todos os exemplares disponiveis\n");
                        printf("2 - Escolher quantidade\n");
                        printf("3 - Cancelar remocao\n");
                        printf("Digite sua escolha: ");
                        scanf("%d", &escolha);
                        while ( (getchar()) != '\n' );

                        if (escolha == 1) {
                            int confirmacao;
                            printf("\nConfirmar exclusao completa do livro: \n1- SIM \n2- NAO\n");
                            printf("Digite sua escolha: ");
                            scanf("%d", &confirmacao);
                            while ( (getchar()) != '\n' );

                            if (confirmacao == 1) {
                                for (int j = i; j < totalLivros - 1; j++) {
                                    livros[j] = livros[j + 1];
                                    livros[j].id = j + 1; /** @brief Atualiza o ID para manter a sequência */
                                }
                                totalLivros--;
                                printf("Livro removido com sucesso!\n");
                                salvarLivros();
                                return;
                            } else if (confirmacao == 2) {
                                printf ("Exclusao cancelada!\n");
                                return;
                            } else {
                                printf("Opcao invalida! Digite apenas 1, 2 ou 3.\n");
                            }
                        } else if (escolha == 2) {

                            do {
                                int quantidade;
                                printf("Digite a quantidade de livros que deseja remover: ");
                                scanf("%d", &quantidade);
                                while ( (getchar()) != '\n' );

                                if (quantidade > 0 && quantidade <= livros[i].totalExemplares) {
                                    livros[i].totalExemplares -= quantidade;
                                    livros[i].exemplaresDisponiveis -= quantidade;
                                    printf("Exemplares removidos com sucesso!\n");
                                    salvarLivros();
                                    return;
                                } else {
                                    printf("Quantidade invalida! Deve ser maior que 0 e menor ou igual ao total de exemplares.\n");
                                }
                            } while (1);
                        } else if (escolha == 3) {
                            printf("Exclusao cancelada!\n");
                            return;
                        } else {
                            printf("Opcao invalida! Digite apenas 1, 2 ou 3.\n");
                        }
                    } while (1);
                }
                printf("\n");
                cabecalhoTabelaLivros();
                exibirLivro(livros[i]);
                printf("Sem exemplares disponiveis para exclusao do cadastro\n");
            }
        }
        if (!livroEncontrado) {
            printf("Livro nao encontrado.\n");
        }
}
