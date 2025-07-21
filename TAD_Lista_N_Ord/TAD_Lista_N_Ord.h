#define TAD_Lista_N_Ord.h
#define max_str 11

typedef struct TAD_lista* lista;

lista cria_lista();
int lista_vazia(lista list);
int lista_cheia(lista list);
int insere_elem(lista list, char elem[max_str]);
int remove_elem(lista list, char elem[max_str]);
