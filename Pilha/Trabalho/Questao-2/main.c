#include<stdio.h>
#include"pilha-char.h"
#include"pilha-float.h"

int valida_escopo(char* expressao){
    pilha_char stack_char = cria_pilha();
    char elem;
    int cont=0, tamanho;
    //pilha_float stack_float = cria_pilha();

    for (int i = 0; expressao[i]!='\0'; i++)
    {
        if (expressao[i]=='(' || expressao[i]=='['|| expressao[i]=='{'){
            tamanho_pilha_char(stack_char, &tamanho);
            if (tamanho>0){
                get_topo_char(stack_char, &elem);
                if(expressao[i]=='('){
                    push_char(&stack_char, expressao[i]);
                    cont++;
                }else if(expressao[i]=='{' && elem!='[' && elem!='('){
                    push_char(&stack_char, expressao[i]);
                    cont++;
                } else if(expressao[i]=='[' && elem!='('){
                    push_char(&stack_char, expressao[i]);
                    cont++;
                } else{
                    printf("Ordem de precedencia dos delimitadores invalida\n");
                    return 0;
                }
            } else if(tamanho==0){
                push_char(&stack_char, expressao[i]);
                cont++;
            }
            
            
        } else if(expressao[i]==')' || expressao[i]==']'|| expressao[i]=='}'){
            (pop_char(&stack_char, &elem));
            cont--;

            if(expressao[i]==')' && elem!='(' || expressao[i]==']' && elem!='['  || expressao[i]=='}' && elem!='{'){
                printf("Ordem de fechamento incorreta\n");
                return 0;
            } 
        }
        if(cont<0){
            printf("Fechamento sem abertura\n");
            return 0;
        } 
    }
    if(cont!=0){
        printf("Mais aberturas do que fechamento\n");
        return 0;
    } 

    return 1;
    
}

int conversao(char* expressao){
    pilha_char stack = cria_pilha();
    char elem;

    for(int i=0; expressao[i]!='\0'; i++){
        if((expressao[i]>='a' && expressao[i]<='z') || (expressao[i]>='A' && expressao[i]<='Z')){
            printf("%c", expressao[i]);

        } else if(expressao[i]=='(' || expressao[i]=='[' || expressao[i]=='{'){
            push_char(&stack, expressao[i]);

        } else if(expressao[i]==')' || expressao[i]==']' || expressao[i]=='}'){
            
            while (get_topo_char(stack, &elem) && elem!='(' && elem!= '[' && elem!='{') {
                pop_char(&stack, &elem);
                printf("%c", elem);
            }
            pop_char(&stack, &elem);

        } else if(expressao[i]=='+' || expressao[i]=='-' || expressao[i]=='*' || expressao[i]=='/' || expressao[i] == '^'){

            while (pilha_vazia_char(stack)==0 && get_topo_char(stack, &elem) && (elem != '(' && elem != '[' && elem != '{') && (((elem == '^') && (expressao[i] != '^')) || ((elem == '*' || elem == '/') && (expressao[i] == '+' || expressao[i] == '-')) || ((elem == '*' || elem == '/') && (expressao[i] == '*' || expressao[i] == '/')) || ((elem == '+' || elem == '-') && (expressao[i] == '+' || expressao[i] == '-')))) {
                pop_char(&stack, &elem);
                printf("%c", elem);
            }
            push_char(&stack, expressao[i]);

        }
    }

    while (pop_char(&stack, &elem)==1){
        printf("%c", elem);
    }

    printf("\n");
    apaga_pilha_char(&stack);
    return 1;
}


int main(){

    //while (1){
        char expressao[101];

        scanf("%[^\n]", expressao);

       if(valida_escopo(expressao)){
        printf("certo\n\n");
       } else{
        printf("Erro\n\n");
       }

       conversao(expressao);
    //}
}