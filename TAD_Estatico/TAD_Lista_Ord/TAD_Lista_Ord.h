#define TAD_LISTA_ORD_H
#define max_vet 15
#define max_str 21

typedef struct bebida{
    char nome[max_str];
    int volume;
    float preco;      
}bebida;

typedef struct TAD_Lista_Ord* lista;

lista cria_lista();
int lista_vazia(lista list);
int lista_cheia(lista list);
int insere_ord(lista list, bebida elem);
int remove_ord(lista list, char nome[max_str]);
int get_elem_pos(lista list, int posicao, bebida *elem);
int esvazia_lista(lista list);
void apaga_lista(lista *list);