//////////////////////////////////////////////////
//       Assinaturas das Funções de Fila        //
//                                              //
//              Estrutura de Dados              //
//                                              //
//         Por Rafael Renó Corrêa, 2025         //
//////////////////////////////////////////////////

#ifndef FILA_H
#define FILA_H

typedef struct info{ // Informação
    int valor;
    char caractere;

    // Preencha com as informações desejadas...
}Info;

typedef struct no No;
typedef struct fila Fila;

Fila *fazFila();
// Função para alocar o ponteiro para a fila
//
// Retorno:
// - Ponteiro do tipo Fila (se nulo, não havia memória RAM disponível).

No *fazNo(Info *dados);
// Função para alocar o ponteiro para um novo nó
//
// Retorno:
// - Ponteiro do tipo Nó (se nulo, não havia memória RAM disponível).

int insereNo(Fila *fila, Info *dados);
// Função para inserir um novo elemento na fila
//
// Retornos:
// - 0: tudo certo;
// - 1: a fila nunca foi alocada; e
// - 2: memória RAM insuficiente.

int removeNo(Fila *fila);
// Função para remover um elemento da fila
//
// Retornos:
// - 0: tudo certo;
// - 1: a fila nunca foi alocada; e
// - 2: a fila está vazia.

Info *consultaFrente(Fila *file);
// Função para consultar o conteúdo do elemento na frente da fila
//
// Retornos:
// - Ponteiro para a informação contida no elemento (se nulo, não havia elemento).

int tamanhoFila(Fila *fila);
// Função para acessar o tamanho da fila
//
// Portanto, retorna a quantidade de elementos na fila.

int liberaFila(Fila *fila);
// Função para liberar a fila da memória RAM
//
// Retornos:
// - 0: tudo certo; e
// - 1: a fila nunca foi alocada.

#endif // FILA_H