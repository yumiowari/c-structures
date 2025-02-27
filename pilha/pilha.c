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