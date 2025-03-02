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

