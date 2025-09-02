#include "fila.h"
#include <stdio.h>

int inserir(fila queue){

    char elem[max_str];


    printf("\nInsira o texto: ");
    getchar();
    scanf("%[^\n]", elem);
    

    if (insere_fim(queue, elem)==1){
        printf("\n->O texto foi adicionado com sucesso\n");
        return 1;
    } else{
        printf("\n->Nao foi possivel adicionar o texto\n");
        return 0;
    }
}

int remover(fila queue){

    char elem[max_str];

    if(remove_ini(queue, elem)==1){
        printf("\n->Texto: '%s' apagado com sucesso\n", elem);
        return 1;
    } else{
        printf("\n->Nao foi possível apagar primeiro texto\n");
        return 0;
    }
}

int imprimir(fila queue){
    int tamanho;

    printf("\n->Elementos em ordem da fila:\n");

    tamanho_fila(queue, &tamanho);

    for(int i=1; i<=tamanho; i++){
        char elem[max_str];

        remove_ini(queue, elem);
        printf("%d-%s\n", i, elem);
        insere_fim(queue, elem);
    }
    
}

int main(){
    fila queue = NULL;
    int tamanho;

    while (1){
        int resposta = -1;
        printf("\n---MENU FILA DE STRING---\n");
        printf("0-Encerrar o programa\n");
        printf("1-Criar fila\n");
        printf("2-Verificar se a fila esta vazia\n");
        printf("3-Verificar se a fila esta cheia\n");
        printf("4-Inserir texto no final da fila\n");
        printf("5-Remover texto do inicio da fila\n");
        printf("6-Esvaziar fila\n");
        printf("7-Apagar fila\n");
        printf("8-Verificar tamanho da fila\n");
        printf("9-Imprimir lista\n");
        printf("\nEscolha uma das opcoes acima: ");

        scanf("%d", &resposta);

        if(resposta==0){
            printf("\n->Programa encerrado\n");
            apaga_fila(&queue);
            return 0;
        }

        if(resposta != 1 && queue==NULL){
            printf("\n->A fila ainda nao foi criada\n");

        } else if(resposta==1 && queue!=NULL){
            printf("\n->So eh possivel criar uma fila!\n");

        } else{

            switch (resposta){
                case 1:
                    queue = cria_fila();
                    printf("\n->Fila criada\n");
                    break;

                case 2:
                    if(fila_vazia(queue)==1){
                        printf("\n->A fila esta vazia\n");
                    } else{
                        printf("\n->A fila nao esta vazia\n");
                    }
                    break;

                case 3:
                    if(fila_cheia(queue)==1){
                        printf("\n->A fila esta cheia\n");
                    } else{
                        printf("\n->A fila nao esta cheia\n");
                    }
                    break;
                
                case 4:
                    inserir(queue);
                    break;
                    
                case 5:
                    remover(queue);
                    break;

                case 6:
                    if (esvazia_fila(queue)==1){
                        printf("\n->Fila esvaziada com sucesso\n");
                    } else{
                        printf("\n->Nao foi possivel esvaziar a fila\n");
                    }
                    break;

                case 7:
                    apaga_fila(&queue);
                    printf("\n->Fila apagada com sucesso\n");
                    break;

                case 8:
                    tamanho_fila(queue, &tamanho);
                    printf("\n->A fila tem %d string(s)", tamanho);
                    break;

                case 9:
                    imprimir(queue);
            }
        }
    }
}