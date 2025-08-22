#include<stdio.h>
#include"Esfera.h"

int main(){
    esfera esfera1 = cria_esfera();
    ponto_R3 ponto1=criar_pto(), ponto2=criar_pto();
    int x, y, z;

    printf("Insira as coordenadas do primeiro ponto da esfera: ");
    scanf("%d %d %d", &x, &y, &z);
    set_pto(ponto1, x, y, z);

    printf("Insira as coordenadas do segundo ponto da esfera: ");
    scanf("%d %d %d", &x, &y, &z);
    set_pto(ponto2, x, y, z);

    set_esfera(esfera1, ponto1, ponto2);

    double raio1 = raio(esfera1);
    double area1 = area(esfera1);
    double volume1 = volume(esfera1);

    printf("o raio da esfera eh: %.2f\n", raio1);
    printf("A area da esfera eh: %.2f\n", area1);
    printf("O volume da esfera eh: %.2f\n", volume1);

    apaga_esfera(&esfera1);
    apaga_pto(&ponto1);
    apaga_pto(&ponto2);
}