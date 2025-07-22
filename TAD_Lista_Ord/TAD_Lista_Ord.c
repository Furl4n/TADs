#include<stdlib.h>
#include<string.h>
#include "TAD_Lista_Ord.h"
#define max_vet 15
#define max_str 21

struct bebida{
    char nome[max_str];
    int volume;
    float preco;      
};

struct TAD_Lista_Ord{
    struct bebida pos[max_str];
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

int insere_ord(lista list, bebida elem){  //adicionar diferenciação por volume caso ==
    if(list==NULL || elem==NULL || lista_cheia(list)) return 0;

    if(lista_vazia(list)==1 || strcmp(elem->nome, list->pos[list->fim-1].nome)==0){
    
        list->pos[list->fim]= *elem;
    }

    int aux=0; 

    while (strcmp(list->pos[aux].nome, elem->nome)==-1){
        //adicionar codigo para mover código
    }
    
}