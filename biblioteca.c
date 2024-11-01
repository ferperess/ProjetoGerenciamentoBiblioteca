#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

// Array de livros e contagem de total de livros
Livro livros[MAX_LIVROS];
int totalLivros = 0;

// Array de leitores e contagem de leitores
InfoLeitor leitores[MAX_LEITORES];
int totalLeitores = 0;

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

void adicionarLivro() {

    Livro novoLivro;
    novoLivro.id = totalLivros + 1;
    printf("Digite o titulo do livro: ");
    fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
    strtok(novoLivro.titulo, "\n"); // Remove o '\n' no final

    printf("Digite o autor do livro: ");
    fgets(novoLivro.autor, sizeof(novoLivro.autor), stdin);
    strtok(novoLivro.autor, "\n");

    int anoValido = 0;
    while (!anoValido) {
        printf("Digite o ano de publicacao do livro (4 dígitos): ");
        int confirmacao = scanf("%d", &novoLivro.anoPublicacao);
        getchar(); // Limpa o buffer

        // Verifica se o ano é um inteiro de 4 dígitos
        if (confirmacao == 1 && novoLivro.anoPublicacao >= 1000 && novoLivro.anoPublicacao <= 9999) {
            anoValido = 1; // Ano válido
        } else {
            printf("O ano de publicacao deve possuir 4 numeros inteiros!\n");
        }
    }

    novoLivro.disponivel = 1; // Livro disponível por padrão
    livros[totalLivros] = novoLivro;
    totalLivros++;

    printf("Livro adicionado com sucesso!\n");
}

void cabecalhoTabelaLivros() {
    printf(BLUE "+-----+--------------------------------+-------------------------+-------------------+------------+\n" RESET);
    printf("| ID  | Titulo                         | Autor                   | Ano de Publicacao | Disponivel  |\n");
    printf(BLUE "+-----+--------------------------------+-------------------------+-------------------+------------+\n" RESET);
}

void cabecalhoTabelaLeitores() {
    printf(BLUE "+-----------------------------+-------------------------+\n" RESET);
    printf("| Nome                           | Telefone                | \n");
    printf(BLUE "+-------------------------------+-------------------------+\n" RESET);
}

void exibirLivro(Livro livro) {
    printf("| %-3d | %-30s | %-23s | %-17d | %-10s |\n",
           livro.id, livro.titulo, livro.autor,
           livro.anoPublicacao, livro.disponivel ? "Sim" : "Nao");
    printf(BLUE "+-----+--------------------------------+-------------------------+-------------------+------------+\n" RESET);
}

void exibirLeitores(const char* nome, const char* telefone) {
    printf("| %-30s | %-23s |\n", nome, telefone);
    printf(BLUE "+-------------------------------+-------------------------+\n" RESET);
}

void listarLivros() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    printf("Lista de livros:\n");
    cabecalhoTabelaLivros();
    for (int i = 0; i < totalLivros; i++) {
        exibirLivro(livros[i]);
    }
}

void listarLeitores() {
    if (totalLeitores == 0) {
        printf(RED "Nenhum leitor cadastrado.\n" RESET);
        return;
    }
    cabecalhoTabelaLeitores();
    for (int i = 0; i < totalLeitores; i++) {
        exibirLeitores(leitores[i].nomeLeitor, leitores[i].numeroLeitorFormatado);
    }
}


void buscarLivro() {
    char tituloBusca[MAX_NOME];
    printf("Digite o titulo do livro que deseja buscar: ");
    fgets(tituloBusca, sizeof(tituloBusca), stdin);
    strtok(tituloBusca, "\n"); // Remove a nova linha, se existir

    for (int i = 0; i < totalLivros; i++) {
        if (strcasecmp(livros[i].titulo, tituloBusca) == 0) {
            exibirLivro(livros[i]);
            return;
        }
    }

    printf("Livro nao encontrado.\n");
}


void salvarLeitores() {

    FILE *file = fopen("leitores.dat", "wb");
    if (file != NULL) {
        fwrite(&totalLeitores, sizeof(int), 1, file);
        fwrite(leitores, sizeof(InfoLeitor), totalLeitores, file);
        fclose(file);
        printf("Leitor cadastrado com sucesso!\n");
    } else {
        printf("Erro ao salvar os dados!\n");
    }
}


void cadastrarLeitor(InfoLeitor *leitores) {
    printf("Digite o nome do leitor: ");
    fgets(leitores[totalLeitores].nomeLeitor, MAX_NOME, stdin);
    strtok(leitores[totalLeitores].nomeLeitor, "\n"); // Remove a nova linha, se existir

    // Loop até que um número de contato válido seja fornecido
    char numeroTemp[12];  // 11 dígitos + '\0'
    int formatoValido = 0;

    while (!formatoValido) {
        printf("Digite o numero de contato do leitor (apenas numeros): ");
        fgets(numeroTemp, sizeof(numeroTemp), stdin);
        strtok(numeroTemp, "\n"); // Remove a nova linha, se existir

        // Verifica se o número de contato tem 11 dígitos
        if (strlen(numeroTemp) == 11) {

            // Formata o número
            // Exemplo: "11987654321" -> "(11) 98765-4321"
            sprintf(leitores[totalLeitores].numeroLeitorFormatado,
                    "(%c%c) %c%c%c%c%c-%c%c%c%c",
             numeroTemp[0], numeroTemp[1], numeroTemp[2],
             numeroTemp[3], numeroTemp[4], numeroTemp[5],
             numeroTemp[6], numeroTemp[7], numeroTemp[8],
             numeroTemp[9], numeroTemp[10]);

            formatoValido = 1; // Formato válido
        } else {
            printf("Formato invalido. O numero deve ter apenas 11 digitos.\n");
        }
    }

    totalLeitores++; // Incrementa o contador de leitores

    salvarLeitores(); // Salvar leitor recém-cadastrado

    printf("Cadastro efetuado com sucesso!"); //Mensagem de cadastro efetuado

}


void carregarLeitores() {

    FILE *file = fopen("leitores.dat", "rb");
    if (file != NULL) {
        fread(&totalLeitores, sizeof(int), 1, file);
        fread(leitores, sizeof(InfoLeitor), totalLeitores, file);
        fclose(file);
        printf("Dados dos leitores carregados com sucesso!\n");
    } else {
        printf("Nenhum leitor encontrado.\n");
    }
}


void emprestarLivro() {

    int opcao;
    char buscaLeitor[MAX_DADOSLEITOR];
    char dadosLeitor[MAX_DADOSLEITOR];


    do {
     printf("Leitor possui cadastro? \n1- SIM \n2- NAO");
     printf("Digite sua opcao: ");
     scanf("%d", &opcao);
     getchar(); // Limpa o buffer

        if (opcao == 1) {
            FILE *file = fopen("leitores.dat", "rb");
            if (file != NULL) {
                printf("Digite o nome completo do leitor: ");
                fgets(buscaLeitor, sizeof(buscaLeitor), stdin);
                buscaLeitor[strcspn(buscaLeitor, "\n")] = 0; // Remove a quebra de linha que pode ser capturada pelo fgets

                int leitorEncontrado = 0; // Para verificar se o leitor foi encontrado

                for(int i = 0; i < totalLeitores; i++) {
                    if (strcasecmp(buscaLeitor, leitores[i].nomeLeitor) == 0) {
                        printf("Dados encontrados!\n");
                        snprintf(dadosLeitor, sizeof(dadosLeitor), "Nome: %s\nContato: %s\n", leitores[i].nomeLeitor, leitores[i].numeroLeitorFormatado);
                        leitorEncontrado = 1;
                        break;
                    }
                }
                if (!leitorEncontrado) {
                    printf("Leitor não encontrado!\n");
                }
            } else {
                printf("ERRO: Nenhum arquivo disponível para buscar leitores.\n");
            }
        }else if (opcao == 2) {
            cadastrarLeitor(leitores);
            snprintf(dadosLeitor, sizeof(dadosLeitor), "Nome: %s\nContato: %s\n", leitores[totalLeitores - 1].nomeLeitor, leitores[totalLeitores - 1].numeroLeitorFormatado);
        } else {
            printf("Opcao invalida! Digite apenas uma das opcoes.\n");
        }
    } while(opcao != 1 && opcao != 2);


    char busca[MAX_NOME];

    printf("Digite o autor ou titulo do livro que deseja emprestar: ");
    fgets(busca, sizeof(busca), stdin);
    strtok(busca, "\n"); // Remove a nova linha, se existir

    for (int i = 0; i < totalLivros; i++) {
        if ((strcasecmp(busca, livros[i].titulo) == 0) || (strcasecmp(busca, livros[i].autor) == 0)) {
            if (livros[i].disponivel) {
                exibirLivro(livros[i]);
                       livros[i].disponivel = 0; // Marca o livro como indisponível agora
            } else {
                printf("Livro ja esta emprestado");
            }
        }
    } printf("Livro nao encontrado.\n");
}

void devolverLivro() {
    char busca[MAX_NOME];

    printf("Digite o autor ou titulo do livro que deseja devolver: ");
    fgets(busca, sizeof(busca), stdin);
    strtok(busca, "\n"); // Remove a nova linha, se existir

            for (int i = 0; i < totalLivros; i++) {
                if ((strcasecmp(busca, livros[i].titulo) == 0) || (strcasecmp(busca, livros[i].autor) == 0)) {
                    if (!livros[i].disponivel) {
                        livros[i].disponivel = 1;
                        printf("Livro %s devolvido com sucesso!\n", livros[i].titulo);
                        return;
                    } else {
                        printf("Livro ja esta disponivel!\n");
                        return;
                      }
                }
            }

    printf("Livro nao encontrado.\n");
}

void removerLivro() {
    int escolha;
    int livroEncontrado = 0; // Verifica se o livro foi encontrado
    char busca[MAX_NOME];

    printf("Digite o autor ou titulo do livro que deseja remover: ");
    fgets(busca, sizeof(busca), stdin);
    strtok(busca, "\n"); // Remove a nova linha, se existir

    for (int i = 0; i < totalLivros; i++) {
        if ((strcasecmp(busca, livros[i].titulo) == 0) || (strcasecmp(busca, livros[i].autor) == 0)) {
            printf("\nLivro %s | Autor: %s | Ano de Publicacao: %d\n", livros[i].titulo, livros[i].autor, livros[i].anoPublicacao);
            livroEncontrado = 1;
            do {
                printf("Confirmar exclusao: \n1- SIM \n2- NAO\n");
                printf("Digite sua escolha: ");
                scanf("%d", &escolha);
                getchar(); // Limpa o buffer

                if (escolha == 1) {
                    for (int j = i; j < totalLivros - 1; j++) {
                        livros[j] = livros[j + 1];
                        livros[j].id = j + 1; // Atualiza o ID para manter a sequência
                    }
                    totalLivros--;
                    printf("Livro removido com sucesso!\n");
                    return; // Sai da função após remoção
                } else if (escolha == 2) {
                    printf("Exclusao cancelada !\n");
                    return; // Sai da função após cancelar
                } else {
                    printf("Opcao invalida! Digite apenas 1 ou 2.\n");
                }
            } while (1);
        }
      }
    if (!livroEncontrado) {
        printf("Livro nao encontrado.\n");
    }
}

void removerLeitor() {
    int escolha;
    int leitorEncontrado = 0; // Verifica se o leitor foi encontrado
    char busca[MAX_NOME];

    printf("Digite o nome completo do leitor que deseja remover: ");
    fgets(busca, sizeof(busca), stdin);
    strtok(busca, "\n"); // Remove a nova linha, se existir

    for (int i = 0; i < totalLeitores; i++) {
        if ((strcasecmp(busca, leitores[i].nomeLeitor) == 0) {
            printf("\nNome: %s | Telefone: %s \n", leitores[i].nomeLeitor, leitores[i].numeroLeitorFormatado);
            leitorEncontrado = 1;
            do {
                printf("Confirmar exclusao: \n1- SIM \n2- NAO\n");
                printf("Digite sua escolha: ");
                scanf("%d", &escolha);
                getchar(); // Limpa o buffer

                if (escolha == 1) {
                    for (int j = i; j < totalLeitores - 1; j++) {
                        leitores[j] = leitores[j + 1];
                    }
                    totalLeitores--;
                    printf("Leitor removido com sucesso!\n");
                    return; // Sai da função após remoção
                } else if (escolha == 2) {
                    printf("Exclusao cancelada !\n");
                    return; // Sai da função após cancelar
                } else {
                    printf("Opcao invalida! Digite apenas 1 ou 2.\n");
                }
            } while (1);
        }
    }
    if (!leitorEncontrado) {
        printf("Leitor nao encontrado.\n");
    }
}