#define TAD_DUPLAMENTE_H

typedef struct no * lista;

lista cria_lista();
int lista_vazia(lista list);
int insere_elem(lista *list, int elem);
int remove_elem(lista *list, int elem);
int insere_posicao(lista *list, int pos, int elem);
int remove_pares(lista *list);
int remove_maior(lista *list);
lista inverte_lista(lista list);
int get_elem_pos(lista list, int pos, int *elem);
