#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct Fila{
    char vet[max_elem][max_str];
    int cont, ini;
};

fila cria_fila(){
    fila novo = (fila)malloc(sizeof(struct Fila));
    if(novo!=NULL){
        novo->cont=0;
        novo->ini=0;
    }
    return novo;
}

int fila_vazia(fila queue){
    if(queue->cont == 0) return 1;
    else return 0;
}

int fila_cheia(fila queue){
    if(queue->cont==max_elem) return 1;
    else return 0;
}

int insere_fim(fila queue, char elem[max_str]){
    if(fila_cheia(queue)) return 0;

    strcpy(queue->vet[(queue->ini+queue->cont)%max_elem], elem);
    queue->cont++;
    
    return 1;
}

int remove_ini(fila queue, char elem[max_str]){
    if(fila_vazia(queue)) return 0;

    strcpy(elem, queue->vet[queue->ini]);
    queue->ini = (queue->ini+1)%max_elem;
    queue->cont--;

    return 1;
}

int apaga_fila(fila *queue){
    if(*queue==NULL) return 0;

    else{
        free(*queue);
        *queue = NULL;

        return 1;
    }
}

int esvazia_fila(fila queue){
    if(queue==NULL) return 0;

    else{
        queue->ini = 0;
        queue->cont = 0;

        return 1;
    }
}

int tamanho_fila(fila queue, int *tamanho){
    if(queue==NULL) return 0;

    *tamanho = queue->cont;
    return 1;
}