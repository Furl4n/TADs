#include "pilha.h"
#include <stdio.h>

void inserir(pilha stack){
    funcionario funcio;

    printf("\nInsira os dados do funcionario a ser adicionado: \n");
    printf("Nome: ");
    scanf(" %[^\n]", funcio.nome);

    printf("Matricula: ");
    scanf("%ld", &funcio.matricula);

    printf("Setor: ");
    scanf(" %c", &funcio.setor);

    printf("Salario: ");
    scanf("%f", &funcio.salario);

    if(push(stack, funcio)==1){
        printf("\n->O funcionario foi adicionado com sucesso\n");
    } else{
        printf("\n->Nao foi possivel adicionar o funcionario\n");
    }
}

void remover(pilha stack){
    funcionario funcio;

    if(pop(stack, &funcio)){
        printf("\n--Funcionario removido--\n");
        printf("Nome: %s\nMatricula: %ld\n", funcio.nome, funcio.matricula);
        printf("Setor: %c\nSalario: %f\n", funcio.setor, funcio.salario);
    } else{
        printf("\n->Nao foi possivel remover o funcionario da pilha\n");
    }
}

int main(){
    
    pilha stack = NULL;
    int condicao = 0;

    while (1){
        int resposta = -1;

        printf("\n---MENU TAD PILHA DE FUNCIONARIOS---\n");
        printf("0-Encerrar o programa\n");
        printf("1-Criar pilha\n");
        printf("2-Verificar se a pilha esta vazia\n");
        printf("3-Verificar se a pilha esta cheia\n");
        printf("4-Inserir o funcionario na pilha\n");
        printf("5-Remover o funcionario da pilha\n");
        printf("6-Verificar o funcionario no topo da pilha\n");
        printf("7-Apagar pilha\n");
        printf("8-Esvaziar pilha\n");
        printf("9-Verificar tamanho da pilha\n");
        printf("10-Imprimir pilha\n");        
        printf("\n->Escolha uma das opcoes acima: ");

        scanf("%d", &resposta);
        getchar();

        if(resposta==0){
            if(condicao==1){
                apaga_pilha(&stack);
            }
            
            printf("\n->Programa encerrado\n");
            return 0;
        }

        if(resposta != 1 && condicao == 0){
            printf("\n->A pilha ainda nao foi criada\n");

        } else if(resposta==1 && condicao == 1){
            printf("\n->So eh possivel criar uma pilha!\n");
        }

        else{
            switch (resposta){
            case 1:
                stack = cria_pilha();
                condicao = 1;
                printf("\n->pilha criada com sucesso.\n");
                break;

            case 2:
                if(pilha_vazia(stack)==1){
                    printf("\n->A pilha esta vazia\n");
                } else{
                    printf("\n->a pilha nao esta vazia\n");
                }
                break;

            case 3:
                if(pilha_cheia(stack)){
                    printf("\n->A pilha esta cheia\n");
                } else{
                    printf("\n->a pilha nao esta cheia\n");
                }
                break;

            case 4:
                inserir(stack);
                break;

            case 5:
                remover(stack);
                break;

            case 6:
                funcionario funcio;

                if(get_topo(stack, &funcio)){
                    printf("\n--Funcionario--\n");
                    printf("Nome: %s\nMatricula: %ld\n", funcio.nome, funcio.matricula);
                    printf("Setor: %c\nSalario: %f\n", funcio.setor, funcio.salario);
                } else{
                    printf("\n->Não foi possível ler o funcinario no topo da pilha\n");
                }
                break;

            case 7:
                apaga_pilha(&stack);
                printf("\n->A pilha foi apagada");
                condicao = 0;
                break;

            case 8:
                esvazia_pilha(stack);
                printf("\n->A pilha foi esvaziada");
                break;

            case 9:
                int tamanho = 0;
                
                tamanho_pilha(stack, &tamanho);
                printf("\n->A pilha tem %d funcionarios\n", tamanho);
                break;

            case 10:
                pilha invertida = cria_pilha();

                while (pilha_vazia(stack)==0){
                    pop(stack, &funcio);
                    push(invertida, funcio);
                }

                for(int i=0; pilha_vazia(invertida)==0; i++){
                    pop(invertida, &funcio);
                    push(stack, funcio);
                    printf("\n--Funcionario N°%d--\n", i+1);
                    printf("Nome: %s\nMatricula: %ld\n", funcio.nome, funcio.matricula);
                    printf("Setor: %c\nSalario: %f\n", funcio.setor, funcio.salario);
                }

                apaga_pilha(&invertida);
                break;

                default:
                    printf("\n->Opção invalida\n");
                    break;
            }
        }
    }
}