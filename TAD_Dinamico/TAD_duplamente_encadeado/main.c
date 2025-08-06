#include "TAD_duplamente.h"
#include <stdio.h>

void inserir(lista *list){
    int elem;

    printf("\nDigite o inteiro a ser adicionado: ");
    scanf("%d", &elem);

    if(insere_elem(list, elem)==1){
        printf("\n->O numero foi adicionado com sucesso\n");
    } else{
        printf("\n->Nao foi possivel adicionar o numero\n");
    }
}

void remover(lista *list){
    int elem;

    printf("\nDigite o inteiro a ser removido: ");
    scanf("%d", &elem);

    if(remove_elem(list, elem)==1){
        printf("\n->O numero foi removido da lista com sucesso\n");
    } else{
        printf("\n->Nao foi possivel remover o numero da lista\n");
    }
}

int main(){
    lista list = NULL;
    int condicao = 0;

    while (1){
        int resposta = -1;

        printf("\n---MENU TAD LISTA DUPLAMENTE ENCADEADO DE INTEIROS---\n");
        printf("0-Encerrar o programa\n");
        printf("1-Criar Lista\n");
        printf("2-Verificar se a lista esta vazia\n");
        printf("3-Inserir o inteiro na lista\n");
        printf("4-Remover o inteiro da lista\n");
        printf("5-Inserir o inteiro por posicao na lista\n");
        printf("6-Remover numeros pares\n");
        printf("7-Remove o maior numero da lista\n");
        printf("8-Pegar elemento da lista por posicao\n");
        printf("9-Mostrar a lista invertida\n");
        printf("\nEscolha uma das opcoes acima: ");

        scanf("%d", &resposta);

        if(resposta==0){
            if(condicao==0){
                printf("\n->Programa encerrado\n");
                return 0;
            }

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
                list = cria_lista();
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
                int elem, pos;
                printf("\nInsira qual inteiro deseja adicionar: ");
                scanf("%d", &elem);
                printf("Insira em qual posicao deseja adicionar: ");
                scanf("%d", &pos);

                if(insere_posicao(&list, pos, elem)==1){
                    printf("\n->O numero foi adicionado com sucesso na posicao\n");
                } else{
                    printf("\n->Não foi possivel adicionar o numero nessa posicao\n");
                }
                break;

            case 6:
                if(remove_pares(&list)==1){
                    printf("\n->Numeros pares foram removidos com sucesso\n");
                } else{
                    printf("\n->Não foi possivel remover os numeros pares\n");
                }
                break;

            case 7:
                if(remove_maior(&list)==1){
                    printf("\n->O maior numero da lista foi removido com sucesso\n");
                } else{
                    printf("\n->Não foi possivel remover maior numero da lista\n");
                }
                break;

            case 8:

                int posicao, elemento;

                printf("Qual posicao da lista deseja copiar: ");
                scanf("%d", &posicao);
                
                if(get_elem_pos(list, posicao, &elemento)==1){
                    printf("\n->O elemento na posicao %d é o número %d\n", posicao, elemento);
                } else{
                    printf("\n->Não foi possivel copiar o numero nessa posicao\n");
                }

                break;

            case 9:

                lista invertida = inverte_lista(list);

                int res;

                if(lista_vazia(list)==0){
                    printf("\n->Vetor invertido:");
                } else{
                    printf("O vetor está vazio");
                    break;
                }

                for(int i=1; get_elem_pos(invertida, i, &res)==1; i++){

                    printf(" %d", res);
                }

                printf("\n");

                break;
                
            default:
                break;
            }
        }
    }
}