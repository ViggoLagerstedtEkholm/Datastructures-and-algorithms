#pragma once
#include "list.h"

void isEmptyTest(List* list);
void insertTest(List* list, int nodeValue);
void searchTest(List* list, int searchValue);
void maximumAndMinTest(List* list, int expected_max, int expected_min);
void successorPredecessorTest(List* list, int key, int expected_successor, int expected_predecessor);
void deleteTest(List* list, int nodeValueToRemove);
void predecessorOfMaximumTest(List* L1, List* L2, int expected_value);
void pushPopStackTest();
void enqueueDequeueQueue();
void testQueueWithStack(Stack* S1, Stack* S2, int insertValue1, int insertValue2, int insertValue3);
void isStackEmptyTest(Stack* S1);
void insertIntoL1Test(List* L1);
void insertIntoL2Test(List* L2);
