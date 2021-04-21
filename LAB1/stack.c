#include <stdlib.h>
#include <stdio.h>
#include "stacks.h"

//Returns 0 if empty and -1 if not.
int stackIsEmpty(Stack* S1) {
    if (S1->count == 0) {
        return 0;
    }
    return -1;
}

//Method pops the last node in the stack.
int pop(Stack* stack) {
    int returnValue = -1;

    if (stack->count == 0) {
        return -1;
    }
    else {

        if (stack->head == stack->tail)
        {
            stack->head = NULL;
            stack->tail = NULL;
            stack->count = 0;
        }
        else {
            stack->tail->prev->next = NULL;
            stack->tail = stack->tail->prev;
            stack->count--;
        }
        if (stack->tail != NULL)
            returnValue = stack->tail->data;

        return returnValue;
    }

}

//Method pushes a node into a stack.
void push(Stack* stack, int x) {
    Node* z = (Node*)malloc(sizeof(Node));
    if (z != NULL) {
        z->data = x;
        if (stack->head == NULL) {
            stack->head = z;
            stack->tail = z;
        }
        else {
            stack->tail->next = z;
            z->prev = stack->tail;
            z->next = NULL;
            stack->tail = z;
        }
        stack->count++;
    }
}

//Creates a empty stack.
Stack* createStack() {  
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack != NULL) {
        stack->tail = NULL; // give the lists head a nullvalue
        stack->head = NULL; // give the lists tail a nullvalue
        stack->count = 0;
    }
    return stack;
}

//Displays stack values.
void displayStack(Stack* stack) {

    if (stack != NULL) {
        Node* firstNode = stack->head;
        for (int i = 0; i < stack->count; i++) {
            printf("%d", firstNode->data);
            printf("\n");
            firstNode = firstNode->next;

        }
    }
}