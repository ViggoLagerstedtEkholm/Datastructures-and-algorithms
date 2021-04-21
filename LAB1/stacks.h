#pragma once
#include "list.h"

typedef struct stack_element_t { // we define our linked-list element
    int count;
    Node* head;
    Node* tail;
} Stack;

int pop(Stack* stack);
void push(Stack* stack, int x);
Stack* createStack();
void displayStack(Stack* stack);
int stackIsEmpty(Stack* stack);
