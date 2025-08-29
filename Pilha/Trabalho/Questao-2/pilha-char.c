#include <stdlib.h>
#include <string.h>
#include "pilha-char.h"

struct no {
    char info;
    struct no* prox;
};

pilha_char cria_pilha_char() {
    return NULL;
}

int pilha_char_vazia(pilha_char stack) {
    if (stack == NULL) return 1;
    return 0;
}

int push_char(pilha_char* stack, char elem) {
    pilha_char novo = (pilha_char)malloc(sizeof(struct no));
    if (novo == NULL) return 0;

    novo->info = elem;
    novo->prox = *stack;
    *stack = novo;

    return 1;
}

int pop_char(pilha_char* stack, char* elem) {
    if (pilha_char_vazia(*stack)) return 0;

    pilha_char aux = *stack;

    *elem = aux->info;
    
    *stack = aux->prox;

    free(aux);

    return 1;
}

int get_topo_char(pilha_char stack, char* elem) {
    if (pilha_char_vazia(stack)) return 0;

    *elem = stack->info;
    return 1;
}

void apaga_pilha_char(pilha_char* stack) {
    if (pilha_char_vazia(*stack)) return;

    pilha_char aux;
    while (*stack != NULL) {
        aux = *stack;
        *stack = (*stack)->prox;
        free(aux);
    }
}

void tamanho_pilha_char(pilha_char stack, int* tamanho) {
    *tamanho = 0;
    
    pilha_char aux = stack;
    while (aux != NULL) {
        (*tamanho)++;
        aux = aux->prox;
    }
}