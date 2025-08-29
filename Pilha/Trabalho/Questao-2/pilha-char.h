#define pilha_char_H

typedef struct no* pilha_char;

pilha_char cria_pilha_char();
int pilha_vazia_char(pilha_char stack);
int push_char(pilha_char *stack, char elem);
int pop_char(pilha_char *stack, char *elem);
int get_topo_char(pilha_char stack, char *elem);
void apaga_pilha_char(pilha_char *stack);
void tamanho_pilha_char(pilha_char stack, int *tamanho);