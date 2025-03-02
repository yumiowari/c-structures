#include <stdio.h>
#include <stdbool.h>

#include "lista.h"

bool rotinaTeste(Lista *lista);
// Rotina de testes para as funções da lista
//
// Retornos:
// - true: tudo certo; e
// - false: algum teste falhou.

bool imprimeLista(Lista *lista, int x, int y);
// Função para imprimir o conteúdo da lista da chave x até a chave y
//
// Retornos:
// - true: tudo certo; e
// - false: a lista nunca foi alocada.

int main(void){
    Lista *lista = NULL;

    if(rotinaTeste(lista) == true){
        printf("Os testes sucederam :)\n");
    }else fprintf(stderr, "Algum teste falhou :(\n");

    return 0;
}

bool rotinaTeste(Lista *lista){
// Rotina de testes para as funções da lista

    int i;
    Info dados;

    lista = fazLista();
    if(lista == NULL)return false;

    for(i = 0; i < 5; i++){
    // Teste de inserção no começo da lista

        dados.valor = (i + 1) * 10;
        dados.caractere = 'a' + i;
        if(insereNo(lista, i + 1, &dados, "front") != 0)return false;
    }

    for(i = 5; i < 10; i++){
    // Teste de inserção no final da lista

        dados.valor = (i + 1) * 10;
        dados.caractere = 'a' + i;
        if(insereNo(lista, i + 1, &dados, "back") != 0)return false;
    }

    if(imprimeLista(lista, 1, 10) != true)return false;
    printf("\n");

    for(i = 1; i <= 10; i++){
        if(removeNo(lista, i) != 0)return false;

        if(imprimeLista(lista, i, 10) != true)return false;
        printf("\n");
    }

    if(liberaLista(lista) != 0)return false;

    return false;
}

bool imprimeLista(Lista *lista, int x, int y){
// Função para imprimir o conteúdo da lista da chave x até a chave y

    if(lista == NULL)return false;
    
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
        printf("Lista = {}.\n");
    }

    return true;
}