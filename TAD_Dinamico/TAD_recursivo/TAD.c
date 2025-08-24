#include<stdlib.h>
#include "TAD.h"

struct no{
    char info;
    lista prox;
};

lista cria_lista(){
    return NULL;
}

int lista_vazia(lista list){
    if(list==NULL) return 1;
    else return 0;
}

int insere_ord(lista *list, char elem){
    if(lista_vazia(*list) || elem<(*list)->info){
        lista novo = (lista)malloc(sizeof(struct no));
        if(novo==NULL) return 0;

        novo->info = elem;
        novo->prox = *list;
        *list = novo;
        return 1;
    }
    else{
        int R = insere_ord(&((*list)->prox), elem);
        return R;
    }
}

int remove_ord(lista *list, char elem){
    if(lista_vazia(*list) || elem<(*list)->info) return 0;
    
    else{
        if(elem == (*list)->info){
            lista aux = *list;
            *list = aux->prox;
            free(aux);
            return 1;
        }
        
        int R = remove_ord(&((*list)->prox), elem);
        return R;
    }
}

int get_elem_pos(lista list, int pos, char *elem){
    if(lista_vazia(list)) return 0;

    if(pos == 1){
        *elem = list->info;
        return 1;
    }

    int R = get_elem_pos(list->prox, pos-1, elem);
    return R;
}

void apaga_lista(lista *list){
    if(lista_vazia(*list)) return;

    lista aux = *list;
    *list = aux->prox;
    free(aux);

    if(lista_vazia(*list)==0){
        apaga_lista(list);
    }
}