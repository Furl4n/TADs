#define FILA_H
#define max_str 11

typedef struct Produto{
    int codigo;
    char desc[max_str];
    float preco;
} produtos;

typedef struct Fila*fila;

fila cria_fila();
int fila_vazia(fila queue);
int insere_fim(fila queue, produtos elem);
int remove_ini(fila queue, produtos *elem);
void apaga_fila(fila *queue);
int esvazia_fila(fila queue);
int tamanho_fila(fila queue, int *tamanho);