#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "stacks.h"
#include "queue.h"

void isStackEmptyTest(Stack* S1) {
    int isEmpty = stackIsEmpty(S1);
    if (isEmpty == 0) {
        printf("Stack is empty!");
    }
    else {
        printf("Stack is NOT empty!");
    }
}

void isEmptyTest(List* list) {
    int expected_value = -1;
    int return_value = isEmpty(list);
    if (expected_value != return_value) {
        printf("Test_failed:_");
        printf("isEmpty()_returned_%d_(expected:_ %d)", return_value, expected_value);
    }
}

void insertTest(List* L1, int nodeValue) {
    Node* testNode = createNode(nodeValue);
    int expected_value = 0; //0 if it works!
    int return_value = insert(L1, testNode);
    if (expected_value != return_value) {
        printf("Test_failed:_");
        printf("insert()_returned_%d_(expected:_ %d)", return_value, expected_value);
    }
}

void searchTest(List* L1, int searchValue) {
    int return_value = -1;
    int expected_value = searchValue;
    if (search(L1, expected_value) != NULL) {
        return_value = search(L1, expected_value)->data;
    }
    if (expected_value != return_value) {
        printf("Test_failed:_");
        printf("search_returned_%d_(expected:_ %d)", return_value, expected_value);
    }
}

void deleteTest(List* L1, int nodeValueToRemove) {
    int return_value = -1;
    Node* testNode = createNode(nodeValueToRemove);

    if (search(L1, testNode->data) != NULL) {
        Node* returnedDeletedNode = createNode(-1);
        returnedDeletedNode = delete(L1, testNode);
        return_value = returnedDeletedNode->data;
        free(returnedDeletedNode);
    }
    if (nodeValueToRemove != return_value) {
        printf("Test_failed:_");
        printf("delete()_returned_%d_(expected:_ %d)", return_value, nodeValueToRemove);
    }

    free(testNode);
}

void maximumAndMinTest(List* list, int expected_max, int expected_min) {
    int return_MaxValue = maximum(list)->data;
    int return_MinValue = minimum(list)->data;
    if (expected_max != return_MaxValue || expected_min != return_MinValue) {
        printf("Test_failed:_");
        printf("maximum_returned_%d_(expected:_ %d)_minimum_returned_%d_(expected:_%d)", return_MaxValue, expected_max, return_MinValue, expected_min);
    }
}

void successorPredecessorTest(List* L1, int key, int expected_successor, int expected_predecessor) {
    Node* nodeSuccessor = createNode(key);
    nodeSuccessor = successor(L1, nodeSuccessor);

    Node* nodePredecessor = createNode(key);
    nodePredecessor = predecessor(L1, nodePredecessor);

    int return_successor = -1;
    if (nodeSuccessor != NULL) {
        return_successor = nodeSuccessor->data;
    }
    int return_predecessor = nodePredecessor->data;

    if (expected_successor != return_successor || expected_predecessor != return_predecessor) {
        printf("Test_failed:_");
        printf("sucessor()_returned_%d_(expected:_ %d)_predecessor()_returned_%d_(expected:_%d)", return_successor, expected_successor, return_predecessor, expected_predecessor);
    }
}

void predecessorOfMaximumTest(List* L1, List* L2, int expected_value) {
    int expected_predecessor = expected_value;
    int return_predecessor = predecessor(L2, maximum(L1))->data;

    if (expected_predecessor != return_predecessor) {
        printf("Test_failed:_");
        printf("predecessor()_returned_%d_(expected:_ %d)", return_predecessor, expected_predecessor);
    }
}

void pushPopStackTest() {
    Stack* S1 = createStack();
    push(S1, 1);
    push(S1, 9);
    push(S1, 9);
    push(S1, 1);
    push(S1, 0);
    push(S1, 4);
    push(S1, 0);
    push(S1, 5);
    push(S1, 6);
    push(S1, 8);
    push(S1, 9);
    push(S1, 3);
    push(S1, 9);
    push(S1, 9);
    pop(S1);
    pop(S1);

    displayStack(S1);
}

void enqueueDequeueQueue() {
    Queue* Q1 = createQueue();
    enqueue(Q1, 2);
    enqueue(Q1, 2);
    enqueue(Q1, 1);
    enqueue(Q1, 9);
    enqueue(Q1, 9);
    enqueue(Q1, 1);
    enqueue(Q1, 0);
    enqueue(Q1, 4);
    enqueue(Q1, 0);
    enqueue(Q1, 5);
    enqueue(Q1, 6);
    enqueue(Q1, 8);
    enqueue(Q1, 9);
    enqueue(Q1, 3);
    dequeue(Q1);
    dequeue(Q1);

    displayQueue(Q1);
}

void testQueueWithStack(Stack* S1, Stack* S2, int insertValue1, int insertValue2, int insertValue3) {
    enqueue2(S1, S2, insertValue1);
    enqueue2(S1, S2, insertValue2);
    enqueue2(S1, S2, insertValue3);
}
