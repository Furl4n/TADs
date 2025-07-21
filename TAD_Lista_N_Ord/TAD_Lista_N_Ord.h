#define TAD_Lista_N_Ord.h
#define max_str 11
#define max_vet 20

typedef struct TAD_lista* lista;

lista cria_lista();
int lista_vazia(lista list);
int lista_cheia(lista list);
int insere_elem(lista list, char elem[max_str]);
int remove_elem(lista list, char elem[max_str]);
char* get_elem_pos(lista list, char elem[max_str], char res[max_str]);
int esvazia_lista(lista list);
int apaga_lista(lista *list);