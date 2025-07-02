#define num_complexo_h

typedef struct num_complexo* complexo;

complexo cria();
int set_nro(complexo p, int r, int i);
int get_nro(complexo p, int *r, int *i);
void apaga(complexo *p);
complexo soma(complexo p1, complexo p2);
complexo sub(complexo p1, complexo p2);
complexo multi(complexo p1, complexo p2);