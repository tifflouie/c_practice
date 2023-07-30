#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    int size;
    int top;
    int *s;
};

void createStack(struct Stack *stack) {
    stack->size = 4;
    stack->top = -1;
    stack->s = (int *)malloc(stack->size * sizeof(int));
}

void displayStack(struct Stack *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->s[i]);
    }
}

void push(struct Stack *stack, int num) {
    stack->top++;
    stack->s[stack->top] = num;
}

int pop(struct Stack *stack) {
    int num = stack->s[stack->top];
    stack->top--;
    return num;
}

int peek(struct Stack *stack, int stack_index) {
    int x = stack->s[stack->top - stack_index + 1];
    return x;
}

// int isEmpty(struct Stack *stack) {
//     if (stack->top == -1) {
//         return 1;
//     }
//     return 0;
// }

int main() {
    struct Stack stack;
    createStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);

    displayStack(&stack);

    printf("-------\n");

    pop(&stack);

    displayStack(&stack);

    printf("-------\n");

    printf("%d\n", peek(&stack, 1));




}