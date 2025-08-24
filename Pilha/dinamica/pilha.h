#ifndef PILHA_H
#define PILHA_H

#define max_str 21

typedef struct no* pilha;

pilha cria_pilha();
int pilha_vazia(pilha stack);
int push(pilha* stack, char* elem);
int pop(pilha* stack, char* elem);
int get_topo(pilha stack, char* elem);
void apaga_pilha(pilha* stack);
void tamanho_pilha(pilha stack, int* tamanho);

#endif