#define ORDENA_H

typedef struct Estudante{
    char nome[41];
    int matricula;
    float n1, n2, n3;
}estudante;

void bubble_sort(estudante user[], int tamanho, int *comparacoes, int *trocas);
void select_sort(estudante user[], int tamanho, int *comparacoes, int *trocas);
void insert_sort(estudante user[], int tamanho, int *comparacoes, int *trocas);
void ini_quick_sort(estudante user[], int tamanho, int *comparacoes, int *trocas);
void quick_sort(estudante user[], int p, int r, int *comparacoes, int *trocas);
void merge_sort (estudante user[], int ini, int fim, int *comparacoes, int *trocas);
void intercala(estudante user[], int ini, int meio, int fim, int *comparacoes, int *trocas);