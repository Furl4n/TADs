#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct no {
    char info[max_str];
    struct no* prox;
};

pilha cria_pilha() {
    return NULL;
}

int pilha_vazia(pilha stack) {
    if (stack == NULL) return 1;
    return 0;
}

int push(pilha* stack, char* elem) {
    pilha novo = (pilha)malloc(sizeof(struct no));
    if (novo == NULL) return 0;

    strcpy(novo->info, elem);

    novo->prox = *stack;
    *stack = novo;

    return 1;
}

int pop(pilha* stack, char* elem) {
    if (pilha_vazia(*stack)) return 0;

    pilha no_a_remover = *stack;

    strcpy(elem, no_a_remover->info);
    
    *stack = no_a_remover->prox;

    free(no_a_remover);

    return 1;
}

int get_topo(pilha stack, char* elem) {
    if (pilha_vazia(stack)) return 0;

    strcpy(elem, stack->info);
    return 1;
}

void apaga_pilha(pilha* stack) {
    if (pilha_vazia(*stack)) return;

    pilha aux;
    while (*stack != NULL) {
        aux = *stack;
        *stack = (*stack)->prox;
        free(aux);
    }
}

void tamanho_pilha(pilha stack, int* tamanho) {
    *tamanho = 0;
    
    pilha aux = stack;
    while (aux != NULL) {
        (*tamanho)++;
        aux = aux->prox;
    }
}