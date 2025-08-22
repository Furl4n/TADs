#include<stdio.h>
#include<stdlib.h>
#include "num_complexo.h"

struct num_complexo{
    float real, imaginario;
};


complexo cria(){
    complexo p = (complexo)malloc(sizeof(complexo));
    return p;
}

int set_nro(complexo p, float r, float i){
    if (p == NULL){
        return 0;
    }

    p->real = r;
    p->imaginario = i;

    return 1;
}

int get_nro(complexo p, float *r, float *i){
    if (p == NULL){
        return 0;
    }

    *r = p->real;
    *i = p->imaginario;

    return 1;
}

void apaga(complexo *p){
    free(*p);
    *p=NULL;
}

complexo soma(complexo p1, complexo p2){
    if (p1 == NULL || p2 ==NULL){
        return NULL;
    }

    complexo p3 = (complexo)malloc(sizeof(complexo));

    p3->real = p1->real+p2->real;
    p3->imaginario = p1->imaginario+p2->imaginario;

    return p3;
}

complexo sub(complexo p1, complexo p2){
    if (p1 == NULL || p2 ==NULL){
        return NULL;
    }

    complexo p3 = (complexo)malloc(sizeof(complexo));

    p3->real = p1->real-p2->real;
    p3->imaginario = p1->imaginario-p2->imaginario;

    return p3;
}

complexo multi(complexo p1, complexo p2){
    if (p1 == NULL || p2 ==NULL){
        return NULL;
    }
    
    complexo p3 = (complexo)malloc(sizeof(complexo));

    p3->real = p1->real*p2->real - p1->imaginario*p2->imaginario;
    p3->imaginario = p1->real*p2->imaginario + p1->imaginario*p2->real;

    return p3;
}