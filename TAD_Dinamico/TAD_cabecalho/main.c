#include<stdio.h>
#include"TAD_Cabecalho.h"

int inserir(lista list){
    int expo;
    float coeficinte;


    printf("\nInsira o coeficiente do termo: ");
    scanf("%f", &coeficinte);
    printf("Insira o expoente do termo: ");
    scanf("%d", &expo);
    

    if (insere_ord(list, coeficinte, expo)==1){
        printf("\n->O termo foi adicionado com sucesso\n");
        return 1;
    } else{
        printf("\n->Nao foi possível adicionar o termo\n");
        return 0;
    }
}

int remover(lista list){

    int expo;

    printf("Qual termo deseja apagar?(expoente) ");
    scanf("%d", &expo);

    if(remove_ord(list, expo)==1){
        printf("\n->termo apagada com sucesso\n");
        return 1;
    } else{
        printf("\n->Nao foi possível apagar o termo\n");
        return 0;
    }
}

int get_pos(lista list){

    int expo, pos;
    float coeficinte;
    int res;

    printf("Digite a posicao que deseja copiar: ");
    scanf("%d", &pos);

    res = get_elem_pos(list, pos, &expo, &coeficinte);
    
    if(res!='\0'){
        printf("\n->termo: %.2fx^%d\n", coeficinte, expo);
        return 1;
    } else{
        printf("\n->Nao foi possivel copiar o termo nessa posicao\n");
        return 0;
    }
}

int main(){
    lista list = NULL;
    int condicao = 0;

    while (1){
        int resposta = -1;

        printf("\n---MENU TAD POLINOMIO ORDENADO---\n");
        printf("0-Encerrar o programa\n");
        printf("1-Criar polinomio\n");
        printf("2-Verificar se o polinomio esta vazio\n");
        printf("3-Inserir termo do polinomio\n");
        printf("4-Remover termo do polinomio\n");
        printf("5-Pegar termo por posicao\n");
        printf("6-Esvaziar polinomio\n");
        printf("7-Apagar polinomio\n");
        printf("\nEscolha uma das opcoes acima: ");

        scanf("%d", &resposta);

        if(resposta==0){
            if(condicao==0){
                printf("\n->Programa encerrado\n");
                return 0;
            }
            apaga_lista(&list);
            return 0;
        }

        if(resposta != 1 && condicao == 0){
            printf("\n->O polinomio ainda nao foi criado\n");

        } else if(resposta==1 && condicao == 1){
            printf("\n->So eh possivel criar um polinomio!\n");
        }

        else{

            switch (resposta){
                case 1:
                    list = criar_lista();
                    condicao = 1;
                    printf("\n->polinomio criado\n");
                    break;

                case 2:
                    if(lista_vazia(list)==1){
                        printf("\n->O polinomio esta vazio\n");
                    } else{
                        printf("\n->O polinomio nao esta vazio\n");
                    }
                    break;

                case 3:
                    inserir(list);
                    break;
            
                case 4:
                    remover(list);
                    break;

                case 5:
                    get_pos(list);
                    break;

                case 6:
                    if(esvazia_lista(list)==1){
                        printf("Polinomio esvaziado com sucesso\n");
                    } else{
                        printf("Não foi possivel esvaziar o polinomio\n");
                    }

                    break;

                case 7:
                    apaga_lista(&list);
                    printf("\n->polinomio apagado com sucesso\n");
                    condicao = 0;
                    break;
        
                default:
                    break;
            }
        }
    }

        
    
}