#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "sorting.h"
#include "load_file.h"
#include "test.h"

int main(int argc, char* argv[])
{
	const char* fname = argv[1];

	int* data = load_file(fname);

	int choise;
	int notScannedArgument = 0;
	//Query the user for input.
	printf("What algorithm do you want to choose? \n");
	printf("Press 1. Insertion sort\n");
	printf("Press 2. Merge sort\n");
	printf("Press 3. Merge sort on L1\n");
	printf("Press 4. Merge sort on L2\n");
	printf("Press 5. Insertion sort on L1\n");
	printf("Press 6. Insertion sort on L2\n");
	printf("Press 7. Insertion sort personal number\n");
	printf("Press 8. Merge sort personal number\n");

	notScannedArgument = scanf("%d", &choise);

	if (notScannedArgument > 0) 
	{
		if (choise == 1)
		{
			float time_spent = 0.0;

			clock_t begin = clock();

			printf("Sorting... \n");
			int sizeForInsertionSort = data[0];

			int* sortedArray = insertionSort(data, sizeForInsertionSort + 1);

			clock_t end = clock();

			printArray(sortedArray, sizeForInsertionSort + 1);

			time_spent += (float)(end - begin) / CLOCKS_PER_SEC;
			printf("Time elpased is %f seconds", time_spent);

			free(sortedArray);
		}

		if (choise == 2)
		{
			float time_spent = 0.0;

			clock_t begin = clock();

			printf("Sorting... \n");

			List* list = createLinkedList();

			//Insert nodes into the list.
			for (int i = 1; i <= data[0]; i++)
			{
				Node* node1 = (Node*)malloc(sizeof(Node));
				if (node1 != NULL) {
					node1->data = data[i];
					insert(list, node1);
				}
			}

			//Merge sort
			mergeSort(list);
			clock_t end = clock();
			time_spent += (float)(end - begin) / CLOCKS_PER_SEC;
			printList(list->head);
			printf("Time elpased is %f seconds", time_spent);

			free(list);
		}

		if (choise == 3) {
			printf("Mergesort on L1 \n");
			List* L1 = createLinkedList();
			insertIntoL1Test(L1);
			exercise5WithListMerge1(L1);
			printList(L1->head);
			free(L1);
		}

		if (choise == 4) {
			printf("Mergesort on L2 \n");
			List* L2 = createLinkedList();
			insertIntoL2Test(L2);
			exercise5WithListMerge1(L2);
			printList(L2->head);
			free(L2);
		}

		if (choise == 5) 
		{
			exercise5WithInsertionSort1();
		}

		if(choise == 6) 
		{
			exercise5WithInsertionSort2();
		}

		if (choise == 7) {
			exercise5PersonalNumberForInsertionSort();
		}

		if (choise == 8) {
			exercise5PersonalNumberForMergeSort();
		}

		if(choise > 8) {
			printf("No such choise exist.");
		}
		
	}

	return 0;
}



