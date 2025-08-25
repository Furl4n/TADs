#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

int main(){
    pilha stack = cria_pilha();

    while (1){
        int numero;
        char base;

        printf("\n\n--MENU CONVERSOR DE INTEIRO DECIMAL PARA OUTRA BASE--\n\n");
        printf("B-Binario\n");
        printf("O-Octal\n");
        printf("H-Hexadecimal\n");
        printf("Escolha para qual base deseja converter: ");
        scanf(" %c", &base);

        printf("Digite o numero a ser convertido: ");
        scanf("%d", &numero); //valor negativo para encerrar programa

        if(numero<0){
            apaga_pilha(&stack);
            printf(("\n->programa encerrado\n"));
            return 0;
        }

        if(base=='B' || base == 'b'){
            while(numero!=0){
                if(numero==1){
                    push(stack, numero);
                    numero--;
                }
                else{
                    int resto = numero%2;
                    push(stack, resto);

                    numero = numero/2;
                }
            }

            int tamanho=0;
            tamanho_pilha(stack, &tamanho);
            printf("\n->Numero convertido: ");

            for(int i=0; i<tamanho; i++){
                int bit;
                pop(stack, &bit);
                printf("%d", bit);
            }
        }
        else if(base=='O' || base == 'o'){
            while(numero!=0){
                if(numero<8){
                    push(stack, numero);
                    numero=0;
                } 
                else{
                    int resto = numero%8;
                    push(stack, resto);

                    numero = numero/8;
                }
            }

            int tamanho=0;
            tamanho_pilha(stack, &tamanho);

            printf("\n->Numero convertido: ");

            for(int i=0; i<tamanho; i++){
                int bit;
                pop(stack, &bit);
                printf("%d", bit);
            }
        }
        else if(base=='H' || base == 'h'){
            while(numero!=0){
                if(numero<16){
                    push(stack, numero);
                    numero=0;
                } 
                else{
                    int resto = numero%16;
                    push(stack, resto);

                    numero = numero/16;
                }
            }

            int tamanho=0;
            tamanho_pilha(stack, &tamanho);

            printf("\n->Numero convertido: ");

            for(int i=0; i<tamanho; i++){
                int bit;
                pop(stack, &bit);
                printf("%d", bit);
            }
        } else{
            printf(("\n->Base nao permitida"));
        }
    }
    
}