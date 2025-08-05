#include <stdlib.h>
#include "TAD_circular.h"

struct no{
    char info;
    struct no *prox;
};

lista criar_lista(){
    return NULL;
}

int lista_vazia(lista list){
    if(list==NULL) return 1;

    else return 0;
}

int insere_inicio(lista *list, char elem){
    lista novo = (lista)malloc(sizeof(struct no));
    if(novo==NULL) return 0;
    novo->info = elem;

    if(lista_vazia(*list)){
        novo->prox = novo;
        (*list)=novo;

    } else{
        novo->prox = (*list)->prox;
        (*list)->prox = novo;
    }

    return 1;
}

int insere_final(lista *list, char elem){
    lista novo = (lista)malloc(sizeof(struct no));
    if(novo==NULL) return 0;
    novo->info = elem;

    if(lista_vazia(*list)==1){
        novo->prox = novo;
    } else{

        novo->prox = (*list)->prox;
        (*list)->prox = novo;
    }
    *list = novo;
    
    return 1;
}

int remove_inicio(lista *list, char *elem){
    if(lista_vazia(*list)==1) return 0;

    else if((*list)->prox==*list){
        *elem = (*list)->info;  //usar tamanho
        free(*list);
        *list=NULL;

    } else{
        lista aux = (*list)->prox;
        *elem = aux->info;

        (*list)->prox = aux->prox;

        free(aux);
    }

    return 1;
}

int remove_final(lista *list, char *elem){
    if(lista_vazia(*list)==1) return 0;

    else if((*list)->prox = *list){
        *elem = (*list)->info;
        free(*list);
        *list==NULL;

    } else{
        lista aux = (*list)->prox;

        while(aux->prox != (*list)){
            aux = aux->prox;
        }

        aux->prox = (*list)->prox;
        *elem = (*list)->info;

        free(*list);
        *list = aux;
    }

    return 1;
}

int tamanho_lista(lista list, int *tamanho){
    if(lista_vazia(list)==1) return 0;

    *tamanho=1;
    lista aux = list;

    while (aux->prox != list){
        aux = aux->prox;
        (*tamanho)++;
    }
    
    return 1;
}

int iguais(lista list1, lista list2){
    if(lista_vazia(list1)==1 && lista_vazia(list2)==1) return 1;

    lista aux1 = list1, aux2 = list2;
    int contador, tamanho1=0, tamanho2=0;

    tamanho_lista(list1, &tamanho1);
    tamanho_lista(list2, &tamanho2);

    if(tamanho1==tamanho2){
        while (aux1->info = aux2->info || aux1->prox!=list1){
            contador++;
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }

        if(tamanho1 == contador) return 1;

        else return 0;
    }

    else return 0;

}