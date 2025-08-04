#include "TAD_circular.h"
#include <stdio.h>

void inserir(lista *list){
    char elem;
    int resposta;

    printf("\nDigite o caracter a ser adicionado: ");
    getchar();
    scanf("%c", &elem);

    printf("\n0-Cancelar a operacao\n");
    printf("1-Adicionar no inicio\n");
    printf("2-Adicionar no final\n");
    printf("Escolha a opcao: ");
    scanf("%d", &resposta);

    if(resposta == 1){
        if(insere_inicio(list, elem)==1){
            printf("\n->O caracter foi adicionado com sucesso\n");
        } else{
            printf("\n->Nao foi possivel adicionar o caracter\n");
        }

    } else if(resposta == 2){
        if(insere_final(list, elem)==1){
            printf("\n->O caracter foi adicionado com sucesso\n");
        } else{
            printf("\n->Nao foi possivel adicionar o caracter\n");
        }

    } else{
        printf("\n->Operacao cancelada\n");
    }
}

void remover(lista *list){
    char elem;
    int resposta;

    printf("\n0-Cancelar a operacao\n");
    printf("1-Remover do inicio\n");
    printf("2-Remover do final\n");
    printf("Escolha a opcao: ");
    scanf("%d", &resposta);

    if(resposta == 1){
        if(remove_inicio(list, &elem)==1){
            printf("\n->O caracter '%c' foi removido com sucesso\n", elem);
        } else{
            printf("\n->Nao foi possivel remover o caracter\n");
        }

    } else if(resposta == 2){
        if(remove_final(list, &elem)==1){
            printf("\n->O caracter '%c' foi removido com sucesso\n", elem);
        } else{
            printf("\n->Nao foi possivel remover o caracter\n");
        }

    } else{
        printf("\n->Operacao cancelada\n");
    }
}

int main(){
    lista list = NULL;
    int condicao = 0;

    while (1){
        int resposta = -1;

        printf("\n---MENU TAD LISTA CIRCULAR DE CARACTERES---\n");
        printf("0-Encerrar o programa\n");
        printf("1-Criar Lista\n");
        printf("2-Verificar se a lista esta vazia\n");
        printf("3-Inserir o caracter da lista\n");
        //printf("4-Inserir o caracter no final da lista\n");
        printf("4-Remover o caracter da lista\n");
        printf("5-Verificar tamanho da lista\n");
        //printf("6-Remover o caracter no final da lista\n");
        //printf("7-Apagar lista\n");
        printf("\nEscolha uma das opcoes acima: ");

        scanf("%d", &resposta);

        if(resposta==0){
            if(condicao==0){
                printf("\n->Programa encerrado\n");
                return 0;
            }
            //apaga_lista(&list);
            return 0;
        }

        if(resposta != 1 && condicao == 0){
            printf("\n->A lista ainda nao foi criada\n");

        } else if(resposta==1 && condicao == 1){
            printf("\n->So eh possivel criar uma lista!\n");
        }

        else{
            switch (resposta)
            {
            case 1:
                list = criar_lista();
                condicao = 1;
                printf("\n->Lista criada com sucesso.\n");
                break;

            case 2:
                if(lista_vazia(list)==1){
                    printf("\n->A lista esta vazia\n");
                } else{
                    printf("\n->a lista nao esta vazia\n");
                }
                break;

            case 3:
                inserir(&list);
                break;

            case 4:
                remover(&list);
                break;

            case 5:
                int tamanho=0;
                tamanho_lista(list, &tamanho);

                if(tamanho>0){
                    printf("\n->A lista tem %d caracteres\n", tamanho);
                } else{
                    printf("\n->A lista esta vazia\n");
                }
                break;

            default:
                break;
            }
        }
    }
}