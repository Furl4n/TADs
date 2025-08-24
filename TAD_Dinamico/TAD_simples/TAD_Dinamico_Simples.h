#define TAD_DINAMICO_SIMPLES_H

typedef struct no *lista;

lista criar_lista();
int lista_vazia(lista list);
int insere_elem(lista *list, char elem);
int remove_elem(lista *list, char elem);
char get_elem_pos(lista list, int pos);
void apaga_lista(lista *list);