#include<stdlib.h>
#include"TAD.h"

struct no{
    int info;
    lista ant, prox;
};


lista cria_lista(){
    return NULL;
}

int lista_vazia(lista list){
    if(list == NULL) return 1;

    return 0;
}

int insere_ord(lista *list, int elem){
    lista novo = (lista)malloc(sizeof(struct no));
    if(novo==NULL) return 0;
    novo->info = elem;

    if(lista_vazia(*list)){
        novo->ant = NULL;
        novo->prox = NULL;
        *list = novo;
        return 1;
    }
    
    lista aux = *list;

    if(novo->info >= aux->info ){
        novo->prox = aux;
        novo->ant = NULL;
        aux->ant = novo;
        *list = novo;

        return 1;
    }

    while(aux->prox!=NULL && novo->info < aux->prox->info){
        aux = aux->prox;
    }


    novo->ant = aux;
    novo->prox = aux->prox;
    if(aux->prox!=NULL) aux->prox->ant = novo;
    aux->prox = novo;
    
    return 1;
}

int remove_ord(lista *list, int elem){
    if(lista_vazia(*list)) return 0;

    lista aux = *list;

    while (aux->prox!=NULL && aux->info!=elem){
        aux=aux->prox;
    }

    if(aux->info!=elem) return 0;

    if(aux->ant!=NULL) aux->ant->prox = aux->prox;
    if(aux->prox!=NULL) aux->prox->ant = aux->ant;
    if(aux==*list) *list = aux->prox;

    free(aux);
    return 1;
}

int get_elem_pos(lista list, int pos, int *elem){
    if(lista_vazia(list) || pos<=0) return 0;

    lista aux = (list);
    int i = 1;
    while(aux!=NULL && i<pos){
        aux = aux->prox;
        i++;
    }

    if(aux==NULL) return 0;

    *elem = aux->info;
    return 1;
}

void apaga_lista(lista *list){
    if(lista_vazia(*list)) return;

    while (*list!=NULL){
        lista aux = (*list)->prox;
        free(*list);
        *list = aux;
    }
    *list=NULL;
    return;
}