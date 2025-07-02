#define tad_h

typedef struct racional* racional;

racional generate();
int set_value(racional p, int n, int d);
int get_value(racional p, int *n, int *d);
int delete(racional *p);