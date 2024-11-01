#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

// Array de leitores e contagem de leitores
InfoLeitor leitores[MAX_LEITORES];
int totalLeitores = 0;

void cabecalhoTabelaLeitores() {
    printf("+--------------------------------+----------------------+\n");
    printf("  | Nome                           | Telefone             | \n");
    printf("  +--------------------------------+----------------------+\n");
}

void exibirLeitores(const char* nome, const char* telefone) {
    printf("  | %-30s | %-19s  |\n", nome, telefone);
    printf("  +--------------------------------+----------------------+\n");
}

void listarLeitores() {
    if (totalLeitores == 0) {
        printf("Nenhum leitor cadastrado.\n");
        return;
    }
    cabecalhoTabelaLeitores();
    for (int i = 0; i < totalLeitores; i++) {
        exibirLeitores(leitores[i].nomeLeitor, leitores[i].numeroLeitorFormatado);
    }
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

int validarNomeLeitor(const char *nomeLeitor) {

    // Verifica se o usuario não deixou a entrada vazia
    if (strlen(nomeLeitor) == 0) {
        printf("Digite o nome do leitor.\n");
        return 0;
    }

    // Percorre cada caractere do nome do autor
    for (int i = 0; i < strlen(nomeLeitor); i++) {
        // Verifica se o caractere é uma letra, espaço ou ponto
        if (!isalpha(nomeLeitor[i]) && nomeLeitor[i] != ' ' && nomeLeitor[i] != '.') {
            return 0; // Não é válido
        }
    }

    return 1; // É válido

}

void cadastrarLeitor(InfoLeitor *leitores) {

    if (totalLeitores >= MAX_LEITORES) {
        printf("Limite de leitores atingido. Nao e possivel cadastrar mais leitores.\n");
        return;
    }

    // Loop para garantir que o usuário não insira números ou deixe espaços vazios
    do {
        printf("Digite o nome do leitor: ");
        fgets(leitores[totalLeitores].nomeLeitor, MAX_NOME, stdin);
        strtok(leitores[totalLeitores].nomeLeitor, "\n"); // Remove a nova linha, se existir

        if (!validarNomeLeitor(leitores[totalLeitores].nomeLeitor)) {
            printf("Nome invalido. Por favor, insira apenas letras, espacos e pontos.\n");
        }
    } while (!validarNomeLeitor(leitores[totalLeitores].nomeLeitor));

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

void removerLeitor() {
    int escolha;
    int leitorEncontrado = 0; // Verifica se o leitor foi encontrado
    char busca[MAX_NOME];

   if (totalLeitores == 0) {
       printf("Sem leitores cadastrados no sistema!\n");
       return;
   }

    printf("Digite o nome completo do leitor que deseja remover: ");
    fgets(busca, sizeof(busca), stdin);
    strtok(busca, "\n"); // Remove a nova linha, se existir

    for (int i = 0; i < totalLeitores; i++) {
        if ((strcasecmp(busca, leitores[i].nomeLeitor) == 0)) {
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