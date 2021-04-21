#include <stdlib.h>
#include <stdio.h>
#include "sorting.h"

void display(List* list) {

    if (list != NULL) {
        Node* firstNode = list->head;
        for (int i = 0; i < list->count; i++) {
            printf("%d", firstNode->data);
            printf("\n");
            firstNode = firstNode->next;

        }
    }
}

int isEmpty(List* list) { // method the checks if the linked-list is empty
    if (list->count == 0) { // check if the list is NULL
        return 0; // if so return 0 representing true
    }
    else {
        return -1; // else it return -1 representing false
    }
}

List* createLinkedList() {  // This method returns an empty List and allocate memory for it
    List* list = (List*)malloc(sizeof(List));
    if (list != NULL) {
        list->tail = NULL; // give the lists head a nullvalue
        list->head = NULL; // give the lists tail a nullvalue
        list->count = 0;
    }
    return list;
}

Node* createNode(int nodeData) {

    Node* aNode = (Node*)malloc(sizeof(Node));
    if (aNode != NULL) {
        aNode->data = nodeData;
    }
    return aNode;
}

int insert(List* list, Node* z) { // This method inserts a new node into a Linked-List

    if (list->head == NULL) // checks if the list is empty which is would be if the head is NULL
    {
        list->head = z;          // insert the parameter values into the lists head
        list->head->prev = NULL; // the head i the first value therefore the prev should be NULL
        list->head->next = NULL; //
        list->count++;
        return 0;
    }
    if (list->tail == NULL)
    {
        list->tail = list->head;
        z->next = list->tail;
        z->prev = NULL;
        list->tail->prev = z;
        list->tail->next = NULL;
        list->head = z;

        list->count++;
        return 0;
    }

    if (list->tail != NULL)
    {
        list->head->prev = z;
        z->prev = NULL;
        z->next = list->head;
        list->head = z;
        list->count++;

        return 0;
    }

    return -1;
}

Node* search(List* list, int key) {
    Node* x = list->head;

    while (x != NULL && x->data != key) {
        x = x->next;
    }

    return x;

}

Node* maximum(List* list) {
    if (list != NULL) {
        Node* x = list->head;
        Node* max = x;
        while (x != NULL) {
            if (x->data > max->data) {
                max = x;
            }
            x = x->next;
        }

        return max;
    }

    return NULL;

}

Node* minimum(List* list) {
    if (list != NULL) {
        Node* x = list->head;
        Node* min = x;
        while (x != NULL) {
            if (x->data < min->data) {
                min = x;
            }
            x = x->next;
        }

        return min;
    }
    return NULL;
}

Node* successor(List* list, Node* x) {
    Node* z = list->head;
    Node* highValueNode = NULL;
    Node* lowValueNode = NULL;

    while (z != NULL) {
        if (x->data < z->data) {
            if (lowValueNode == NULL && highValueNode == NULL) {
                highValueNode = z;
                lowValueNode = z;
            }
            else {
                highValueNode = z;
            }

            if (highValueNode->data < lowValueNode->data) {
                lowValueNode = highValueNode;
            }
        }
        z = z->next;
    }
    if (lowValueNode != NULL) {
        return lowValueNode;
    }
    return NULL;
}

Node* predecessor(List* list, Node* x) {
    Node* z = list->head;
    Node* highValueNode = NULL;
    Node* lowValueNode = NULL;

    while (z != NULL) {
        if (x->data > z->data) {
            if (lowValueNode == NULL && highValueNode == NULL) {
                highValueNode = z;
                lowValueNode = z;
            }
            else {
                lowValueNode = z;
            }

            if (highValueNode->data < lowValueNode->data) {
                highValueNode = lowValueNode;
            }
        }
        z = z->next;
    }
    if (highValueNode != NULL) {
        return highValueNode;
    }
    return NULL;
}

Node* delete(List* list, Node* z)
{
    Node* deletedNode = NULL;
    if (z != NULL && list != NULL) {
        deletedNode = search(list, z->data);
        if (deletedNode != NULL) {
            if (deletedNode->prev != NULL)
                deletedNode->prev->next = deletedNode->next;

            else
                list->head = deletedNode->next;

            if (deletedNode->next != NULL)
                deletedNode->next->prev = deletedNode->prev;

            else
                list->tail = deletedNode->prev;


            list->count--;
        }
    }


    return deletedNode;
}


void insertIntoL1Test(List* L1) {


    Node* a1 = (Node*)malloc(sizeof(Node));
    if (a1 != NULL)
        a1->data = 7;
    Node* b1 = (Node*)malloc(sizeof(Node));
    if (b1 != NULL)
        b1->data = 8;
    Node* c1 = (Node*)malloc(sizeof(Node));
    if (c1 != NULL)
        c1->data = 10;
    Node* d1 = (Node*)malloc(sizeof(Node));
    if (d1 != NULL)
        d1->data = 5;
    Node* e1 = (Node*)malloc(sizeof(Node));
    if (e1 != NULL)
        e1->data = 1;
    Node* f1 = (Node*)malloc(sizeof(Node));
    if (f1 != NULL)
        f1->data = 3;

    insert(L1, a1);
    insert(L1, b1);
    insert(L1, c1);
    insert(L1, d1);
    insert(L1, e1);
    insert(L1, f1);

}

void freeList(List* list) {
    Node* tmp;

    while (list->head != NULL)
    {
        tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }
}

void insertIntoL2Test(List* L2) {

    Node* a2 = (Node*)malloc(sizeof(Node));
    if (a2 != NULL)
        a2->data = 2;
    Node* b2 = (Node*)malloc(sizeof(Node));
    if (b2 != NULL)
        b2->data = 1;
    Node* c2 = (Node*)malloc(sizeof(Node));
    if (c2 != NULL)
        c2->data = 6;
    Node* d2 = (Node*)malloc(sizeof(Node));
    if (d2 != NULL)
        d2->data = 9;
    Node* e2 = (Node*)malloc(sizeof(Node));
    if (e2 != NULL)
        e2->data = 2;
    Node* f2 = (Node*)malloc(sizeof(Node));
    if (f2 != NULL)
        f2->data = 5;


    insert(L2, a2);
    insert(L2, b2);
    insert(L2, c2);
    insert(L2, d2);
    insert(L2, e2);
    insert(L2, f2);
}
