#include <stdio.h>
#include "tad.h"

int main(){
    racional p = generate();
    int num, den;

    int teste = set_value(p, 12, 6);
    int pega = get_value(p, &num, &den);

    printf("%p %d\n%d %d\n", p, teste, num, den);

    int del = delete(&p);

    printf("%p %d", p, del);

    return 0;
}