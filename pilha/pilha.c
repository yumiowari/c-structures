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