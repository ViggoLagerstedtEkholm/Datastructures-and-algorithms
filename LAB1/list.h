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

void display(List* list);
int isEmpty(List* list);
Node* createNode(int nodeData);
List* createLinkedList();
int insert(List* list, Node* z);
Node* search(List* list, int key);
Node* maximum(List* list);
Node* minimum(List* list);
Node* successor(List* list, Node* x);
Node* predecessor(List* list, Node* x);
Node* delete(List* list, Node* z);
void  freeList(List* list);
void insertIntoL1Test(List* L1);
void insertIntoL2Test(List* L2);
