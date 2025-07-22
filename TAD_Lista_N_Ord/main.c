#include<stdio.h>
#include<string.h>
#include"TAD_Lista_N_Ord.h"

int main(){
    char res[11];
    lista teste = cria_lista();

    printf("%d\n", lista_vazia(teste));
    printf("%d\n", lista_cheia(teste));

    char txt[11];
    int res2;

    strcpy(txt, "teseeee");
    
    insere_elem(teste, txt);
    get_elem_pos(teste, 1, res);
    printf("%s\n", res);
    printf("%d\n", remove_elem(teste, txt));
    res2 = get_elem_pos(teste, 1, res);
    printf("%s\n", res);
    printf("%d\n", res2);
    printf("%d\n", lista_vazia(teste));

    return 0;
}