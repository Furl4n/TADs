#include<stdio.h>
#include<string.h>
#include "TAD_Lista_Ord.h"

int main(){ //alterar max_vet
    lista teste = cria_lista(teste);

    printf("%d\n", lista_vazia(teste));
    printf("%d\n", lista_cheia(teste));

    char amstel[max_str], brahama[max_str];

    strcpy(amstel, "Amstel");
    strcpy(brahama, "Brahama");

    insere_ord(teste, amstel, 379, 3.49);
    insere_ord(teste, brahama, 600, 10);

    printf("%d\n", lista_vazia(teste));
    printf("%d\n", lista_cheia(teste));

    remove_ord(teste, amstel);

    printf("%d\n", lista_vazia(teste));
    printf("%d\n", lista_cheia(teste));


    return 0;

}