#define TAD_H

typedef struct no *lista;

lista cria_lista();
int lista_vazia(lista list);
int insere_ord(lista *list, char elem);
int remove_ord(lista *list, char elem);
int get_elem_pos(lista list, int pos, char *elem);
void apaga_lista(lista *list);