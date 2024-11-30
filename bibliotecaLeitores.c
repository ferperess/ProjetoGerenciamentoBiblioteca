/**
 * @file bibliotecaLeitores.c
 * @brief Implementação das funções relacionadas ao gerenciamento de leitores
 * @authors Fernando Peres C. Gomes, Flabiano Henrique de Souza, João Vitor Costa e Silva, Lucas Sabino Guilherme
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

/** @brief Array de leitores e contagem de leitores */
InfoLeitor leitores[MAX_LEITORES];

/** @brief Variável para contagem do total de leitores */
int totalLeitores = 0;


/**
 * @brief Exibe o cabeçalho da tabela de leitores
 */
void cabecalhoTabelaLeitores() {
    printf("  +--------------------------------+----------------------+\n");
    printf("  | Nome                           | Telefone             | \n");
    printf("  +--------------------------------+----------------------+\n");
}

/**
 * @brief Exibe os dados de um leitor
 * @param nome Nome do leitor
 * @param telefone Telefone do leitor
 */
void exibirLeitores(const char* nome, const char* telefone) {
    printf("  | %-30s | %-19s  |\n", nome, telefone);
    printf("  +--------------------------------+----------------------+\n");
}

/**
 * @brief Lista todos os leitores cadastrados
 */
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

/**
 * @brief Salva os dados dos leitores em um arquivo
 */
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

/**
 * @brief Valida o nome do leitor
 * @param nomeLeitor Nome do leitor a ser validado
 * @return 1 se o nome é válido, 0 caso contrário
 */
int validarNomeLeitor(const char *nomeLeitor) {

    /** @brief Verifica se o usuário não deixou a entrada vazia */
    if (strlen(nomeLeitor) == 0) {
        printf("Digite o nome do leitor.\n");
        return 0;
    }

    /** @brief Percorre cada caractere do nome do autor */
    for (int i = 0; i < strlen(nomeLeitor); i++) {
        /** @brief Verifica se o caractere é uma letra, espaço ou ponto */
        if (!isalpha(nomeLeitor[i]) && nomeLeitor[i] != ' ' && nomeLeitor[i] != '.') {
            return 0;
        }
    }

    return 1;

}

/**
 * @brief Cadastra um novo leitor
 * @param leitores Array de leitores
 */
void cadastrarLeitor(InfoLeitor *leitores) {

    if (totalLeitores >= MAX_LEITORES) {
        printf("Limite de leitores atingido. Nao e possivel cadastrar mais leitores.\n");
        return;
    }

    /** @brief Loop para garantir que o usuário não insira números ou deixe espaços vazios */
    do {
        printf("Digite o nome do leitor: ");
        fgets(leitores[totalLeitores].nomeLeitor, MAX_NOME, stdin);
        strtok(leitores[totalLeitores].nomeLeitor, "\n"); /** @brief Remove a nova linha, se existir */

        if (!validarNomeLeitor(leitores[totalLeitores].nomeLeitor)) {
            printf("Nome invalido. Por favor, insira apenas letras, espacos e pontos.\n");
        }
    } while (!validarNomeLeitor(leitores[totalLeitores].nomeLeitor));

    /** @brief Loop até que um número de contato válido seja fornecido */
    char numeroTemporario[12];  /** @brief 11 dígitos + '\0' */
    int formatoValido = 0;

     /** @brief Loop até que um número de contato válido seja fornecido */
    while (!formatoValido) {
        printf("Digite o numero de contato do leitor (apenas numeros): ");
        fgets(numeroTemporario, sizeof(numeroTemporario), stdin);
        strtok(numeroTemporario, "\n"); /** @brief Remove o caractere de nova linha */

        /** @brief Valida se todos os caracteres são dígitos e se o comprimento é 11 */
        int valido = 1; /** @brief Flag para verificar se algum caractere é dígito */

        // Verifica se o número tem exatamente 11 dígitos
        if (strlen(numeroTemporario) != 11) {
            valido = 0; // Não é válido se não tiver 11 dígitos
        } else {
            for (int i = 0; i < strlen(numeroTemporario); i++) {
                if (!isdigit(numeroTemporario[i])) {
                    valido = 0; /** @brief Encontrou um caractere que não é dígito */
                    break;
                }
            }
        }

        if (valido) {
            /** @brief Formata o número */
            /** @brief Exemplo: "11987654321" -> "(11) 98765-4321" */
            sprintf(leitores[totalLeitores].numeroLeitorFormatado,
                    "(%c%c) %c%c%c%c%c-%c%c%c%c",
                    numeroTemporario[0], numeroTemporario[1],
                    numeroTemporario[2], numeroTemporario[3],
                    numeroTemporario[4], numeroTemporario[5],
                    numeroTemporario[6], numeroTemporario[7],
                    numeroTemporario[8], numeroTemporario[9],
                    numeroTemporario[10]);

            formatoValido = 1; /** @brief Número válido */
        } else {
            printf("\nFormato invalido. O numero deve ter exatamente 11 digitos e conter apenas numeros.\n");
        }
    }

    printf("\n");
    totalLeitores++; /** @brief Incrementa o contador de leitores */

    salvarLeitores(); /** @brief Salvar leitor recém-cadastrado e exibir mensagem de sucesso */

    return 0;
}

/**
 * @brief Carrega os dados dos leitores de um arquivo
 */void carregarLeitores() {

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

/**
 * @brief Remove um leitor do sistema
 */
void removerLeitor() {
    int escolha;
    int leitorEncontrado = 0; /** @brief Verifica se o leitor foi encontrado */
    char busca[MAX_NOME];

   if (totalLeitores == 0) {
       printf("Sem leitores cadastrados no sistema!\n");
       return;
   }

    printf("Digite o nome completo do leitor que deseja remover: ");
    fgets(busca, sizeof(busca), stdin);
    strtok(busca, "\n");

    for (int i = 0; i < totalLeitores; i++) {
        if ((strcasecmp(busca, leitores[i].nomeLeitor) == 0)) {
            printf("\nNome: %s | Telefone: %s \n", leitores[i].nomeLeitor, leitores[i].numeroLeitorFormatado);
            leitorEncontrado = 1;
            do {
                printf("Confirmar exclusao: \n1- SIM \n2- NAO\n");
                printf("Digite sua escolha: ");
                scanf("%d", &escolha);
                while ( (getchar()) != '\n' ); /** @brief Limpa o buffer */

                if (escolha == 1) {
                    for (int j = i; j < totalLeitores - 1; j++) {
                        leitores[j] = leitores[j + 1];
                    }
                    totalLeitores--;
                    printf("Leitor removido com sucesso!\n");
                    return; /** @brief Sai da função após remoção */
                } else if (escolha == 2) {
                    printf("Exclusao cancelada !\n");
                    return; /** @brief Sai da função após cancelar */
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
