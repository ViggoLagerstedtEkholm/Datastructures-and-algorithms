#include "math.h"
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include <windows.h>

//Takes a linked list as a argument.
void mergeSort(List* list) {
	int totalCount = list->count; //get the total node count in the linked list.
	Node* head = list->head; //Get the start of the linked list.
	Node* frontNode; //We will use this node to define the first node in the subarray.
	Node* backNode; //We will use this node to define the last node in the subarray.

	//Base case, stop the recursion.
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	middleNode(head, &frontNode, &backNode, totalCount); //This method "split" the linked list into subarrays.

	totalCount = totalCount / 2; //This will divide until the merge tree is formed, Example: 1 -> 1/2 -> 1/4 -> 1/8 -> 1/16 -> 1/32 ...

	List* leftList = createLinkedList(); //Create the left subarray. 
	List* rightList = createLinkedList(); //Create the right subarray. 

	leftList->head = frontNode; //Head node of left linked list 1
	leftList->count = totalCount;
	rightList->head = backNode; //Head node of right linked list 2
	rightList->count = totalCount;

	//Call this method recusivly, this will generate a tree of linked lists.
	mergeSort(leftList);
	mergeSort(rightList);

	//Here we merge 2 linked lists.
	list->head = merge(leftList->head, rightList->head);
	plot2(list);
}

//The double pointers will point to other pointers.
void middleNode(Node* nodeHead, Node** frontNode, Node** backNode, int totalCount)
{
	int middle = totalCount / 2; //We need to know where the middle node is in the list.
	Node* middleNode = nodeHead;

	int j = 1;

	//Derefrencing NULL pointer.
	if (nodeHead != NULL) {
		//this while loop iterates until !(j < middle) and changes the pointer for our nodes.
		//This effectivly splits the linked list into 2.
		// Example
		// LeftList(node1 -> node2 -> node3) | RightList(node1 -> node2 -> node3)
		while ((nodeHead != NULL || nodeHead->next != NULL) && j < middle)
		{
			middleNode = middleNode->next; //We keep on going through all the nodes because we have not yet found the middle node.
			j++;
		}

		*frontNode = nodeHead; //Define of start of left list.
		*backNode = middleNode->next; //Define start of right list.
		middleNode->next = NULL; //This "splits" the linked list because we say that the middlenode next node pointer is NULL.
	}
}

Node* merge(Node* leftListNode, Node* rightListNode)
{
	Node sentinel; //We need this to start merging our two sorted lists into a new list.
	Node* newNode = createNode(0); //Instansiate new node.
	Node* tail = &sentinel; //We give the tail node the adress of the sentinel.

	sentinel.next = NULL; //Doesn't point to anything.
	while (leftListNode != NULL || rightListNode != NULL) //We check if a node exist in either linked list.
	{
		//Which one is null?
		//If right list is null, we can just put the left list node in. This goes vice versa.
		if (leftListNode == NULL)
		{
			tail->next = rightListNode; //The tail->next points to the right list node. 
			break; //We're done.
		}
		else if (rightListNode == NULL)
		{
			tail->next = leftListNode; //The tail->next points to the left list node.
			break; //We're done.
		}

		//Is the first node in the left linked list greater than the one in the right one?
		//We can simply change >= to get ascending order.
		if (leftListNode->data >= rightListNode->data) {
			newNode = leftListNode;

			//Derefrencing pointer.
			if (newNode != NULL) {
				leftListNode = newNode->next; //Our new leftListNode is the current newNode->next.

				newNode->next = tail->next; //Connect new node in the list.

				tail->next = newNode; //We finally chain together the list using pointers.
			}
		}
		else {
			newNode = rightListNode;

			//Derefrencing pointer.
			if(newNode != NULL) {
				rightListNode = newNode->next;

				newNode->next = tail->next;

				tail->next = newNode;
			}
		}
		tail = tail->next; //Move the tail forward.
	}

	//We return everything except the tail.
	//This will return the list1 and list2 but now merged together (sorted).
	return(sentinel.next); 
}

void plot2(List* list)
{
	Node* value = createNode(1);
	value = list->head;
	for (int row = 0; row < list->count; ++row)
	{
		for (int column = 0; column < value->data / 16; ++column)
		{
			printf(" % c ", '#');
		}
		value = value->next;
		printf("\n");
	}
	Sleep(50);
	system("cls");
}

//Print the list content.
void printList(Node* node)
{
	int i = 0;
	while (node != NULL) {
		i++;
		printf("Index: %d, data: %d \n", i, node->data);
		node = node->next;
	}
}