#define pontoR3_h

typedef struct R3* ponto_R3;

ponto_R3 criar_pto();
int set_pto(ponto_R3 p, int p1, int p2, int p3);
int get_pto(ponto_R3 p, int *p1, int *p2, int *p3);
void apaga_pto(ponto_R3 *p);
double dist(ponto_R3 p1, ponto_R3 p2);