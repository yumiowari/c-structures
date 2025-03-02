//////////////////////////////////////////////////
//      Implementação das Funções de Lista      //
//                                              //
//              Estrutura de Dados              //
//                                              //
//         Por Rafael Renó Corrêa, 2025         //
//////////////////////////////////////////////////

#include <stdlib.h>
#include <string.h>

#include "lista.h"

struct no{ // Nó
    int chave;
    Info *dados;
    struct no *prox;
};

struct lista{ // Lista
    int qtd;
    struct no *raiz;
};

Lista *fazLista(){
// Função para alocar o ponteiro para a lista

    Lista *lista = (Lista*) malloc(sizeof(Lista));
    if(lista == NULL)return NULL;

    lista->raiz = NULL;
    lista->qtd = 0;

    return lista;
}

No *fazNo(int chave, Info *dados){
// Função para alocar o ponteiro para um novo nó

    No *novo_no = (No*) malloc(sizeof(No));
    if(novo_no == NULL)return NULL;

    Info *novo_dado = (Info*) malloc(sizeof(Info));
    if(novo_dado == NULL){
        free(novo_no);

        return NULL;
    }
    *novo_dado = *dados;

    novo_no->chave = chave;
    novo_no->dados = novo_dado;

    return novo_no;
}

int insereNo(Lista *lista, int chave, Info *dados, char *modo){
// Função para inserir um novo elemento na lista

    if(lista == NULL)return 1;

    No *novo_no = fazNo(chave, dados);
    if(novo_no == NULL)return 2;

    if(strcmp(modo, "front") == 0){ // insere o novo nó no começo da lista
        if(lista->qtd > 0){
            novo_no->prox = lista->raiz;

            lista->raiz = novo_no;
        }else{ // se é o primeiro nó
            novo_no->prox = NULL;

            lista->raiz = novo_no;
        }
    }else if(strcmp(modo, "back") == 0){ // insere o novo nó no final da lista
        if(lista->qtd > 0){
            No *aux;

            aux = lista->raiz;

            while(aux->prox != NULL)aux = aux->prox; // O(n)

            novo_no->prox = NULL;

            aux->prox = novo_no;
        }else{ // se é o primeiro nó
            novo_no->prox = NULL;

            lista->raiz = novo_no;
        }
    }else{ // modo inválido
        return 3;
    }

    lista->qtd++;

    return 0;
}

int removeNo(Lista *lista, int chave){
// Função para remover um elemento da lista

    if(lista == NULL)return 1;

    No *ant, *aux;

    if(lista->qtd > 0){
        if(lista->qtd > 1){
            aux = lista->raiz;

            if(aux->chave != chave){
                while((aux != NULL) && (aux->chave != chave)){ // procura o nó
                    ant = aux;

                    aux = aux->prox;
                }

                if(aux != NULL){
                    if(aux->prox != NULL){
                        ant->prox = aux->prox;
                    }else{ // é o último elemento
                        ant->prox = NULL;
                    }
                    
                    free(aux->dados);
                    free(aux);
                }else return 3;
            }else{ // se é o primeiro nó
                lista->raiz = aux->prox;

                free(aux->dados);
                free(aux);
            }
        }else{ // se é o primeiro e único nó
            aux = lista->raiz;

            free(aux->dados);
            free(aux);

            lista->raiz = NULL;
        }
    }else return 2;

    lista->qtd--;

    return 0;
}

Info *consultaNo(Lista *lista, int chave){
// Função para consultar o conteúdo de um elemento da lista a partir da chave

    if(lista == NULL)return NULL;

    if(lista->qtd > 0){
        No *aux = lista->raiz;

        while((aux != NULL) && (aux->chave != chave))aux = aux->prox;

        if(aux != NULL){ // se encontrou
            return aux->dados;
        }else{ // se não encontrou
            return NULL;
        }
    }else return NULL; // a lista está vazia
}

int tamanhoLista(Lista *lista){
// Função para acessar o tamanho da lista

    return lista->qtd;
}

int liberaLista(Lista *lista){
// Função para liberar a lista da memória RAM

    if(lista == NULL)return 1;

    No *ant, *prox;

    ant = lista->raiz;

    while(ant != NULL){
        prox = ant->prox;

        free(ant->dados);
        free(ant);

        ant = prox;
    }

    free(lista);

    return 0;
}