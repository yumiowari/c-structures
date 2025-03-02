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
    
    int i;
    Info dados;
    Info *ptr = &dados;

    fila = fazFila();
    if(fila == NULL)return 1;

    for(i = 0; i < 10; i++){
        dados.valor = i + 1;
        dados.caractere = 'a' + i;

        if(insereNo(fila, ptr) != 0)return 1;
    }

    for(i = 0; i < 10; i++){
        if(removeNo(fila) != 0)return 1;
    }

    return 0;
}