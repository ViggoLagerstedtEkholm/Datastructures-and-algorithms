#pragma once
typedef struct Node_t {     // we define a node element
    int data;
    struct  Node_t* next;
    struct  Node_t* prev;
} Node;

typedef struct list_element_t { // we define our linked-list element
    int count;
    Node* head;
    Node* tail;
} List;

Node* createNode(int);
int isEmpty(List* list);
List* createLinkedList();
int insert(List* list, Node* z);
Node* search(List* list, int key);
Node* maximum(List* list);
Node* minimum(List* list);
Node* successor(List* list, Node* x);
Node* predecessor(List* list, Node* x);
Node* delete(List* list, Node* z);
void  freeList(List* list);

int* insertionSort(int* arr, int size);
void printArray(int* arr, int size);
void plot(int* arr, int size);
void plot2(List*);

void printList(Node* node);
Node* merge(Node* leftListNode, Node* rightListNode);
void middleNode(Node* nodeHead, Node** frontNode, Node** backNode, int totalCount);
void mergeSort(List* list);
