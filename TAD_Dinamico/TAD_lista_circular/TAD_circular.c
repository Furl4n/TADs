#include <stdlib.h>
#include "TAD_circular.h"

struct no{
    char info;
    struct no *prox;
};

/*
Entrada: Nenhuma
Pré-condição: Nenhuma
Processo: Cria a lista
Saída: Endereço ad lista
Pós-condição: Nenhuma
*/
lista criar_lista(){
    return NULL;
}

/*
Entrada: endereço de uma lista (List)
Pré-condição: Nenhuma
Processo: Confere se a lista está vazia
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: Nenhuma
*/
int lista_vazia(lista list){
    if(list==NULL) return 1;

    else return 0;
}

/*
Entrada: endereço do endereço de uma lista (List), caracter (elem)
Pré-condição: Nenhuma
Processo: Adiciona o elemento no inicio da lista
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: Lista com um elemento a mais
*/
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

/*
Entrada: endereço do endereço de uma lista (List), caracter (elem)
Pré-condição: Nenhuma
Processo: Adiciona o elemento no final da lista
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: Lista com um elemento a mais
*/
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

/*
Entrada: Endereço do endereço de uma lista (List), endereço do elemento removido (elem)
Pré-condição: A lista não estar vazia
Processo: Apaga o elemento no começo da lista
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: O caracter com o elemnto removido da lista
*/
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

/*
Entrada: Endereço do endereço de uma lista (List), endereço do elemento removido (elem)
Pré-condição: A lista não estar vazia
Processo: Apaga o elemento no final da lista
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: O caracter com o elemnto removido da lista
*/
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

/*
Entrada: Endereço da lista (List), endereco de 1 inteiro (tamanho)
Pré-condição: A lista não estar vazia
Processo: Conta quantos elementos tem na lista
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: Inteiro com o tamanho da lista
*/
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

/*
Entrada: Endereço de 2 listas (list1 e list2) 
Pré-condição: Nenhuma
Processo: Compara se as duas listas são iguais
Saída: 1 (são iguais) ou 0 (não são iguais)
Pós-condição: Nenhuma
*/
int iguais(lista list1, lista list2){
    if(lista_vazia(list1)==1 && lista_vazia(list2)==1) return 1;

    lista aux1 = list1, aux2 = list2;
    int contador, tamanho1=0, tamanho2=0;

    tamanho_lista(list1, &tamanho1);
    tamanho_lista(list2, &tamanho2);

    if(tamanho1==tamanho2){
        while (aux1->info = aux2->info || aux1->prox!=list1){
            contador++;
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }

        if(tamanho1 == contador) return 1;

        else return 0;
    }

    else return 0;

}