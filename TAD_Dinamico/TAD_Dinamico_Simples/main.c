#include<stdio.h>
#include "TAD_Dinamico_Simples.h"

int inserir(lista *list){
    char elem;


    printf("\nInsira o caracter: ");
    getchar();
    scanf("%c", &elem);
    

    if (insere_elem(&list, elem)==1){
        printf("\n->O caracter foi adicionado com sucesso\n");
        return 1;
    } else{
        printf("\n->Nao foi possível adicionar o caracter\n");
        return 0;
    }
}

int remover(lista *list){

    char elem;

    printf("Qual texto deseja apagar? ");
    getchar();
    scanf("%c", &elem);

    if(remove_elem(&list, elem)==1){
        printf("\n->Caracter apagada com sucesso\n");
        return 1;
    } else{
        printf("\n->Nao foi possível apagar o caracter\n");
        return 0;
    }
}

int get_pos(lista *list){

    char elem;
    int pos;

    printf("Digite a posicao que deseja copiar: ");
    scanf("%d", &pos);

    elem = get_elem_pos(list, pos);
    printf("\n->Caracter: %c\n", elem);

    if(elem!='\0'){
        printf("\n->Caracter: %c\n", elem);
        return 1;
    } else{
        printf("\n->Nao foi possivel copiar o caracter nessa posicao\n");
        return 0;
    }
}

int main(){
    lista list = NULL;
    int condicao = 0;

    while (1){
        int resposta = -1;

        printf("\n---MENU TAD LISTA NAO ORDENADA DE CARACTERES---\n");
        printf("0-Encerrar o programa\n");
        printf("1-Criar lista\n");
        printf("2-Verificar se a lista esta vazia\n");
        printf("3-Inserir caracter na lista\n");
        printf("4-Remover caracter da lista\n");
        printf("5-Pegar caracter por posicao\n");
        printf("6-Apagar lista\n");
        printf("\nEscolha uma das opcoes acima: ");

        scanf("%d", &resposta);

        if(resposta==0){
            printf("\n->Programa encerrado\n");
            apaga_lista(list);
            return 0;
        }

        if(resposta != 1 && condicao == 0){
            printf("\n->A lista ainda nao foi criada\n");

        } else if(resposta==1 && condicao == 1){
            printf("\n->So eh possivel criar uma lista!\n");
        }

        else{

            switch (resposta){
                case 1:
                    list = criar_lista();
                    condicao = 1;
                    printf("\n->Lista criada\n");
                    break;

                case 2:
                    if(lista_vazia(list)==1){
                        printf("\n->A lista esta vazia\n");
                    } else{
                        printf("\n->A lista nao esta vazia\n");
                    }
                    break;

                case 3:
                    inserir(&list);
                    break;
            
                case 4:
                    remover(&list);
                    break;

                case 5:
                    get_pos(*list);
                    break;

                case 6:
                    apaga_lista(&list);
                    condicao = 0;
                    break;
        
                default:
                    break;
            }
        }
    }

        
    
}