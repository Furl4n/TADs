#include<stdio.h>
#include"num_complexo.h"

int main(){
    complexo c1=cria(), c2=cria();
    float real, imag;

    printf("Informe a parte real e imaginaria do primeiro numero complexo C1 (apenas numeros):");
    scanf("%f %f", &real, &imag);
    set_nro(c1, real, imag);

    printf("Informe a parte real e imaginaria do segundo numero complexo C2 (apenas numeros):");
    scanf("%f %f", &real, &imag);
    set_nro(c2, real, imag);

    complexo c3=cria();

    c3=soma(c1, c2);
    get_nro(c3, &real, &imag);
    if (imag<0){
        printf("O resultado da operacao C1+C2 eh: %.2f%.2fi\n", real, imag);
    } else{
        printf("O resultado da operacao C1+C2 eh: %.2f%+.2fi\n", real, imag);
    }

    c3=sub(c1, c2);
    get_nro(c3, &real, &imag);
    if (imag<0){
        printf("O resultado da operacao C1-C2 eh: %.2f%.2fi\n", real, imag);
    } else{
        printf("O resultado da operacao C1-C2 eh: %.2f+%.2fi\n", real, imag);
    }
    
    
    
    c3=multi(c1, c2);
    get_nro(c3, &real, &imag);
    if (imag<0){
        printf("O resultado da operacao C1*C2 eh: %.2f%.2fi\n", real, imag);
    } else{
        printf("O resultado da operacao C1*C2 eh: %.2f+%.2fi\n", real, imag);
    }
    
    apaga(&c1);
    apaga(&c2);
    apaga(&c3);
    return 0;
}
    