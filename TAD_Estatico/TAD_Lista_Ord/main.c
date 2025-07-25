#include<stdio.h>
#include<string.h>
#include "TAD_Lista_Ord.h"

int inserir(lista list){

    bebida elem;
    char nome[max_str];


    printf("\n---INSERIR BEBIDA---\n");
    printf("Insira o nome da bebida: ");
    getchar();
    scanf("%[^\n]", nome);
    strcpy(elem.nome, nome);
    printf("Insira o volume da bebida: ");
    scanf("%d", &elem.volume);
    printf("Insira o valor da bebida: ");
    scanf("%f", &elem.preco);
    

    if (insere_ord(list, elem)==1){
        printf("\n->Bebida adicionada com sucesso\n");
        return 1;
    } else{
        printf("\n->Nao foi possível adicionar a bebida\n");
        return 0;
    }
}

int remover(lista list){

    char nome[max_str];

    printf("Qual bebida deseja apagar? ");
    getchar();
    scanf("%[^\n]", nome);

    if(remove_ord(list, nome)==1){
        printf("\n->Bebida apagada com sucesso\n");
        return 1;
    } else{
        printf("\n->Nao foi possível apagar a bebida\n");
        return 0;
    }
}

int get_pos(lista list){

    bebida elem;
    int pos;

    printf("Digite a posicao que deseja copiar: ");
    scanf("%d", &pos);

    if(get_elem_pos(list, pos, &elem)==1){
        printf("Bebida na posicao:\n");
        printf("\n->Nome: %s\n->Volume: %d mL\n->Preco: %.2f\n", elem.nome, elem.volume, elem.preco);
        return 1;
    } else{
        printf("\n->Nao foi possivel copiar a bebida nessa posicao\n");
        return 0;
    }
}

int main(){
    lista list = NULL;

    while (1){
        int resposta = -1;
        printf("\n---MENU TAD LISTA ORDENADA DE BEBIDAS---\n");
        printf("0-Encerrar o programa\n");
        printf("1-Criar lista\n");
        printf("2-Verificar se a lista esta vazia\n");
        printf("3-Verificar se a lista esta cheia\n");
        printf("4-Inserir bebida na lista\n");
        printf("5-Remover bebida da lista\n");
        printf("6-Pegar bebida da lista por posicao\n");
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