#include <stdlib.h>
#include <string.h>
#include "pilha-float.h"

struct no {
    float info;
    struct no* prox;
};

pilha_float cria_pilha() {
    return NULL;
}

int pilha_vazia_float(pilha_float stack) {
    if (stack == NULL) return 1;
    return 0;
}

int push_float(pilha_float* stack, float elem) {
    pilha_float novo = (pilha_float)malloc(sizeof(struct no));
    if (novo == NULL) return 0;

    novo->info = elem;
    novo->prox = *stack;
    *stack = novo;

    return 1;
}

int pop_float(pilha_float* stack, float* elem) {
    if (pilha_vazia_float(*stack)) return 0;

    pilha_float aux = *stack;
    *elem = aux->info;
    *stack = aux->prox;

    free(aux);
    return 1;
}

int get_topo_float(pilha_float stack, float* elem) {
    if (pilha_vazia_float(stack)) return 0;

    *elem = stack->info;
    return 1;
}

void apaga_pilha_float(pilha_float* stack) {
    if (pilha_vazia_float(*stack)) return;

    pilha_float aux;
    while (*stack != NULL) {
        aux = *stack;
        *stack = (*stack)->prox;
        free(aux);
    }
}

void tamanho_pilha_float(pilha_float stack, int* tamanho) {
    *tamanho = 0;
    
    pilha_float aux = stack;
    while (aux != NULL) {
        (*tamanho)++;
        aux = aux->prox;
    }
}