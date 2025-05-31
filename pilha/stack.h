#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct value{ // valor
    int num;

}typedef(value_t);

typedef struct node node_t;
typedef struct stack stack_t;

stack_t *makeStack();
// função p/ alocar a pilha na memória

bool stackNode(stack_t *stack, value_t value);
// função p/ empilhar um elemento na pilha

bool dropNode(stack_t *stack);
// função p/ desempilhar o elemento no topo da pilha

int stackQty(stack_t *stack);
// função p/ retornar a quantidade de elementos na pilha

value_t stackTop(stack_t *stack);
// função p/ retornar o conteúdo do elemento no topo da pilha

bool dropStack(stack_t *stack);
// função p/ liberar a pilha da memória

#endif // STACK_H