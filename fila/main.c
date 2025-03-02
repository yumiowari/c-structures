#include <stdio.h>

#include "fila.h"

int rotinaTeste(Fila *fila);
// Rotina de testes para as funções de fila
//
// Retornos:
// - 0: tudo certo; e
// - 1: algum teste falhou.

int main(void){
    Fila *fila = NULL;

    if(rotinaTeste(fila) == 0){
        printf("Os testes sucederam :)\n");
    }else fprintf(stderr, "Algum teste falhou :(\n");
    
    return 0;
}

int rotinaTeste(Fila *fila){
// Rotina de testes para as funções de fila
    

    return 0;
}