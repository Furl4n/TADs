#define TAD_H

typedef struct no *lista;

lista cria_lista();
int lista_vazia(lista list);
int insere_ord(lista *list, int elem);
int remove_ord(lista *list, int elem);
int remove_ord(lista *list, int elem);
int get_elem_pos(lista list, int pos, int *elem);
void apaga_lista(lista *list);