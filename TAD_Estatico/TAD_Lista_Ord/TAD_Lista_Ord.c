#include<stdlib.h>
#include<string.h>
#include "TAD_Lista_Ord.h"

struct TAD_Lista_Ord{
    bebida pos[max_vet];
    int fim;
};

lista cria_lista(){
    lista list = (lista)malloc(sizeof(struct TAD_Lista_Ord));
    if (list!=NULL) list->fim=0;
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

int insere_ord(lista list, bebida elem){
    if(list==NULL || lista_cheia(list)) return 0;

    if(lista_vazia(list)==1 || strcmp(elem.nome, list->pos[list->fim-1].nome)==1) 
    list->pos[list->fim]= elem;

    else if (strcmp(elem.nome, list->pos[list->fim-1].nome) == 0) {
        if (elem.volume >= list->pos[list->fim-1].volume) {
            list->pos[list->fim] = elem;
        } else {
            int i = list->fim - 1;
            while (i >= 0 && strcmp(elem.nome, list->pos[i].nome) == 0 && elem.volume < list->pos[i].volume) {
                list->pos[i+1] = list->pos[i];
                i--;
            }
            list->pos[i+1] = elem;
        }
    } 
    else{
        int i = list->fim - 1;
        while (i >= 0 && (strcmp(elem.nome, list->pos[i].nome) < 0 || (strcmp(elem.nome, list->pos[i].nome) == 0 && elem.volume < list->pos[i].volume))) {

        list->pos[i+1] = list->pos[i];
        i--;
        }

        list->pos[i+1] = elem;
    }
    
    list->fim++;
    return 1;
}

int remove_ord(lista list, char nome[max_str]){
    if(list==NULL || lista_vazia(list) || strcmp(list->pos[0].nome, nome)==1 || strcmp(nome, list->pos[list->fim-1].nome)==1)
    return 0;

    else{
        int aux=0;

        while(strcmp(list->pos[aux].nome, nome)!=0 && aux<list->fim) aux++;

        if(aux==list->fim){
            return 0;
        }

        for(int i=aux; i<list->fim-1; i++){
            list->pos[i]=list->pos[i+1];
        }
    }
    
    list->fim--;
    return 1;    
}

int get_elem_pos(lista list, int posicao, bebida *elem){
    if(list==NULL || lista_vazia(list) || list->fim < posicao || posicao<0) return 0;

    else{
        *elem = list->pos[posicao-1];
        return 1;
    }
}

int esvazia_lista(lista list){
    if(list==NULL) return 0;
    list->fim=0;
    return 1;
}

void apaga_lista(lista *list){
    free(*list);
    *list=NULL;
}