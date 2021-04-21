#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "stacks.h"

//Enqueues a integer value into the queue.
void enqueue(Queue* queue, int x) {
    Node* h = (Node*)malloc(sizeof(Node));
    if (h != NULL) {
        h->data = x;
        if (queue->count == 0) {
            queue->head = h;
            queue->tail = h;
            queue->count++;
        }

        else if (queue->head == queue->tail)
        {
            queue->head->next = h;
            h->prev = queue->head;
            queue->tail = h;
            h->next = NULL;
            queue->count++;
        }

        else {
            h->prev = queue->tail;
            queue->tail->next = h;
            queue->tail = h;
            h->next = NULL;
            queue->count++;
        }
    }
}

//Dequeues the first item in the queue.
int dequeue(Queue* queue) {
    int x = -1;
    if (queue->head != NULL) {
        x = queue->head->data;

        if (queue->head->next != NULL) {
            queue->head->next->prev = NULL;
            queue->head = queue->head->next;

        }
        else {
            queue->head = NULL;
            queue->tail = NULL;
        }
        queue->count--;
    }
    return x;
}

//Creates an empty queue.
Queue* createQueue() {  // This method returns an empty List and allocate memory for it
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue != NULL) {
        queue->tail = NULL; // give the lists head a nullvalue
        queue->head = NULL; // give the lists tail a nullvalue
        queue->count = 0;
    }
    return queue;
}

//Display the queue values.
void displayQueue(Queue* queue) {

    if (queue != NULL) {
        Node* firstNode = queue->head;
        for (int i = 0; i < queue->count; i++) {
            printf("%d", firstNode->data);
            printf("\n");
            firstNode = firstNode->next;

        }
    }
}

//Using 2 stacks so create a queue, takes a integer value to insert.
void enqueue2(Stack* stack2, Stack* stack1, int x) {

    while (stack1->count > 0)
    {
        push(stack2, stack1->tail->data);
        pop(stack1);
    }

    push(stack1, x);

    while (stack2->count > 0) {
        push(stack1, stack2->tail->data);
        pop(stack2);
    }
}

//Dequeue the first value in the queue.
int dequeue2(Stack* stack1) {
    int x = -1;

    if (stack1 != NULL) {
        x = stack1->head->data;
        pop(stack1);

    }
    return x;
}