#define Esfera_h
#include"pontoR3.h"

typedef struct Esfera* esfera;

esfera cria_esfera();
int set_esfera(esfera p, ponto_R3 p1, ponto_R3 p2);
int get_esfera(esfera p, ponto_R3 p1, ponto_R3 p2);
void apaga_esfera(esfera *p);
double raio(esfera p);
double area(esfera p);
double volume(esfera p);