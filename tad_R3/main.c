#include<stdio.h>
#include"pontoR3.h"


int main(){
    ponto_R3 ponto1=criar_pto(), ponto2=criar_pto();
    int x, y, z;

    printf("Informe as coordenadas do primeiro ponto:");
    scanf("%d %d %d", &x, &y, &z);
    set_pto(ponto1, x, y, z);
    

    printf("Informe as coordenadas do primeiro ponto:");
    scanf("%d %d %d", &x, &y, &z);
    set_pto(ponto2, x, y, z);

    float distancia=dist(ponto1, ponto2);

    printf("A distancia entre os dois pontos eh de: %.2f", distancia);

    apaga_pto(&ponto1);
    apaga_pto(&ponto2);

    return 0;
}