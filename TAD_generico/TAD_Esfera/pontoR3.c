#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"pontoR3.h"

struct R3{
    int coor_x, coor_y, coor_z;
};

ponto_R3 criar_pto(){
    ponto_R3 p = (ponto_R3)malloc(sizeof(ponto_R3));
    return p;
}

int set_pto(ponto_R3 p, int p1, int p2, int p3){
    if (p == NULL){
        return 0;
    }

    p->coor_x = p1;
    p->coor_y = p2;
    p->coor_z = p3;

    return 1;
}

int get_pto(ponto_R3 p, int *p1, int *p2, int *p3){
    if (p == NULL){
        return 0;
    }

    *p1 = p->coor_x;
    *p2 = p->coor_y;
    *p3 = p->coor_z;

    return 1;
}

void apaga_pto(ponto_R3 *p){
    free(*p);
    *p=NULL;
}

double dist(ponto_R3 p1, ponto_R3 p2){
    if (p1 == NULL || p2==NULL){
        return 0;
    }

    double dist_x, dist_y, dist_z;

    dist_x = p1->coor_x-p2->coor_x;
    dist_y = p1->coor_y-p2->coor_y;
    dist_z = p1->coor_z-p2->coor_z;

    dist_x = dist_x*dist_x;
    dist_y = dist_y*dist_y;
    dist_z = dist_z*dist_z;

    return sqrt(dist_x+dist_y+dist_z);
}