#include<stdio.h>
#include"TAD_Lista_N_Ord.h"

int main(){
    char res[11];
    lista teste = cria_lista();

    printf("%d\n", lista_vazia(teste));
    printf("%d\n", lista_cheia(teste));
    
    insere_elem(teste, "teste10000");
    get_elem_pos(teste, "teste1", &res);
    printf("%s", res);

    return 0;
}