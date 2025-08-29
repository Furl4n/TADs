#define PILHA_FLOAT_H

typedef struct no* pilha_float;

pilha_float cria_pilha();
int pilha_vazia_float(pilha_float stack);
int push_float(pilha_float *stack, float elem);
int pop_float(pilha_float *stack, float *elem);
int get_topo_float(pilha_float stack, float *elem);
void apaga_pilha_float(pilha_float *stack);
void tamanho_pilha_float(pilha_float stack, int *tamanho);