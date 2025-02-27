#include <stdio.h>

#include "pilha.h"

int rotinaTeste(Pilha *pilha);
// Rotina de testes para as funções de pilha
//
// Retornos:
// - 0: tudo certo; e
// - 1: algum teste falhou.

int imprimePilha(Pilha *pilha);
// Função para imprimir o conteúdo da pilha
//
// Retornos:
// - 0: tudo certo; e
// - 1: a pilha nunca foi alocada.

int main(void){
    Pilha *pilha = NULL;

    if(rotinaTeste(pilha) == 0){
        printf("Os testes sucederam :)\n");
    }else fprintf(stderr, "Algum teste falhou :(\n");

    return 0;
}

int rotinaTeste(Pilha *pilha){
// Rotina de testes para as funções de pilha
    
    int i;
    Info dados;

    pilha = fazPilha();
    if(pilha == NULL)return 1;

    for(i = 0; i < 10; i++){
        dados.valor = (i + 1);
        dados.caractere = 'a' + i;

        if(empilhaNo(pilha, &dados) != 0)return 1;
    }

    for(i = 0; i < 10; i++)if(desempilhaNo(pilha) != 0)return 1;

    return 0;
}