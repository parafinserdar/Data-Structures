#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top; 
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1; 
    return stack;
}


int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}


int isEmpty(Stack* stack) {
    return stack->top == -1;
}


void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack dolu, eleman eklenemiyor.\n");
        return;
    }
    stack->data[++stack->top] = value; 
    printf("%d stack'e eklendi.\n", value);
}


int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack boş, eleman çıkarılamaz.\n");
        return -1;
    }
    return stack->data[stack->top--]; 
}


int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack boş, peek işlemi yapılamaz.\n");
        return -1;
    }
    return stack->data[stack->top];
}

int main() {
    Stack* stack = createStack(); 

    push(stack, 10); 
    push(stack, 20);
    push(stack, 30);

    printf("Stack'in üstündeki eleman: %d\n", peek(stack)); 

    printf("Eleman çıkarıldı: %d\n", pop(stack)); 
    printf("Eleman çıkarıldı: %d\n", pop(stack));

    printf("Stack'in üstündeki eleman: %d\n", peek(stack));

    push(stack, 40); 

    printf("Stack'in üstündeki eleman: %d\n", peek(stack));

    free(stack); 
    return 0;
}
