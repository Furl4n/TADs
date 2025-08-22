#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Esfera.h"

struct Esfera{
    ponto_R3 centro;
    ponto_R3 extremidade;
};

esfera cria_esfera(){
    esfera p = (esfera)malloc(sizeof(esfera));

    p-> centro = criar_pto();
    p->extremidade = criar_pto();
    return p;
}

int set_esfera(esfera p, ponto_R3 p1, ponto_R3 p2){
    if(p==NULL || p1==NULL || p2==NULL){
        return 0;
    }

    int x, y, z;
    get_pto(p1, &x, &y, &z);
    set_pto(p-> centro, x, y, z);

    get_pto(p2, &x, &y, &z);
    set_pto(p->extremidade, x, y, z);

    return 1;
}

int get_esfera(esfera p, ponto_R3 p1, ponto_R3 p2){
    if(p==NULL || p1==NULL || p2==NULL){
        return 0;
    }

    int x, y, z;
    get_pto(p-> centro, &x, &y, &z);
    set_pto(p1, x, y, z);

    get_pto(p->extremidade, &x, &y, &z);
    set_pto(p2, x, y, z);

    return 1;
}

void apaga_esfera(esfera *p){
    free(*p);
    *p=NULL;
}

double raio(esfera p){
    if(p==NULL){
        return 0;
    }
    
    double raio = dist(p->centro, p->extremidade);
    return raio;
}

double area(esfera p){
    if(p==NULL){
        return 0;
    }

    double r = raio(p);
    double area = 4*3.14159*r*r;
    return area;
}

double volume(esfera p){
    if(p==NULL){
        return 0;
    }

    double r = raio(p);
    double volume = (4.0/3.0)*3.14159*r*r*r;
    return volume;
}