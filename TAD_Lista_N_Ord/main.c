#include<stdio.h>
#include<string.h>
#include"TAD_Lista_N_Ord.h"

int main(){
    char res[11];
    lista teste = cria_lista();

    printf("%d\n", lista_vazia(teste));
    printf("%d\n", lista_cheia(teste));

    char txt[11];

    strcpy(txt, "teseeee");
    
    insere_elem(teste, txt);
    get_elem_pos(teste, txt, res);
    printf("%s", res);

    return 0;
}