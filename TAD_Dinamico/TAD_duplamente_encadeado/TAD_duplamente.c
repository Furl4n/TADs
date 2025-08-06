#include<stdlib.h>
#include"TAD_duplamente.h"

struct no{
    int info;
    lista ant, prox;
};

/*
Entrada: Nenhuma
Pré-condição: Nenhuma
Processo: cria uma lista
Saída: endereço da lista
Pós-condição: Nenhuma
*/
lista cria_lista(){
    return NULL;
}

/*
Entrada: Endereco de uma lista (List)
Pré-condição: Nenhuma
Processo: Confere se a lista está vazia
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: nenhuma
*/
int lista_vazia(lista list){
    if(list==NULL) return 1;

    else return 0;
}

/*
Entrada: Endereço do endereço de uma lista (List) e um inteiro
Pré-condição: Nenhuma
Processo: Adiciona o inteiro a lista
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: Novo número adicionado a lista
*/
int insere_elem(lista *list, int elem){
    lista novo = (lista)malloc(sizeof(struct no));
    if(novo==NULL) return 0;

    novo->info = elem;
    novo->prox = *list;
    novo->ant = NULL;

    if(lista_vazia(*list)==0){
        (*list)->ant = novo;
    }
    *list = novo;

    return 1;
}

/*
Entrada: Endereço do endereço de uma lista (List) e um inteiro
Pré-condição: A lista não ser vazia
Processo: remove um elemento da lista se existir
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: Lista com um número a menos
*/
int remove_elem(lista *list, int elem){
    if(lista_vazia(*list)) return 0;

    lista aux = *list;

    while (aux->info!=elem && aux->prox!=NULL){
        aux = aux->prox;
    }

    if(aux->info!=elem) return 0;
    if(aux->prox!=NULL) aux->prox->ant = aux->ant;
    if(aux->ant!=NULL) aux->ant->prox = aux->prox;
    if(aux == *list) *list = aux->prox;

    free(aux);
    return 1;
}

/*
Entrada: Endereço do endereço de uma lista (List), posicao que deseja inserir e um inteiro
Pré-condição: A posicao ser maior de 0
Processo: Adiciona o inteiro a lista na posição solicitada
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: Novo número adicionado a lista na posição solicitada
*/
int insere_posicao(lista *list, int pos, int elem){
    if(pos<=0) return 0;
    lista novo = (lista)malloc(sizeof(struct no));
    if(novo==NULL) return 0;
    novo->info = elem;

    if(pos==1){
        novo->ant = NULL;
        novo->prox = *list;
        if(lista_vazia(*list)==0) novo->prox->ant = novo;
        *list = novo;
        return 1;

    } else{
        lista aux = *list;
        int i=0;

        while(i<pos-1 && aux!=NULL){
            aux = aux->prox;
            i++;
        }

        if(aux==NULL){
            free(novo);
            return 0;

        } else{
            novo->ant = aux;
            novo->prox = aux->prox;
            if(aux->prox!=NULL) aux->prox->ant=novo;
            aux->prox = novo;
            return 1;
        }
    }
}

/*
Entrada: Endereco do endereço de uma lista (List)
Pré-condição: A lista não ser vazia
Processo: Remove todos os números pares da lista
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: A lista sem nenhum número par
*/
int remove_pares(lista *list){
    if (lista_vazia(*list)) {
        return 0;
    }

    lista aux = *list;
    while (aux != NULL) {
        lista aux2 = aux->prox;

        if (aux->info % 2 == 0) {
            if (aux->ant != NULL) {
                aux->ant->prox = aux->prox;
            } else {
                *list = aux->prox;
            }

            if (aux->prox != NULL) {
                aux->prox->ant = aux->ant;
            }

            free(aux);
        }
        
        aux = aux2;
    }

    return 1;
}

/*
Entrada: Endereco do endereço de uma lista (List)
Pré-condição: A lista não ser vazia
Processo: Remove o maior número da lista
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: Lista sem o maior número
*/
int remove_maior(lista *list){
    if(lista_vazia(*list)) return 0;

    lista maior = *list;

    lista aux = (*list)->prox;

    while (aux != NULL){
        if(aux->info>=maior->info) maior = aux;
        aux = aux->prox;
    }

    if(maior->ant!=NULL) maior->ant->prox = maior->prox;
    else{
        *list = maior->prox;
    }
    if(maior->prox!=NULL) maior->prox->ant = maior->ant;

    free(maior);

    return 1;
}

/*
Entrada: Endereco de uma lista (List)
Pré-condição: A lista não ser vazia
Processo: Inverte uma lista
Saída: O endereço de uma nova lista invertida
Pós-condição: uma nova lista invertida
*/
lista inverte_lista(lista list){
    if(lista_vazia(list)) return NULL;

    lista invertida = cria_lista();

    lista aux = (lista)malloc(sizeof(struct no));
    if(aux == NULL) return NULL;

    aux->info = list->info;
    aux->ant = NULL;
    aux->prox = NULL;
    invertida = aux;
    list = list->prox;


    while(list!=NULL){
        lista temp = (lista)malloc(sizeof(struct no));
        if(temp == NULL) return NULL;

        temp->info = list->info;
        temp->ant = NULL;
        temp->prox = invertida;
        invertida->ant = temp;

        invertida = temp;
        list = list->prox;
    }

    return invertida;
}

/*
Entrada: Endereco de uma lista (List), posicao que deseja inserir e um inteiro
Pré-condição: A lista não ser vazia
Processo: Copia o número na posição solicitada
Saída: 1 (sucesso) ou 0 (falha)
Pós-condição: Nenhum
*/
int get_elem_pos(lista list, int pos, int *elem){
    if(lista_vazia(list)) return 0;

    int i=1;

    while(i<pos && list!=NULL){
        list = list->prox;
        i++;
    }

    if(list!=NULL) *elem = list->info;

    else return 0;

    return 1;
}