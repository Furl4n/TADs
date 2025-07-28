#include<stdlib.h>
#include "TAD_Cabecalho.h"

struct no{
    int expoente;
    float coeficiente;
    lista prox;
};

lista criar_lista(){
    lista cab = (lista)malloc(sizeof(struct no));
    if(cab!=NULL) cab->prox = NULL;
    return cab;
}

int lista_vazia(lista list){
    if(list->prox==NULL) return 1;

    return 0;
}

int insere_ord(lista list, float coef, int expo){
    if(list==NULL || coef==0) return 0;

    lista novo = (lista)malloc(sizeof(struct no));
    if(novo==NULL)return 0;

    novo->coeficiente = coef;
    novo->expoente = expo;

    if (list->prox==NULL){
        list->prox = novo;
        novo->prox = NULL;
        return 1;
    }

    lista aux=list;

    while (aux->prox!=NULL && aux->prox->expoente<=novo->expoente){
        aux = aux->prox;
    }

    if(aux->expoente == novo->expoente){
        aux->coeficiente += novo->coeficiente;

        if(aux->coeficiente==0) remove_ord(list, aux->prox->expoente);
        return 1;
    } else{
        novo->prox = aux->prox;
        aux->prox = novo;
        return 1;
    }

    return 0;
}

int remove_ord(lista list, int expo){
    if(list==NULL || expo<0) return 0;

    lista aux = list;

    while (aux->prox != NULL && aux->prox->expoente != expo){
        aux = aux->prox;
    }

    if(aux->prox != NULL && aux->prox->expoente == expo){
        lista temp = aux->prox;
        aux->prox = aux->prox->prox;
        free(temp);
        return 1;
    }
    
    return 0;
}

int get_elem_pos(lista list, int pos, int *expo, float *coef){
    if(list==NULL || lista_vazia(list) || pos<=0) return 0;

    lista aux = list;

    for(int i=0; i<pos; i++){
        if(aux->prox==NULL) return 0;
        aux = aux->prox;
    }

    *expo = aux->expoente;
    *coef = aux->coeficiente;

    return 1;
}

int apaga_lista(lista *list){
    if(list==NULL) return 0;

    lista atual = *list;

    while(atual->prox!=NULL){
        lista proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *list = NULL;

    return 1;
}

int esvazia_lista(lista list){
    if(list==NULL || list->prox==NULL) return 0;

    lista atual = list->prox;

    while(atual->prox!=NULL){
        lista proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    list->prox =NULL;

    return 1;
}