#define max_vet 10
#include<stdlib.h>
#include "pilha.h"

struct Pilha{
    funcionario vet[max_vet];
    int topo;
};

pilha cria_pilha(){
    pilha novo = (pilha)malloc(sizeof(struct Pilha));
    novo->topo = -1;
    return novo;
}

int pilha_vazia(pilha stack){
    if(stack->topo == -1) return 1;
    return 0;
}

int pilha_cheia(pilha stack){
    if(stack->topo == max_vet-1) return 1;

    return 0;
}

int push(pilha stack, funcionario elem){
    if(pilha_cheia(stack) || stack==NULL) return 0;

    stack->topo++;
    stack->vet[stack->topo] = elem;
    return 1;
}

int pop(pilha stack, funcionario *elem){
    if(pilha_vazia(stack) || stack==NULL) return 0;

    *elem = stack->vet[stack->topo];
    stack->topo--;
    return 1;
}

int get_topo(pilha stack, funcionario *elem){
    if(pilha_vazia(stack) || stack==NULL) return 0;

    *elem = stack->vet[stack->topo];
    return 1;
}

void apaga_pilha(pilha *stack){
    free(*stack);
    *stack = NULL;
    return;
}

int esvazia_pilha(pilha stack){
    if(stack==NULL) return 0;

    stack->topo  = -1;
    return 1;
}

void tamanho_pilha(pilha stack, int *tamanho){
    *tamanho = stack->topo+1;
    return;
}
