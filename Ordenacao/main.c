#include "ordena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

    int main(){

        FILE *arquivo = fopen("Lista_Alunos.txt", "r");

        struct Estudante user[2287];

        for(int i=0; i<2287; i++){
            fscanf(arquivo, "%d %s %f %f %f", &user[i].matricula, user[i].nome, &user[i].n1, &user[i].n2, &user[i].n3);
        }

    int opcao, comparacoes=0, trocas=0;
    double inicio, fim;

    printf("1-Bubble sort\n");
    printf("2-Select sort\n");
    printf("3-Insert sort\n");
    printf("4-Quick sort\n");
    printf("5-Merge sort\n");
    printf("6-Selecione um dos metodos: ");
    scanf("%d", &opcao);

    FILE *resposta = fopen("resposta", "w");
        
    switch (opcao)
    {
    case 1:
        inicio = clock();
        bubble_sort(user, 2287, &comparacoes, &trocas);
        fim = clock();

        for(int i=0; i<2287; i++){
            fprintf(resposta, "%d %s %.2f %.2f %.2f\n", user[i].matricula, user[i].nome, user[i].n1, user[i].n2, user[i].n3);
        }
        fprintf(resposta, "Tempo de ordanação(Milisegundos): %06.2lf\n", (fim-inicio)/CLOCKS_PER_SEC*1000);
        fprintf(resposta, "comparações: %d  trocas:%d", comparacoes, trocas);
        break;
    
    case 2:
        inicio = clock();
        select_sort(user, 2287, &comparacoes, &trocas);
        fim = clock();

        for(int i=0; i<2287; i++){
            fprintf(resposta, "%d %s %.2f %.2f %.2f\n", user[i].matricula, user[i].nome, user[i].n1, user[i].n2, user[i].n3);
        }
        fprintf(resposta, "Tempo de ordanação(Milisegundos): %06.2lf\n", (fim-inicio)/CLOCKS_PER_SEC*1000);
        fprintf(resposta, "comparações: %d  trocas:%d", comparacoes, trocas);

        break;
    
    case 3:
        inicio = clock();
        insert_sort(user, 2287, &comparacoes, &trocas);
        fim = clock();

        for(int i=0; i<2287; i++){
            fprintf(resposta, "%d %s %.2f %.2f %.2f\n", user[i].matricula, user[i].nome, user[i].n1, user[i].n2, user[i].n3);
        }
        fprintf(resposta, "Tempo de ordanação(Milisegundos): %06.2lf\n", (fim-inicio)/CLOCKS_PER_SEC*1000);
        fprintf(resposta, "comparações: %d  trocas:%d", comparacoes, trocas);

        break;
    
    case 4:
        inicio = clock();
        ini_quick_sort(user, 2287, &comparacoes, &trocas);
        fim = clock();

        for(int i=0; i<2287; i++){
            fprintf(resposta, "%d %s %.2f %.2f %.2f\n", user[i].matricula, user[i].nome, user[i].n1, user[i].n2, user[i].n3);
        }
        fprintf(resposta, "Tempo de ordanação(Milisegundos): %06.2lf\n", (fim-inicio)/CLOCKS_PER_SEC*1000);
        fprintf(resposta, "comparações: %d  trocas:%d", comparacoes, trocas);

        break;
    
    case 5:
        inicio = clock();
        merge_sort(user, 0, 2286, &comparacoes, &trocas);
        fim = clock();

        for(int i=0; i<2287; i++){
            fprintf(resposta, "%d %s %.2f %.2f %.2f\n", user[i].matricula, user[i].nome, user[i].n1, user[i].n2, user[i].n3);
        }
        fprintf(resposta, "Tempo de ordanação(Milisegundos): %06.2lf\n", (fim-inicio)/CLOCKS_PER_SEC*1000);
        fprintf(resposta, "comparações: %d  trocas:%d", comparacoes, trocas);

        break;
    
    default:
        break;
    }

}
