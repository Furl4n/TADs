#define PILHA_H
#define max_str 31

typedef struct funcionarios{
    long int matricula;
    char nome[max_str], setor;
    float salario;
} funcionario;

typedef struct Pilha * pilha;

pilha cria_pilha();
int pilha_vazia(pilha stack);
int pilha_cheia(pilha stack);
int push(pilha stack, funcionario elem);
int pop(pilha stack, funcionario *elem);
int get_topo(pilha stack, funcionario *elem);
void apaga_pilha(pilha *stack);
int esvazia_pilha(pilha stack);
void tamanho_pilha(pilha stack, int *tamanho);