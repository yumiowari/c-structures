#include <stdio.h>

#include "lista.h"

int rotinaTeste(Lista *lista);
// Rotina de testes para as funções da lista
//
// Retornos:
// - 0: tudo certo; e
// - 1: algum teste falhou.

int imprimeLista(Lista *lista, int x, int y);
// Função para imprimir o conteúdo da lista da chave x até a chave y
//
// Retornos:
// - 0: tudo certo; e
// - 1: a lista nunca foi alocada.

int main(void){
    Lista *lista = NULL;

    if(rotinaTeste(lista) == 0){
        printf("Os testes sucederam :)\n");
    }else fprintf(stderr, "Algum teste falhou :(\n");

    return 0;
}

int rotinaTeste(Lista *lista){
// Rotina de testes para as funções da lista

    int i;
    Info dados;

    lista = fazLista();
    if(lista == NULL)return 1;

    for(i = 0; i < 5; i++){
    // Teste de inserção no começo da lista

        dados.valor = (i + 1) * 10;
        dados.caractere = 'a' + i;
        if(insereNo(lista, i + 1, &dados, "front") != 0)return 1;
    }

    for(i = 5; i < 10; i++){
    // Teste de inserção no final da lista

        dados.valor = (i + 1) * 10;
        dados.caractere = 'a' + i;
        if(insereNo(lista, i + 1, &dados, "back") != 0)return 1;
    }

    if(imprimeLista(lista, 1, 10) != 0)return 1;
    printf("\n");

    for(i = 1; i <= 10; i++){
        if(removeNo(lista, i) != 0)return 1;

        if(imprimeLista(lista, i, 10) != 0)return 1;
        printf("\n");
    }

    if(liberaLista(lista) != 0)return 1;

    return 0;
}

int imprimeLista(Lista *lista, int x, int y){
// Função para imprimir o conteúdo da lista da chave x até a chave y

    if(lista == NULL)return 1;
    
    int chave;
    Info *dados = NULL;

    if(tamanhoLista(lista) > 0){
        printf("Lista = {");
        for(chave = x; chave < y; chave++){
            dados = consultaNo(lista, chave);
            if(dados != NULL){
                printf("%d: [%d, %c]; ", chave, dados->valor, dados->caractere);
            }
        }
        dados = consultaNo(lista, chave);
        if(dados != NULL){
            printf("%d: [%d, %c]}.\n", chave, dados->valor, dados->caractere);
        }
    }else{
        printf("{}.\n");
    }

    return 0;
}