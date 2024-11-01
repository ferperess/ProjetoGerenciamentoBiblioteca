#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <string.h>

extern InfoLeitor leitores[MAX_LEITORES];

void exibirMenu() {
    printf("\n--- Gerenciamento de Biblioteca ---\n\n");
    printf("1. Cadastrar leitor\n");
    printf("2. Listar leitores\n");
    printf("3. Adicionar livro\n");
    printf("4. Listar livros\n");
    printf("5. Buscar livro\n");
    printf("6. Emprestar livro\n");
    printf("7. Devolver livro\n");
    printf("8. Remover livro\n");
    printf("9. Remover leitor\n");
    printf("10. Sair\n");
}

int main() {

    carregarLivros(); // Carrega os dados de livros salvos anteriormente
    carregarLeitores(); // Carrega os dados de leitores salvos anteriormente

    int escolha;
    while (1) {
        exibirMenu();
        printf("\nDigite sua opcao:  ");
        scanf("%d", &escolha);
        getchar(); // Limpa o buffer

        switch (escolha) {
            case 1:
                cadastrarLeitor(leitores);
            break;
            case 2:
                listarLeitores();
            break;
            case 3:
                adicionarLivro();
            break;
            case 4:
                listarLivros();
            break;
            case 5:
                buscarLivro();
            break;
            case 6:
                emprestarLivro();
            break;
            case 7:
                devolverLivro();
            break;
            case 8:
                removerLivro();
            break;
            case 9:
                removerLeitor();
            break;
            case 10:
                salvarLivros(); // Salva os livros cadastrados antes de encerrar o sistema
                salvarLeitores(); //Salva os leitores cadastrados antes de encerrar o sistema
                printf("\nDados salvos.\n");
                printf("\nSaindo do sistema...\n");
                exit(0);
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
