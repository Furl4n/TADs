#define TAD_CABECALHO_H

typedef struct no *lista;

lista criar_lista();
int lista_vazia(lista list);
int insere_ord(lista list, float coef, int expo);
int remove_ord(lista list, int expo);
int get_elem_pos(lista list, int pos, int *expo, float *coef);
int apaga_lista(lista *list);
int esvazia_lista(lista list);