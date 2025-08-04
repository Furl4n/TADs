#define TAD_CIRCULAR_H

typedef struct no *lista;

lista criar_lista();
int lista_vazia(lista list);
int insere_inicio(lista *list, char elem);
int insere_final(lista *list, char elem);
int remove_inicio(lista *list, char *elem);
int remove_final(lista *list, char *elem);
int tamanho_lista(lista list, int *tamanho);