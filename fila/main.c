#include <stdio.h>
#include <stdbool.h>

#include "fila.h"

bool rotinaTeste(Fila *fila);
// Rotina de testes para as funções de fila
//
// Retornos:
// - true: tudo certo; e
// - false: algum teste falhou.

int main(void){
    Fila *fila = NULL;

    if(rotinaTeste(fila) == true){
        printf("Os testes sucederam :)\n");
    }else fprintf(stderr, "Algum teste falhou :(\n");
    
    return 0;
}

bool rotinaTeste(Fila *fila){
// Rotina de testes para as funções de fila
    
    int i;
    Info dados;
    Info *ptr = NULL;

    fila = fazFila();
    if(fila == NULL)return false;

    printf("Enfileirando...\n");
    for(i = 0; i < 10; i++){
        dados.valor = i + 1;
        dados.caractere = 'a' + i;

        printf("[%d, %c]\n", dados.valor, dados.caractere);

        if(insereNo(fila, &dados) != 0)return false;

        ptr = consultaFrente(fila);
        if(ptr == NULL)return false;
    }

    printf("Desenfileirando...\n");
    for(i = 0; i < 10; i++){
        ptr = consultaFrente(fila);
        if(ptr == NULL)return false;

        printf("[%d, %c]\n", ptr->valor, ptr->caractere);

        if(removeNo(fila) != 0)return false;
    }

    if(liberaFila(fila) != 0)return false;

    return true;
}