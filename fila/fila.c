//////////////////////////////////////////////////
//      Implementação das Funções de Fila       //
//                                              //
//              Estrutura de Dados              //
//                                              //
//         Por Rafael Renó Corrêa, 2025         //
//////////////////////////////////////////////////

#include <stdlib.h>

#include "fila.h"

struct no{ // Nó
    Info *dados;
    struct no *prox;
};

struct fila{ // Fila
    int qtd;
    struct no *raiz;
};

Fila *fazFila(){
// Função para alocar o ponteiro para a fila

    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if(fila == NULL)return NULL;

    fila->raiz = NULL;
    fila->qtd = 0;

    return fila;
}

No *fazNo(Info *dados){
// Função para alocar o ponteiro para um novo nó

    No *novo_no = (No*) malloc(sizeof(No));
    if(novo_no == NULL)return NULL;

    Info *novo_dado = (Info*) malloc(sizeof(Info));
    if(novo_dado == NULL){
        free(novo_no);

        return NULL;
    }
    *novo_dado = *dados;

    novo_no->dados = novo_dado;

    return novo_no;
}

int insereNo(Fila *fila, Info *dados){
// Função para inserir um novo elemento na fila

    if(fila == NULL)return 1;

    No *novo_no = fazNo(dados);
    if(novo_no == NULL)return 2;

    if(fila->qtd > 0){
        No *aux = fila->raiz;

        while(aux->prox != NULL)aux = aux->prox; // O(n)

        novo_no->prox = NULL;

        aux->prox = novo_no;
    }else{ // se é o primeiro nó
        novo_no->prox = NULL;

        fila->raiz = novo_no;
    }

    fila->qtd++;

    return 0;
}

int removeNo(Fila *fila){
// Função para remover um elemento da fila

    if(fila == NULL)return 1;

    if(fila->qtd > 0){
        No *aux = fila->raiz;

        fila->raiz = aux->prox;

        free(aux);
    }else return 2;

    fila->qtd--;

    return 0;
}

Info *consultaFrente(Fila *fila){
// Função para consultar o conteúdo do elemento na frente da fila

    No *aux = fila->raiz;

    return aux->dados;
}

int tamanhoFila(Fila *fila){
// Função para acessar o tamanho da fila

    return fila->qtd;
}

int liberaFila(Fila *fila){
// Função para liberar a fila da memória RAM

    if(fila == NULL)return 1;

    while(fila->qtd > 0)removeNo(fila);

    free(fila);

    return 0;
}