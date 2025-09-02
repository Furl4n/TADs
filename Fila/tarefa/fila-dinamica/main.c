#include "fila.h"
#include <stdio.h>

int inserir(fila queue){

    struct Produto elem;

    printf("\nINSERIR PRODUTO:\n");
    printf("Digite o codigo do produto: ");
    scanf("%d", &elem.codigo);
    printf("Digite o preco do produto: ");
    scanf("%f", &elem.preco);
    printf("ditite a descricao do produto(max 10 caracteres): ");
    getchar();
    scanf("%[^\n]", elem.desc);
    

    if (insere_fim(queue, elem)==1){
        printf("\n->O produto foi adicionado com sucesso\n");
        return 1;
    } else{
        printf("\n->Nao foi possivel adicionar o produto\n");
        return 0;
    }
}

int remover(fila queue){

    produtos elem;

    if(remove_ini(queue, &elem)==1){
        printf("\n->Produto apagado:\n");
        printf("Codigo: %d\n", &elem.codigo);
        printf("Preco: %.2f\n", &elem.preco);
        printf("Descricao: %s\n", elem.desc);

        return 1;
    } else{
        printf("\n->Nao foi possível apagar primeiro o produto\n");
        return 0;
    }
}

int imprimir(fila queue){
    int tamanho;

    if(fila_vazia(queue)){
        printf("\n->A fila esta vazia\n");
        return 0;
    } 
    
    printf("\n->Elementos em ordem da fila:\n");
    
    tamanho_fila(queue, &tamanho);
    
    for(int i=1; i<=tamanho; i++){
        produtos elem;

        remove_ini(queue, &elem);

        printf("\n->Produto N%d:\n", i);
        printf("Codigo: %d\n", elem.codigo);
        printf("Preco: %.2f\n", elem.preco);
        printf("Descricao: %s\n", elem.desc);

        insere_fim(queue, elem);
    }
    
}

int main(){
    fila queue = NULL;
    int tamanho;

    while (1){
        int resposta = -1;
        printf("\n---MENU FILA DE PRODUTOS---\n");
        printf("0-Encerrar o programa\n");
        printf("1-Criar fila\n");
        printf("2-Verificar se a fila esta vazia\n");
        printf("3-Inserir produto no final da fila\n");
        printf("4-Remover produto do inicio da fila\n");
        printf("5-Esvaziar fila\n");
        printf("6-Apagar fila\n");
        printf("7-Verificar tamanho da fila\n");
        printf("8-Imprimir lista\n");
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
                    inserir(queue);
                    break;
                    
                case 4:
                    remover(queue);
                    break;

                case 5:
                    if (esvazia_fila(queue)==1){
                        printf("\n->Fila esvaziada com sucesso\n");
                    } else{
                        printf("\n->Nao foi possivel esvaziar a fila\n");
                    }
                    break;

                case 6:
                    apaga_fila(&queue);
                    printf("\n->Fila apagada com sucesso\n");
                    break;

                case 7:
                    if(tamanho_fila(queue, &tamanho)){
                        printf("\n->A fila tem %d produto(s)\n", tamanho);
                    } else{
                        printf("\n->Nao foi possivel verificar o tamanho da lista\n");
                    }
                    break;

                case 8:
                    imprimir(queue);
                    break;
            }
        }
    }
}