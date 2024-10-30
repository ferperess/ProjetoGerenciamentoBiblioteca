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

    novoLivro.disponivel = 1; // Livro disponível por padrão
    livros[totalLivros] = novoLivro;
    totalLivros++;

    printf("Livro adicionado com sucesso!\n");
}

void listarLivros() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("Lista de livros:\n");
    for (int i = 0; i < totalLivros; i++) {
        printf("ID: %d | Titulo: %s | Autor: %s | Disponivel: %s\n",
               livros[i].id, livros[i].titulo, livros[i].autor,
               livros[i].disponivel ? "Sim" : "Nao");
    }
}

void buscarLivro() {
    char tituloBusca[MAX_NOME];
    printf("Digite o titulo do livro que deseja buscar: ");
    fgets(tituloBusca, sizeof(tituloBusca), stdin);
    strtok(tituloBusca, "\n");

    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(livros[i].titulo, tituloBusca) == 0) {
            printf("Livro encontrado: ID: %d | Autor: %s | Disponivel: %s\n",
                   livros[i].id, livros[i].autor,
                   livros[i].disponivel ? "Sim" : "Nao");
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
    strtok(leitores[totalLeitores].nomeLeitor, "\n");// Remove a nova linha, se existir

    // Loop até que um número de contato válido seja fornecido
    char numeroTemp[12];  // 11 dígitos + '\0'
    int formatoValido = 0;
    while (!formatoValido) {
        printf("Digite o numero de contato do leitor (apenas numeros): ");
        fgets(numeroTemp, sizeof(numeroTemp), stdin);
        strtok(numeroTemp, "\n"); // Remove a nova linha, se existir

        // Verifica se o número de contato tem 11 dígitos
        if (strlen(numeroTemp) == 11) {

            //formata o número
            // Exemplo: "11987654321" -> "(11) 98765-4321"
            sprintf(leitores[totalLeitores].numeroLeitorFormatado,
                    "(%c%c) %c%c%c%c%c-%c%c%c%c",
             numeroTemp[0], numeroTemp[1], numeroTemp[2],
             numeroTemp[3], numeroTemp[4], numeroTemp[5],
             numeroTemp[6], numeroTemp[7], numeroTemp[8],
             numeroTemp[9], numeroTemp[10]);

            formatoValido = 1; // Formato válido
        } else {
            printf("Formato invalido. O numero deve ter 11 digitos.\n");
        }
    }

        totalLeitores++; // Incrementa o contador de leitores

    salvarLeitores(); // Salvar leitores após o cadastro

    printf("Cadastro efetuado com sucesso!"); //Mensagem de cadastro efetuado

    totalLeitores++; // Incrementa o contador de leitores
}


void carregarLeitores() {

    FILE *file = fopen("leitores.dat", "rb");
    if (file != NULL) {
        fread(&totalLeitores, sizeof(int), 1, file);
        fread(leitores, sizeof(InfoLeitor), totalLeitores, file);
        fclose(file);
        printf("Dados carregados com sucesso!\n");
    } else {
        printf("Nenhum dado encontrado.\n");
    }
}

void validarId(int *id, char *mensagem) {
    int resultado;

    while (1) {
        // Loop até que uma entrada válida seja recebida
        printf("\n%s", mensagem);

        resultado = scanf("%d", id); // Verifica se é número inteiro

        if (resultado == 1 && *id > 0) {
            break; // Caso seja inteiro positivo, encerra o loop
        } else {
            printf("Entrada inválida! Por favor, digite um número inteiro.\n");
            while (getchar() != '\n'); // Limpa até encontrar a quebra linha
        }
    }
}

void emprestarLivro() {

    carregarLeitores();

    int opcao;
    char buscaLeitor[MAX_DADOSLEITOR];
    char dadosLeitor[MAX_DADOSLEITOR];


    do {
     printf("Leitor possui cadastro? \n1- SIM \n2- NÃO");
     printf("Digite sua opção: ");
     scanf("%d", &opcao);
     getchar(); // Limpa o buffer

        if (opcao == 1) {
            if (file != NULL) {
                printf("Digite o nome completo do leitor: ");
                fgets(buscaLeitor, sizeof(buscaLeitor), stdin);
                buscaLeitor[strcspn(buscaLeitor, "\n")] = 0; // Remove a quebra de linha que pode ser capturada pelo fgets

                int leitorEncontrado = 0; // Para verificar se o leitor foi encontrado

                for(int i = 0; i < totalLeitores; i++) {
                    if (strcasecmp(buscaLeitor, leitores[i].nomeLeitor) == 0) {
                        printf("Dados encontrados!\n");
                        snprintf(dadosLeitor, sizeof(dadosLeitor), "Nome: %s\nContato: %s\n", leitores[i].nomeLeitor, leitores[i].contato);
                        leitorEncontrado = 1;
                        break;
                    }
                }
                if (!leitorEncontrado) {
                    printf("Leitor não encontrado!\n");
                }
            } else {
                printf("Erro: Nenhum arquivo disponível para buscar leitores.\n");
            }
        }else if (opcao == 2) {
            cadastrarLeitor();
            snprintf(dadosLeitor, sizeof(dadosLeitor), "Nome: %s\nContato: %s\n", leitores[totalLeitores - 1].nomeLeitor, leitores[totalLeitores - 1].numeroLeitorFormatado);
        } else {
            printf("Opcao invalida! Digite apenas uma das opções.\n");
        }
    } while(opcao != 1 && opcao != 2);


    int id;
    char mensagem[] = "Digite o ID do livro que deseja emprestar: ";

    validarId(&id, mensagem); // Função que valida se o ID é número inteiro

        for (int i = 0; i < totalLivros; i++) {
            if (livros[i].id == id && livros[i].disponivel) {
                livros[i].disponivel = 0;
                printf("\nLivro %s emprestado com sucesso!\n", livros[i].titulo);
                printf("%s\n", dadosLeitor);
                return;
            }
        }

    printf("Livro nao encontrado ou ja esta emprestado.\n");
}

void devolverLivro() {
    int id;
    char mensagem[] = "Digite o ID do livro que deseja devolver: ";

    validarId(&id, mensagem); // Função que valida se o ID é número inteiro

            for (int i = 0; i < totalLivros; i++) {
                if (livros[i].id == id && !livros[i].disponivel) {
                    livros[i].disponivel = 1;
                    printf("Livro %s devolvido com sucesso!\n", livros[i]);
                    return;
                }
            }

    printf("Livro nao encontrado ou ja está disponivel.\n");
}

void removerLivro() {
    int escolha;
    int id;
    char mensagem[] = "Digite o ID do livro que deseja remover: ";

    int livroEncontrado = 0; // Flag para verificar se o livro foi encontrado

    validarId(&id, mensagem); // Função que valida se o ID é número inteiro

    for (int i = 0; i < totalLivros; i++) {
        if (livros[i].id == id) {
            livroEncontrado = 1;
            printf("\nLivro %s | Autor: %s \n", livros[i].titulo, livros[i].autor);
            do {
                printf("Confirmar exclusão: \n1- SIM \n2- NÃO\n");
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
                    printf("Exclusão cancelada !\n");
                    return; // Sai da função após cancelar
                } else {
                    printf("Opção inválida! Digite apenas 1 ou 2.\n");
                }
            } while (1);
        }
      }
    if (!livroEncontrado) {
        printf("Livro não encontrado.\n");
    }
}