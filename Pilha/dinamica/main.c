#include "pilha.h"
#include <stdio.h>

void inserir(pilha* stack) {
    char elem[max_str];

    printf("\nDigite a string a ser inserida: ");
    scanf(" %[^\n]", elem);
    getchar();

    if (push(stack, elem)) {
        printf("\n-> A string foi adicionada com sucesso.\n", elem);
    } else {
        printf("\n-> Nao foi possivel adicionar a string.\n");
    }
}

void remover(pilha* stack) {
    char elem[max_str];

    if (pop(stack, elem)) {
        printf("String removida: %s\n", elem);
    } else {
        printf("\n-> Nao foi possivel remover a string.\n");
    }
}

int main() {
    pilha stack = NULL;
    int condicao = 0;

    while (1) {
        int resposta = -1;

        printf("\n--- MENU TAD PILHA DE STRINGS ---\n");
        printf("0- Encerrar o programa\n");
        printf("1- Criar pilha\n");
        printf("2- Verificar se a pilha esta vazia\n");
        printf("3- Inserir string na pilha\n");
        printf("4- Remover string da pilha\n");
        printf("5- Verificar string no topo da pilha\n");
        printf("6- Apagar pilha\n");
        printf("7- Verificar tamanho da pilha\n");
        printf("8- Imprimir pilha\n");
        printf("\n-> Escolha uma das opcoes acima: ");

        scanf("%d", &resposta);
        getchar();

        if (resposta == 0) {
            if (condicao == 1) {
                apaga_pilha(&stack);
            }
            printf("\n-> Programa encerrado\n");
            return 0;
        }

        if (resposta != 1 && condicao == 0) {
            printf("\n-> A pilha ainda nao foi criada.\n");
        } else if (resposta == 1 && condicao == 1) {
            printf("\n-> A pilha ja foi criada!\n");
        } else {
            switch (resposta) {
                case 1:
                    stack = cria_pilha();
                    condicao = 1;
                    printf("\n-> Pilha criada com sucesso.\n");
                    break;

                case 2:
                    if (pilha_vazia(stack)) {
                        printf("\n-> A pilha esta vazia.\n");
                    } else {
                        printf("\n-> A pilha nao esta vazia.\n");
                    }
                    break;

                case 3:
                    inserir(&stack);
                    break;

                case 4:
                    remover(&stack);
                    break;

                case 5: {
                    char elem[max_str];
                    if (get_topo(stack, elem)) {
                        printf("String no topo: %s\n", elem);
                    } else {
                        printf("\n-> Nao foi possivel ler a string na pilha\n");
                    }
                    break;
                }
                case 6:
                    apaga_pilha(&stack);
                    printf("\n-> A pilha foi apagada.\n");
                    condicao = 0;
                    break;
                
                case 7: {
                    int tamanho = 0;
                    tamanho_pilha(stack, &tamanho);
                    printf("\n-> A pilha tem %d elementos.\n", tamanho);
                    break;
                }
                case 8: {
                    if (pilha_vazia(stack)) {
                        printf("\n-> A pilha esta vazia.\n");
                        break;
                    }
                    pilha invertida = cria_pilha();
                    char elem[max_str];

                    while (pilha_vazia(stack) == 0){
                        pop(&stack, elem);
                        push(&invertida, elem);
                    }
                    
                    printf("\n--Conteudo da Pilha--\n");
                    
                    while (pilha_vazia(invertida) == 0) {
                        pop(&invertida, elem);
                        printf("-> %s\n", elem);
                        push(&stack, elem);
                    }
                    apaga_pilha(&invertida);
                    break;
                }
                default:
                    printf("\n-> Opcao invalida.\n");
                    break;
            }
        }
    }
}