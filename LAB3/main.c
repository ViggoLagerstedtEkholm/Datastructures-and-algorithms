#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "load_file.h"
#include "test.h"

int main(int argc, char* argv[]) {
	const char* fname = argv[1];
	//int* data = load_file(fname);

	Tree* binarySearchTree = createTree();

	//Insert test data into our BST.
	insertTestData(binarySearchTree);
	//insertTestDataChar(binarySearchTree);

	int choise = 0;
	int input;
	int keepOnGoing = 0;
	int notScannedArgument = 0;
	
	//This loop will insert all the values from the loaded data (test files) into our binary tree.
	
	/*
	for (int i = 1; i <= data[0]; i++)
	{
		TreeNode* node1 = createTreeNode(1);
		if (node1 != NULL) {
			node1->key = data[i];

			insert(binarySearchTree, node1);
		}
	}	
	*/

	inOrderTreeWalk(binarySearchTree->root);

	//This while loop will exit if the user inputs -1 and reiterate if 1 is entered. This enables the user to enter new options.
	
	
	while (keepOnGoing != -1 || keepOnGoing == 1) {
		keepOnGoing = 0;
		system("cls");
		printf("Which test would you like to peform \n");
		printf("Press 1. Insert a tree node \n");
		printf("Press 2. To search after a node \n");
		printf("Press 3. To see the minimum value for the test tree\n");
		printf("Press 4. To see the maximum value for the test tree\n");
		printf("Press 5. To see the successor for value 5 in the tree\n");
		printf("Press 6. To see the  predecessor for value 5 in the tree\n");
		printf("Press 7. To delete a node in the tree\n");
		printf("Press 8. See depth and size of the tree\n");
		printf("Press 9. print tree in order\n");
		printf("Press 10. for testA generictree\n");
		printf("Press 11. for testB generictree\n");
		printf("Press 12. for testC generictree\n");

		notScannedArgument = scanf_s("%d", &choise);

		if (notScannedArgument > 0)
		{
			switch (choise)
			{
				case 1:
					printf("Write a value \n");
					scanf_s("%d", &input);
					printf("\n");
					TreeNode* nodeG = createTreeNode(input);
					insertTest(binarySearchTree, nodeG);
					break;
				case 2:
					printf("Write a value \n");
					scanf_s("%d", &input);
					TreeNode* nodeA = createTreeNode(input);
					searchTest(binarySearchTree->root, nodeA);
					break;
				case 3:
					minimumTest(binarySearchTree->root);
					break;
				case 4:
					maximumTest(binarySearchTree->root);
					break;
				case 5:{
						TreeNode* nodeB = createTreeNode(5);
						successorTest(binarySearchTree->root, nodeB);
					}				
					break;
				case 6: {
						TreeNode* nodeC = createTreeNode(5);
						predecessorTest(binarySearchTree->root, nodeC);
					break;
				}
				case 7:
					printf("Write a value \n");
					scanf_s("%d", &input);
					TreeNode* nodeD = createTreeNode(input);
					deleteTest(binarySearchTree, binarySearchTree->root, nodeD);
					break;
				case 8:
					depthAndSizeTest(binarySearchTree);
					printf("\n");
					break;
				case 9:
					printf("\n");
					printf("The tree consist of these values \n");
					inOrderTreeWalk(binarySearchTree->root);
					break;
				case 10:
					printf("Before deleting the node with letter A \n");
					inOrderTreeWalk(binarySearchTree->root);
					TreeNode* testA = createTreeNodeChar('A');
					TreeNode* testNode = search(binarySearchTree->root, testA);
					TreeNode* deletedNode = deleteNode(binarySearchTree, testNode);
					free(deletedNode);
					printf("After deleting the node with letter A \n");
					inOrderTreeWalk(binarySearchTree->root);
					break;
				case 11:
				{
					TreeNode* testAForSuccessorChar = createTreeNodeChar('C');
					testAForSuccessorChar = search(binarySearchTree->root, testAForSuccessorChar);
					TreeNode* testNode = successor(testAForSuccessorChar);
					printf("Successor of C is \n");
					printf("%c", testNode->key);

					break;
				}
				case 12:
				{
					TreeNode* testAForMaxChar = maximum(binarySearchTree->root);
					printf("Maximum value is \n");
					printf("%c", testAForMaxChar->key);
					break;
				}
			}
		}

		while (keepOnGoing != 1 && keepOnGoing != -1) {
			printf("\n");
			printf("Keep on testing? \n");
			printf("Press  1 for YES\n");
			printf("Press -1 for NO \n");
			scanf_s("%d", &keepOnGoing);
		}
	}
	free(binarySearchTree);

	return 0;
}