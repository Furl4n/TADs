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