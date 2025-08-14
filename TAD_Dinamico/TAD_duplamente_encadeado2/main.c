#include "TAD.h"
#include <stdio.h>

int main(){
    lista list = cria_lista();

    insere_ord(&list, 3);
    insere_ord(&list, 5);

    int elem1=0, elem2=0;

    get_elem_pos(&list, 1, &elem1);
    get_elem_pos(&list, 0, &elem2);


    printf("%d %d", elem1, elem2);

    return 0;
}