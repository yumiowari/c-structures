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
    Info *ptr = NULL;

    fila = fazFila();
    if(fila == NULL)return 1;

    printf("Enfileirando...\n");
    for(i = 0; i < 10; i++){
        dados.valor = i + 1;
        dados.caractere = 'a' + i;

        printf("[%d, %c]\n", dados.valor, dados.caractere);

        if(insereNo(fila, &dados) != 0)return 1;

        ptr = consultaFrente(fila);
        if(ptr == NULL)return 1;
    }

    printf("Desenfileirando...\n");
    for(i = 0; i < 10; i++){
        ptr = consultaFrente(fila);
        if(ptr == NULL)return 1;

        printf("[%d, %c]\n", ptr->valor, ptr->caractere);

        if(removeNo(fila) != 0)return 1;
    }

    if(liberaFila(fila) != 0)return 1;

    return 0;
}