#pragma once
#include "list.h"
#include "stacks.h"

typedef struct queue_element_t { // we define our linked-list element
    int count;
    Node* head;
    Node* tail;
} Queue;

int dequeue(Queue* queue);
void enqueue(Queue* queue, int x);
Queue* createQueue();
void displayQueue(Queue* stack);
int dequeue2(Stack*);
void enqueue2(Stack*, Stack*, int);