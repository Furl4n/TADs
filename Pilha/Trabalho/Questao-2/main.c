#include<stdio.h>
#include"pilha-char.h"
#include"pilha-float.h"
#include <math.h>
#include <string.h>

int valida_escopo(char* expressao){
    pilha_char stack_char = cria_pilha_char();
    char elem;
    int cont=0, tamanho;

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

int conversao(char* expressao, char* convertida){
    pilha_char stack = cria_pilha_char();
    char elem;
    int j = 0;

    for(int i=0; expressao[i]!='\0'; i++){
        char atual = expressao[i];

        if((atual>='a' && atual<='z') || (atual>='A' && atual<='Z')){
            convertida[j++] = atual;

        } else if(atual=='(' || atual=='[' || atual=='{'){
            push_char(&stack, atual);

        } else if(atual==')' || atual==']' || atual=='}'){
            while (get_topo_char(stack, &elem) && elem!='(' && elem!= '[' && elem!='{') {
                pop_char(&stack, &elem);
                convertida[j++] = elem;
            }
            pop_char(&stack, &elem);

        } else if(atual=='+' || atual=='-' || atual=='*' || atual=='/' || atual == '^'){
            while (pilha_vazia_char(stack)==0 && get_topo_char(stack, &elem) && (elem != '(' && elem != '[' && elem != '{') && (((elem == '^') && (atual != '^')) || ((elem == '*' || elem == '/') && (atual == '+' || atual == '-')) || ((elem == '*' || elem == '/') && (atual == '*' || atual == '/')) || ((elem == '+' || elem == '-') && (atual == '+' || atual == '-')))) {
                pop_char(&stack, &elem);
                convertida[j++] = elem;
            }
            push_char(&stack, atual);
        }
    }

    while (pop_char(&stack, &elem)==1){
        convertida[j++] = elem;
    }

    convertida[j] = '\0';

    apaga_pilha_char(&stack);
    return 1;
}

int calcular(char* expressao, float *res){
    float vet[123];
    
    for(int j='A'; j<='Z'; j++){
        for(int i=0; expressao[i]!='\0'; i++){
            if(expressao[i]==j){
                printf("Qual o valor de '%c' na expressao? ", j);
                scanf("%f", &vet[j]);
                break;
            }
        }
    }


    for(int j='a'; j<='z'; j++){
        for(int i=0; expressao[i]!='\0'; i++){
            if(expressao[i]==j){
                printf("Qual o valor de '%c' na expressao? ", j);
                scanf("%f", &vet[j]);
                break;
            }
        }
    }



    pilha_float stack_float = cria_pilha_float();
    float operando1, operando2, resultado;

    for (int i = 0; expressao[i] != '\0'; i++) {

        if ((expressao[i] >= 'a' && expressao[i] <= 'z') || (expressao[i] >= 'A' && expressao[i] <= 'Z')) {
            push_float(&stack_float, vet[expressao[i]]);
        } 
        else if (expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/' || expressao[i] == '^') {
            if (pop_float(&stack_float, &operando2)==0 || pop_float(&stack_float, &operando1)==0) {
                printf("\n->ERRO: Falta de operando.\n");
                apaga_pilha_float(&stack_float);
                return 0;
            }
            switch (expressao[i]) {
                case '+': 
                    resultado = operando1 + operando2; 
                    break;

                case '-':
                    resultado = operando1 - operando2;
                    break;

                case '*': 
                    resultado = operando1 * operando2; 
                    break;

                case '/': 
                    resultado = operando1 / operando2; 
                    break;

                case '^': 
                    resultado = pow(operando1, operando2); 
                    break;
            }
            push_float(&stack_float, resultado);
        }
    }
    
    if(pop_float(&stack_float, &resultado)==0){
        printf("\n->ERRO: Expressao invalida ou vazia.\n");
        apaga_pilha_float(&stack_float);
        return 0;
    }

    if (pilha_vazia_float(stack_float)==0) {
        printf("\n->ERRO: Falta de operador.\n");
        apaga_pilha_float(&stack_float);
        return 0;
    }
    
    apaga_pilha_float(&stack_float);
    *res = resultado;
    return 1;
}

int main(){

    while (1){
        char expressao[101];
        char convertida[101];
        float res;

        printf("\n->digite a expressao a ser calculada: ");
        scanf(" %[^\n]", expressao);

        if(strcmp(expressao, "FIM")==0){
            return 0;
        }
        else if(valida_escopo(expressao)){
            conversao(expressao, convertida);
            printf("\n->A expressao convertida para pos-fixa eh: %s\n", convertida);

            printf("\n->Agora vamos avaliar essa expressao:\n");
            calcular(convertida, &res);

            printf("\n->O resultado da expressao eh: %.2f\n", res);
        } else{
            printf("\n->Insira a expressao novamente\n");
        }
    }
}