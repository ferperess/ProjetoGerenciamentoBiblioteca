#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void exibirMenu() {
    printf("\n--- Sistema de Biblioteca ---\n\n");
    printf("1. Cadastrar leitor\n");
    printf("2. Adicionar livro\n");
    printf("3. Listar livros\n");
    printf("4. Buscar livro\n");
    printf("5. Emprestar livro\n");
    printf("6. Devolver livro\n");
    printf("7. Remover livro\n");
    printf("8. Sair\n");
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
                cadastrarLeitor();
            break;
            case 2:
                adicionarLivro();
            break;
            case 3:
                listarLivros();
            break;
            case 4:
                buscarLivro();
            break;
            case 5:
                emprestarLivro();
            break;
            case 6:
                devolverLivro();
            break;
            case 7:
                removerLivro();
            break;
            case 8:
                salvarLivros(); // Salva os livros cadastrados antes de encerrar o sistema
                salvarLeitores(); //Salva os leitores cadastrados antes de encerrar o sistema
                printf("\nDados salvos.\n");
                printf("\nSaindo do sistema...\n");
                exit(0);
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
