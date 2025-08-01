#include <string.h>
#include<stdlib.h>
#include "TAD_Lista_N_Ord.h"


struct TAD_lista{
    char pos[max_vet][max_str];
    int fim;
};

lista cria_lista(){
    lista list;
    list = (lista)malloc(sizeof(struct TAD_lista));
    if(list!=NULL){
        list->fim = 0;
    }
    return list;
}

int lista_vazia(lista list){
    if(list->fim==0) return 1;

    return 0;
}

int lista_cheia(lista list){
    if(list->fim==max_vet) return 1;
    
    return 0;
}

int insere_elem(lista list, char elem[max_str]){
    if(list==NULL || lista_cheia(list)==1) return 0;

    strcpy(list->pos[list->fim], elem);
    list->fim++;
    return 1;
}

int remove_elem(lista list, char elem[max_str]){
    if(list==NULL || lista_vazia(list)==1) return 0;

    int aux=0;

    while(aux<list->fim && strcmp(list->pos[aux], elem)!=0) aux++;

    if(aux==list->fim) return 0;

    for(int i=aux; i<list->fim-1; i++){
        strcpy(list->pos[i], list->pos[i+1]);
    }

    list->fim--;
    return 1;
}

int get_elem_pos(lista list, int posicao, char res[max_str]){
    if(list==NULL || lista_vazia(list)==1 || posicao-1< 0 || posicao-1>=list->fim){
        res[0]='\0';
        return 0;
    } 

    strcpy(res, list->pos[posicao-1]);

    return 1;
    }

int esvazia_lista(lista list){
    if(list==NULL) return 0;

    list->fim = 0;

    return 1;
}

void apaga_lista(lista *list){
    free(*list);
    *list = NULL;
}