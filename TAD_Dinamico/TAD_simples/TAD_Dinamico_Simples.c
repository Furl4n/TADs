#include "TAD_Dinamico_Simples.h"
#include <stdlib.h>

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

int insere_elem(lista *list, char elem){
    if(list==NULL) return 0;

    lista temp = (lista)malloc(sizeof(struct no));

    temp->info = elem;
    temp->prox = *list;
    *list = temp;

    return 1;
}

int remove_elem(lista *list, char elem){
    if(list==NULL) return 0;

    lista aux = *list; 

    if (aux->info==elem){
        *list = aux->prox;
        free(aux);
        return 1;
    }
    

    while (aux->prox!=NULL && aux->prox->info!=elem){
        aux = aux->prox;
    }

    if(aux->prox->info==elem){
        lista aux2 = aux->prox;
        aux->prox = aux2->prox;
        free(aux2);
        return 1;
    }

    return 0;
    
}

char get_elem_pos(lista list, int pos){
    if(list==NULL) return '\0';

    int aux = 1;

    while (aux<pos && list->prox!=NULL){
        list = list->prox;
        aux++;
    }

    if(aux==pos){
        return list->info;
    }
    
    return '\0';
}

void apaga_lista(lista *list){

    lista aux=*list;

    while (aux->prox!=NULL){
        lista aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }

    *list = NULL;
}

