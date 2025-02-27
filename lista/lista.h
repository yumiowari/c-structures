//////////////////////////////////////////////////
//       Assinaturas das Funções de Lista       //
//                                              //
//              Estrutura de Dados              //
//                                              //
//         Por Rafael Renó Corrêa, 2025         //
//////////////////////////////////////////////////

#ifndef LISTA_H
#define LISTA_H

typedef struct info{ // Informação
    int valor;
    char caractere;

    // Preencha com as informações desejadas...
}Info;

typedef struct no No;
typedef struct lista Lista;

Lista *fazLista();
// Função para alocar o ponteiro para a lista
//
// Retorno:
// - Ponteiro do tipo Lista (se nulo, não havia memória RAM disponível).

No *fazNo(int chave, Info *dados);
// Função para alocar o ponteiro para um novo nó
//
// Retorno:
// - Ponteiro do tipo Nó (se nulo, não havia memória RAM disponível).

int insereNo(Lista *lista, int chave, Info *dados, char *modo);
// Função para inserir um novo elemento na lista
//
// Modos:
//     - "front": insere o elemento no começo da lista (O(1)); e
//     - "back": insere o elemento no final da lista (O(n)).
//
// Retornos:
// - 0: tudo certo;
// - 1: a lista nunca foi alocada;
// - 2: memória RAM insuficiente; e
// - 3: o modo não foi implementado.

int removeNo(Lista *lista, int chave);
// Função para remover um elemento da lista
//
// Retornos:
// - 0: tudo certo;
// - 1: a lista nunca foi alocada;
// - 2: a lista está vazia; e
// - 3: o elemento não está na lista.

Info *consultaNo(Lista *lista, int chave);
// Função para consultar o conteúdo de um elemento da lista a partir da chave
//
// Retornos:
// - Ponteiro para a informação contida no elemento (se nulo, não havia elemento).

int tamanhoLista(Lista *lista);
// Função para acessar o tamanho da lista
//
// Portanto, retorna a quantidade de elementos na lista.

int liberaLista(Lista *lista);
// Função para liberar a lista da memória RAM
//
// Retornos:
// - 0: tudo certo; e
// - 1: a lista nunca foi alocada.

#endif // LISTA_H