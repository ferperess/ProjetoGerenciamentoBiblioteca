#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"

// Array de livros e contagem de total de livros
Livro livros[MAX_LIVROS];
int totalLivros = 0;


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

int validarAutor(const char *autor) {

    // Verifica se o usuario não deixou a entrada vazia
    if (strlen(autor) == 0) {
        printf("Digite o nome do autor.\n");
        return 0;
    }

    // Percorre cada caractere do nome do autor
    for (int i = 0; i < strlen(autor); i++) {
        // Verifica se o caractere é uma letra, espaço ou ponto
        if (!isalpha(autor[i]) && autor[i] != ' ' && autor[i] != '.') {
            return 0; // Não é válido
        }
    }

    return 1; // É válido

}

void adicionarLivro() {
    Livro novoLivro;
    novoLivro.id = totalLivros + 1;

    printf("Digite o titulo do livro: ");
    fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
    strtok(novoLivro.titulo, "\n"); // Remove o '\n' no final

    // Loop para grantir que o usuário não insira números ou deixe espaços vazios
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
    printf("+-----+--------------------------------+-------------------------+-------------------+------------+\n");
    printf("| ID  | Titulo                         | Autor                   | Ano de Publicacao | Disponivel |\n");
    printf("+-----+--------------------------------+-------------------------+-------------------+------------+\n");
}


void exibirLivro(Livro livro) {
    printf("| %-3d | %-30s | %-23s | %-17d | %-10s |\n",
           livro.id, livro.titulo, livro.autor,
           livro.anoPublicacao, livro.disponivel ? "Sim" : "Nao");
    printf("+-----+--------------------------------+-------------------------+-------------------+------------+\n");
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


void buscarLivro() {
    char tituloBusca[MAX_NOME];

   if (totalLivros == 0) {
       printf("Sem livros cadastrados no sistema\n");
       return;
   }

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


void emprestarLivro() {

    int opcao;
    char buscaLeitor[MAX_DADOSLEITOR];
    char dadosLeitor[MAX_DADOSLEITOR];

    // Verifica se possui algum livro cadastrado
    if(totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    do {
     printf("Leitor possui cadastro? \n1- SIM \n2- NAO");
     printf("\nDigite sua opcao: ");
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
                    printf("Leitor nao encontrado! Cadstre o leitor\n\n");
                    cadastrarLeitor(leitores);
                    snprintf(dadosLeitor, sizeof(dadosLeitor), "Nome: %s\nContato: %s\n", leitores[totalLeitores - 1].nomeLeitor, leitores[totalLeitores - 1].numeroLeitorFormatado);
                }
            } else {
                printf("ERRO: Nenhum arquivo disponivel para buscar leitores.\n");
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


    if (totalLivros == 0) {
        printf("Sem livros emprestados no sistema!\n");
        return;
    }

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
                printf("\nLivro: %s | Autor: %s | Ano de Publicacao: %d\n", livros[i].titulo, livros[i].autor, livros[i].anoPublicacao);
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
