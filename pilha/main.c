#include <stdio.h>

#include "pilha.h"

bool rotinaTeste(Pilha *pilha);
// Rotina de testes para as funções de pilha
//
// Retornos:
// - true: tudo certo; e
// - false: algum teste falhou.

int main(void){
    Pilha *pilha = NULL;

    if(rotinaTeste(pilha) == 0){
        printf("Os testes sucederam :)\n");
    }else fprintf(stderr, "Algum teste falhou :(\n");

    return 0;
}

bool rotinaTeste(Pilha *pilha){
// Rotina de testes para as funções de pilha
    
    int i;
    Info dados;
    Info *ptr = NULL;

    pilha = fazPilha();
    if(pilha == NULL)return false;

    printf("Empilhando...\n");
    for(i = 0; i < 10; i++){
        dados.valor = (i + 1);
        dados.caractere = 'a' + i;

        if(empilhaNo(pilha, &dados) != 0)return false;

        ptr = consultaTopo(pilha);
        if(ptr == NULL)return false;
        
        printf("[%d, %c]\n", ptr->valor, ptr->caractere);
    }

    printf("Desempilhando...\n");
    for(i = 0; i < 10; i++){
        ptr = consultaTopo(pilha);
        if(ptr == NULL)return false;
        
        printf("[%d, %c]\n", ptr->valor, ptr->caractere);

        if(desempilhaNo(pilha) != 0)return false;
    }

    if(derrubaPilha(pilha) != 0)return false;

    return true;
}