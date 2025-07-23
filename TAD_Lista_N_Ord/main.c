#include<stdio.h>
#include<string.h>
#include"TAD_Lista_N_Ord.h"

int inserir(lista list){

    char elem[max_str];


    printf("\nInsira o texto: ");
    getchar();
    scanf("%[^\n]", elem);
    

    if (insere_elem(list, elem)==1){
        printf("\n->O texto foi adicionado com sucesso\n");
        return 1;
    } else{
        printf("\n->Nao foi possível adicionar o texto\n");
        return 0;
    }
}

int remover(lista list){

    char elem[max_str];

    printf("Qual texto deseja apagar? ");
    getchar();
    scanf("%[^\n]", elem);

    if(remove_elem(list, elem)==1){
        printf("\n->Texto apagada com sucesso\n");
        return 1;
    } else{
        printf("\n->Nao foi possível apagar o texto\n");
        return 0;
    }
}

int get_pos(lista list){

    char elem[max_str];
    int pos;

    printf("Digite a posicao que deseja copiar: ");
    scanf("%d", &pos);

    if(get_elem_pos(list, pos, elem)==1){
        printf("\n->Texto : %s\n", elem);
        return 1;
    } else{
        printf("\n->Nao foi possivel copiar o texto nessa posicao\n");
        return 0;
    }
}

int main(){
    lista list = NULL;

    while (1){
        int resposta = -1;
        printf("\n---MENU TAD LISTA NAO ORDENADA DE TEXTO---\n");
        printf("0-Encerrar o programa\n");
        printf("1-Criar lista\n");
        printf("2-Verificar se a lista esta vazia\n");
        printf("3-Verificar se a lista esta cheia\n");
        printf("4-Inserir texto na lista\n");
        printf("5-Remover texto da lista\n");
        printf("6-Pegar texto por posicao\n");
        printf("7-Esvaziar lista\n");
        printf("8-Apagar lista\n");
        printf("\nEscolha uma das opcoes acima: ");

        scanf("%d", &resposta);

        if(resposta==0){
            printf("\n->Programa encerrado\n");
            return 0;
        }

        if(resposta != 1 && list==NULL){
            printf("\n->A lista ainda nao foi criada\n");

        } else if(resposta==1 && list!=NULL){
            printf("\n->So eh possivel criar uma lista!\n");

        } else{

            switch (resposta){
        case 1:
            list = cria_lista();
            printf("\n->Lista criada\n");
            break;

        case 2:
            if(lista_vazia(list)==1){
                printf("\n->A lista esta vazia\n");
            } else{
                printf("\n->A lista nao esta vazia\n");
            }
            break;

        case 3:
            if(lista_cheia(list)==1){
                printf("\n->A lista esta cheia\n");
            } else{
                printf("\n->A lista não esta cheia\n");
            }
            break;
        
        case 4:
            inserir(list);
            break;
            
        case 5:
            remover(list);
            break;

        case 6:
            get_pos(list);
            break;

        case 7:
            if (esvazia_lista(list)==1){
                printf("\n->Lista apagada com sucesso\n");
            } else{
                printf("\n->Nao foi possivel apagar a lista\n");
            }
            break;

        case 8:
            apaga_lista(&list);
            printf("\n->Lista apagada com sucesso\n");
            break;
        }
        }

        
    }
    
}