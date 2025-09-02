#include <stdlib.h>
#include "fila.h"

struct no{
    produtos info;
    struct no* prox;
};

struct Fila{
    struct no *ini, *fim;
};


fila cria_fila(){
    fila novo = (fila)malloc(sizeof(struct Fila));

    if(novo!=NULL){
        novo->ini = NULL;
        novo->fim = NULL;
    }
    return novo;
}

int fila_vazia(fila queue){
    if(queue->ini==NULL) return 1;
    else return 0;
}

int insere_fim(fila queue, produtos elem){
    if(queue==NULL) return 0;

    struct no *novo = (struct no*)malloc(sizeof(struct no));
    if(novo==NULL) return 0;

    novo->info = elem;
    novo->prox = NULL;

    if(fila_vazia(queue)){
        queue->ini = novo;
    } else{
        queue->fim->prox = novo;
    }
    queue->fim = novo;

    return 1;
}

int remove_ini(fila queue, produtos *elem){
    if(queue==NULL || fila_vazia(queue)) return 0;

    *elem = queue->ini->info;

    struct no *aux = queue->ini;
    queue->ini = queue->ini->prox;
    if(queue->ini == NULL) queue->fim = NULL;

    free(aux);
    return 1;
}

void apaga_fila(fila *queue){

    while ((*queue)->ini != NULL){
        struct no *aux = (*queue)->ini;
        (*queue)->ini = (*queue)->ini->prox;
        free(aux);
    }
    
    free(*queue);
    *queue = NULL;
    return;
}

int esvazia_fila(fila queue){
    if(queue==NULL) return 0;

    while (queue->ini != NULL){
        struct no *aux = queue->ini;
        queue->ini = queue->ini->prox;
        free(aux);
    }

    queue->fim = NULL;

    return 1;
}

int tamanho_fila(fila queue, int *tamanho){
    if(queue==NULL) return 0;

    struct no *aux = queue->ini;
    *tamanho = 0;

    while(aux != NULL){
        aux = aux->prox;
        (*tamanho)++;
    }

    return 1;
}