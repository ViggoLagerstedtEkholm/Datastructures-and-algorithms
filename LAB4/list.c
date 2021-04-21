#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void display(List* list) {

    if (list != NULL) {
        Node* firstNode = list->head;
        for (int i = 0; i < list->count; i++) {
            printf("%d", firstNode->data->Name);
            printf("\n");
            firstNode = firstNode->next;
        }
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

Node* createNode() {

    Node* aNode = (Node*)malloc(sizeof(Node));
    if (aNode != NULL) {
        aNode->data = NULL;
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

Node* search(List* list, Vertex* key) {
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




void freeList(List* list) {
    Node* tmp;

    while (list->head != NULL)
    {
        tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }
}

