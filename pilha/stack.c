#include <stdlib.h>

#include "stack.h"

struct node{ // nó
    value_t value;
    struct node *next;

};

struct stack{ // pilha
    struct node *root;
    int qty;

};

stack_t *makeStack(){
// função p/ alocar a pilha na memória

    stack_t *stack = (stack_t*) malloc(sizeof(stack_t));
    if(stack != NULL){
        stack->root = NULL;
        stack->qty = 0;
    }

    return stack;
}

node_t *makeNode(value_t value){
// função p/ alocar o nó na memória

    node_t *node = (node_t*) malloc(sizeof(node_t));
    if(node != NULL){
        node->value = value;
        node->next = NULL;
    }

    return node;
}

bool stackNode(stack_t *stack, value_t value){
// função p/ empilhar um elemento na pilha

    if(stack == NULL)
        return false;

    node_t *new_node = makeNode(value);
    if(new_node == NULL){
        return false;
    }
    new_node->next = stack->root;

    stack->root = new_node;

    stack->qty++;

    return true;
}

bool dropNode(stack_t *stack){
// função p/ desempilhar o elemento no topo da pilha

    if(stack == NULL || stack->qty == 0)
        return false;

    node_t *aux_node;

    aux_node = stack->root;

    stack->root = stack->root->next;

    free(aux_node);

    stack->qty--;

    return true;
}

int stackQty(stack_t *stack){
// função p/ retornar a quantidade de elementos na pilha

    return stack->qty;
}

value_t stackTop(stack_t *stack){
// função p/ retornar o conteúdo do elemento no topo da pilha

    return stack->root->value;
}

bool dropStack(stack_t *stack){
// função p/ liberar a pilha da memória

    if(stack == NULL)
        return false;

    node_t *aux_node;

    while(stack->qty > 0){
        dropNode(stack);
    }

    free(stack);

    return true;
}