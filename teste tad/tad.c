#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

struct racional{
    int num, den;
};

racional generate() {
racional p;
p = (racional) malloc(sizeof(racional));
return p;
};

int set_value(racional p, int n, int d){

    if (p == NULL || d == 0){
        return 0;
    }

    p->num = n;
    p->den = d;

    return 1;
}

int get_value(racional p, int *n, int *d){
    if(p ==NULL){
        return 0;
    }

    *n = p->num;
    *d = p->den;

    return 1;
}

int delete(racional *p){
    free(*p);
    *p=NULL;

    return 1;
}