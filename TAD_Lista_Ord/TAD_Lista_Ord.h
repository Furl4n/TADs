#define TAD_LISTA_ORD_H
#define max_vet 2
#define max_str 21

typedef struct bebida* bebida;
typedef struct TAD_Lista_Ord* lista;

lista cria_lista();
int lista_vazia(lista list);
int lista_cheia(lista list);
int insere_ord(lista list, char nome[max_str], int volume, float preco);
int remove_ord(lista list, char nome[max_str]);