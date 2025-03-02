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

int empilhaNo(Pilha *pilha, Info *dados){
// Função para empilhar um novo elemento

    if(pilha == NULL)return 1;

    No *novo_no = fazNo(dados);
    if(novo_no == NULL)return 2;

    if(pilha->qtd > 0){
        novo_no->prox = pilha->raiz;

        pilha->raiz = novo_no;
    }else{ // se é o primeiro nó
        novo_no->prox = NULL;

        pilha->raiz = novo_no;
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

        free(aux->dados);
        free(aux);
    }else return 2;

    pilha->qtd--;

    return 0;
}

Info *consultaTopo(Pilha *pilha){
// Função para consultar o elemento no topo da pilha

    if(pilha->qtd == 0)return NULL;

    No *aux = pilha->raiz;

    return aux->dados;
}

int tamanhoPilha(Pilha *pilha){
// Função para acessar o tamanho da pilha

    return pilha->qtd;
}

int derrubaPilha(Pilha *pilha){
// Função para liberar a pilha da memória RAM

    if(pilha == NULL)return 1;

    while(pilha->qtd > 0)desempilhaNo(pilha);

    free(pilha);

    return 0;
}
