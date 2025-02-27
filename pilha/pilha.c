//////////////////////////////////////////////////
//      Implementação das Funções de Pilha      //
//                                              //
//              Estrutura de Dados              //
//                                              //
//         Por Rafael Renó Corrêa, 2025         //
//////////////////////////////////////////////////

#include <stdlib.h>

#include "pilha.h"

struct no{ // Nó
    Info *dados;
    struct no *prox;
};

struct pilha{ // Pilha
    int qtd;
    struct no* raiz;
};

Pilha *fazPilha(){
// Função para alocar o ponteiro para a pilha

    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    if(pilha == NULL)return NULL;

    pilha->raiz = NULL;
    pilha->qtd = 0;

    return pilha;
}

No *fazNo(Info *dados){
// Função para alocar o ponteiro para um novo nó

    No *novoNo = (No*) malloc(sizeof(No));
    if(novoNo == NULL)return NULL;

    Info *novoDado = (Info*) malloc(sizeof(Info));
    if(novoDado == NULL){
        free(novoNo);

        return NULL;
    }
    *novoDado = *dados;

    novoNo->dados = novoDado;

    return novoNo;
}

int empilhaNo(Pilha *pilha, Info *dados){
// Função para empilhar um novo elemento

    if(pilha == NULL)return 1;

    No *novoNo = fazNo(dados);
    if(novoNo == NULL)return 2;

    if(pilha->qtd > 0){
        novoNo->prox = pilha->raiz;

        pilha->raiz = novoNo;
    }else{ // se é o primeiro nó
        novoNo->prox = NULL;

        pilha->raiz = novoNo;
    }

    pilha->qtd++;

    return 0;
}

int desempilhaNo(Pilha *pilha){
// Função para desempilhar o elemento no topo da pilha

    if(pilha == NULL)return 1;

    if(pilha->qtd > 0){
        No *aux = pilha->raiz;

        pilha->raiz = aux->prox;

        free(aux);
    }else return 2;

    return 0;
}

int tamanhoPilha(Pilha *pilha){
// Função para acessar o tamanho da pilha

    return pilha->qtd;
}

