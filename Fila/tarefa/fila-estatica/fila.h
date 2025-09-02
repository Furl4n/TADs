#define FILA_H
#define max_str 31
#define max_elem 10


typedef struct Fila*fila;

fila cria_fila();
int fila_vazia(fila queue);
int fila_cheia(fila queue);
int insere_fim(fila queue, char elem[max_str]);
int remove_ini(fila queue, char elem[max_str]);
int apaga_fila(fila *queue);
int esvazia_fila(fila queue);
int tamanho_fila(fila queue, int *tamanho);