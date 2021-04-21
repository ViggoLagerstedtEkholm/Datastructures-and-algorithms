#include <stdlib.h>
#include <stdio.h>
#include "sorting.h"
#include "test.h"

#define ARRAY_SIZE 6
#define ARRAY_SIZE_PERSONAL_NUMBER 10

void exercise5WithListMerge2(List* L1)
{
	mergeSort(L1);

}
void exercise5WithListMerge1(List* L2)
{
	mergeSort(L2);
}

void exercise5PersonalNumberForInsertionSort() {
	int personalNumber[ARRAY_SIZE_PERSONAL_NUMBER] = { 2, 0, 0, 0, 10, 27, 9, 9, 9, 9 };

	int* sortedArray = insertionSort(personalNumber, ARRAY_SIZE_PERSONAL_NUMBER);

	printArray(sortedArray, ARRAY_SIZE_PERSONAL_NUMBER);
}

void exercise5PersonalNumberForMergeSort() {
	List* list = createLinkedList();
	Node* node1 = createNode(2);
	Node* node2 = createNode(0);
	Node* node3 = createNode(0);
	Node* node4 = createNode(0);

	Node* node5 = createNode(10);
	Node* node6 = createNode(27);
	Node* node7 = createNode(9);
	Node* node8 = createNode(9);
	Node* node9 = createNode(9);

	insert(list, node1);
	insert(list, node2);
	insert(list, node3);
	insert(list, node4);
	insert(list, node5);
	insert(list, node6);
	insert(list, node7);
	insert(list, node8);
	insert(list, node9);

	mergeSort(list);

	printList(list->head);
}

void exercise5WithInsertionSort1()
{
	int personalNumber[ARRAY_SIZE] = { 3, 1, 5, 10, 8, 7};

	int* sortedArray = insertionSort(personalNumber, ARRAY_SIZE);

	printArray(sortedArray, ARRAY_SIZE);

}

void exercise5WithInsertionSort2()
{
	int personalNumber[ARRAY_SIZE] = { 5, 2, 9, 6, 1, 2};

	int* sortedArray = insertionSort(personalNumber, ARRAY_SIZE);

	printArray(sortedArray, ARRAY_SIZE);
}
