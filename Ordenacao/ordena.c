#include "ordena.h"
#include <stdlib.h>
#include <math.h>

void bubble_sort(estudante user[], int tamanho, int *comparacoes, int *trocas){
    for(int iteracao=0; iteracao<tamanho-1; iteracao++){
        int troca=0;
        for (int i=0; i < tamanho-1; i++){
            (*comparacoes)++;
            if(user[i].matricula>user[i+1].matricula){
                estudante aux = user[i];
                user[i] = user[i+1];
                user[i+1] = aux;
                (*trocas)++;
                troca=1;
            }
        }

        if(troca==0) break;
    }
}

void select_sort(estudante user[], int tamanho, int *comparacoes, int *trocas){
    for (int iteracao = 0; iteracao < tamanho - 1; iteracao++) {
        int menor = iteracao;

        for (int i = iteracao + 1; i < tamanho; i++) {
            (*comparacoes)++;
            if (user[i].matricula < user[menor].matricula) {
                menor = i;
            }
        }

        if (iteracao != menor) {
            estudante aux = user[iteracao];
            user[iteracao] = user[menor];
            user[menor] = aux;
            (*trocas)++;
        }
    }
}

void insert_sort(estudante user[], int tamanho, int *comparacoes, int *trocas){

    for (int iteracao = 1; iteracao < tamanho; iteracao++) {
        estudante elem = user[iteracao];
        int i = iteracao-1;

        while (i >= 0 && user[i].matricula > elem.matricula) {
            (*comparacoes)++;   
            (*trocas)++;
            user[i+1] = user[i];
            i--;
        }
        if (i >= 0) (*comparacoes)++;

        user[i+1] = elem;
        (*trocas)++;
    }
}

void ini_quick_sort(estudante user[], int tamanho, int *comparacoes, int *trocas){
    quick_sort(user, 0, tamanho-1, comparacoes, trocas);
}

void quick_sort(estudante user[], int p, int r, int *comparacoes, int *trocas) {
    if (p < r) {
        int v = (rand() % (r - p + 1)) + p; 
        estudante pivo = user[v];
        
        estudante aux_troca_pivo = user[v];
        user[v] = user[r];
        user[r] = aux_troca_pivo;
        (*trocas)++;
        
        int i = p; 
        int j = r - 1;

        while (i <= j) {
            
            while (i <= j && user[i].matricula < pivo.matricula) {
                (*comparacoes)++;
                i++;
            }

            if(i <= j) (*comparacoes)++;

            while (j >= i && user[j].matricula > pivo.matricula) {
                (*comparacoes)++;
                j--;
            }

            if(j >= i) (*comparacoes)++;

            if (i < j) {
                estudante aux = user[i];
                user[i] = user[j];
                user[j] = aux; 
                (*trocas)++;
                i++;
                j--;
            }
        }
        
        quick_sort(user, p, j, comparacoes, trocas);
        quick_sort(user, i, r, comparacoes, trocas);
    }
}

void merge_sort(estudante user[], int ini, int fim, int *comparacoes, int *trocas){
    if (ini < fim) {
        int meio = floor((ini+fim)/2);
        merge_sort(user, ini, meio, comparacoes, trocas);
        merge_sort(user, meio+1, fim, comparacoes, trocas);

        intercala(user, ini, meio, fim, comparacoes, trocas);
    }
}

void intercala(estudante user[], int ini, int meio, int fim, int *comparacoes, int *trocas) {
    int p1 = ini, p2 = meio + 1, fim1 = 0, fim2 = 0;
    int tamanho = fim - ini + 1;
    estudante *vaux = (estudante*) malloc(tamanho * sizeof(struct Estudante));
    
    if (vaux != NULL) {
        int i, j, k;

        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                (*comparacoes)++;

                if (user[p1].matricula < user[p2].matricula) {
                    vaux[i] = user[p1++];
                    (*trocas)++;
                } else {
                    vaux[i] = user[p2++];
                    (*trocas)++;
                }
                
                if (p1 > meio) {
                    fim1 = 1;
                }
                if (p2 > fim) {
                    fim2 = 1;
                }
            } else {
                if (!fim1) {
                    vaux[i] = user[p1++];
                    (*trocas)++;
                } else {
                    vaux[i] = user[p2++];
                    (*trocas)++;
                }
            }
        }

        for (j = 0, k = ini; j < tamanho; j++, k++) {
            user[k] = vaux[j];
            (*trocas)++;
        }
        
        free(vaux);
    }
}