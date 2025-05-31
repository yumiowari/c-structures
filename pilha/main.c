#include <stdio.h>

#include "stack.h"

int main(void){
    stack_t *stack = NULL;

    stack = makeStack();

    value_t value;

    for(int i = 1; i <= 10; i++){
        value.num = i;

        stackNode(stack, value);
    }

    for(int i = 1; i <= 5; i++){
        dropNode(stack);
    }

    printf("É o nó no topo da pilha: %d\n", stackTop(stack));

    dropStack(stack);

    return 0;
}