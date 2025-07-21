#include<stdio.h>
#include"TAD_Lista_N_Ord.h"

int main(){
    lista teste = cria_lista();

    printf("%d\n", lista_vazia(teste));
    printf("%d\n", lista_cheia(teste));
    
}