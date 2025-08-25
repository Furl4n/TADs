#define PILHA_H

typedef struct Pilha * pilha;

pilha cria_pilha();
int pilha_vazia(pilha stack);
int pilha_cheia(pilha stack);
int push(pilha stack, int elem);
int pop(pilha stack, int *elem);
int get_topo(pilha stack, int *elem);
void apaga_pilha(pilha *stack);
int esvazia_pilha(pilha stack);
void tamanho_pilha(pilha stack, int *tamanho);