//////////////////////////////////////////////////
//       Assinaturas das Funções de Pilha       //
//                                              //
//              Estrutura de Dados              //
//                                              //
//         Por Rafael Renó Corrêa, 2025         //
//////////////////////////////////////////////////

#ifndef PILHA_H
#define PILHA_H

typedef struct info{ // Informação
    int valor;
    char caractere;
    
    // Preencha com as informações desejadas...
}Info;

typedef struct no No;
typedef struct pilha Pilha;

Pilha *fazPilha();
// Função para alocar o ponteiro para a pilha
//
// Retornos:
// - Ponteiro do tipo Pilha (se nulo, não havia memória RAM disponível)

No *fazNo(int chave, Info *dados);
// Função para alocar o ponteiro para um novo nó
//
// Retorno:
// - Ponteiro do tipo Nó (se nulo, não havia memória RAM disponível)

int empilhaNo(Pilha *pilha, Info *dados);
// Função para empilhar um novo elemento
//
// Retornos:
// - 0: tudo certo;
// - 1: a pilha nunca foi alocada; e
// - 2: memória RAM insuficiente;

int desempilhaNo(Pilha *pilha);
// Função para desempilhar o elemento no topo da pilha
//
// Retornos:
// - 0: tudo certo;
// - 1: a pilha nunca foi alocada; e
// - 2: a pilha está vazia;

Info *consultaTopo(Pilha *pilha);
// Função para consultar o elemento no topo da pilha
//
// Retornos:
// - Ponteiro para a informação contida no elemento (se nulo, não havia elemento)

int tamanhoPilha(Pilha *pilha);
// Função para acessar o tamanho da pilha
//
// Portanto, retorna a quantidade de elementos na pilha

int derrubaPilha(Pilha *pilha);
// Função para liberar a pilha da memória RAM
//
// Retornos:
// - 0: tudo certo; e
// - 1: a pilha nunca foi alocada.

#endif // PILHA_H