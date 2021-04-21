#include <stdlib.h>
#include <stdio.h>
#include "test.h"

// TestData

void insertTestData(Tree* tree) {

	TreeNode* a1 = createTreeNode(7);
	TreeNode* b1 = createTreeNode(8);
	TreeNode* c1 = createTreeNode(10);
	TreeNode* d1 = createTreeNode(5);
	TreeNode* e1 = createTreeNode(1);
	TreeNode* f1 = createTreeNode(3);

	insert(tree, e1);
	insert(tree, a1);
	insert(tree, b1);
	insert(tree, c1);
	insert(tree, d1);
	insert(tree, f1);
}

void insertTestDataChar(Tree* tree) {

	TreeNode* a1 = createTreeNodeChar('A');
	TreeNode* b1 = createTreeNodeChar('B');
	TreeNode* c1 = createTreeNodeChar('C');
	TreeNode* d1 = createTreeNodeChar('D');
	TreeNode* e1 = createTreeNodeChar('E');
	TreeNode* f1 = createTreeNodeChar('F');
	TreeNode* g1 = createTreeNodeChar('G');
	TreeNode* h1 = createTreeNodeChar('H');
	TreeNode* i1 = createTreeNodeChar('I');
	TreeNode* j1 = createTreeNodeChar('J');

	insert(tree, f1);
	insert(tree, c1);
	insert(tree, a1);
	insert(tree, e1);
	insert(tree, b1);
	insert(tree, d1);
	insert(tree, h1);
	insert(tree, j1);
	insert(tree, g1);
	insert(tree, i1);

}

void insertTest(Tree* tree, TreeNode* input) {
	int expectedValue = 1;
	int returnedValue = 0;
	TreeNode* node = NULL;

	node = createTreeNode(input->key);

	returnedValue = insert(tree, node);

	if (expectedValue != returnedValue) {
		printf("Test_failed:_");
		printf("insert()_returned_%d_(expected:_ %d)", returnedValue, expectedValue);
	}
}

void searchTest(TreeNode* root, TreeNode* input) {
	TreeNode* expectedValue = input;
	int returnedValue = 0;
	if (search(root, expectedValue) != NULL)
		returnedValue = search(root, expectedValue)->key;
	else
	{
		returnedValue = -1;
	}

	if (expectedValue->key != returnedValue) {
		printf("Test_failed:_");
		printf("search()_returned_%d_(expected:_ %d)", returnedValue, expectedValue->key);
	}
	else {
		printf("\n");
		printf("Test was a success \n");
	}
}

void minimumTest(TreeNode* root) {
	int returnedValue = 0;
	int expectedValue = 1;
	returnedValue = minimum(root)->key;
	if (expectedValue != returnedValue) {
		printf("Test_failed:_");
		printf("minimum()_returned_%d_(expected:_ %d)", returnedValue, expectedValue);
	}
	else {
		printf("Result: %d", returnedValue);
	}
}

void maximumTest(TreeNode* root) {
	int returnedValue = 0;
	int expectedValue = 10;
	returnedValue = maximum(root)->key;
	if (expectedValue != returnedValue) {
		printf("Test_failed:_");
		printf("minimum()_returned_%d_(expected:_ %d)", returnedValue, expectedValue);
	}
	else {
		printf("Result: %d", returnedValue);
	}
}

void successorTest(TreeNode* node, TreeNode* input) {
	int returnedValue = 0;
	int expectedValue = 7;
	if (search(node, input) != NULL) {
		TreeNode* testNode = search(node, input);
		returnedValue = successor(testNode)->key;

		if (expectedValue != returnedValue) {
			printf("Test_failed:_");
			printf("successor_returned_%d_(expected:_ %d)", returnedValue, expectedValue);
		}
		else {
			printf("Result %d", returnedValue);
		}
	}
	else {
		printf("The value you have entered does not have a successor or is not in the tree");
	}
}


void predecessorTest(TreeNode* node, TreeNode* input) {
	int returnedValue = 0;
	int expectedValue = 3;
	if (search(node, input) != NULL) {
		TreeNode* testNode = search(node, input);
		returnedValue = predecessor(testNode)->key;

		if (expectedValue != returnedValue) {
			printf("Test_failed:_");
			printf("predecessor_returned_%d_(expected:_ %d)", returnedValue, expectedValue);
		}
		else {
			printf("Result %d", returnedValue);
		}
	}
	else {
		printf("The value you have entered does not have a predecessor or is not in the tree");
	}
}

void deleteTest(Tree* tree, TreeNode* node, TreeNode* input) {
	int returnedValue = 0;
	int expectedValue = 0;
	if (input != NULL) {
		expectedValue = input->key;
	}
	printf("Nodes in the tree before delete \n");
	inOrderTreeWalk(tree->root);
	if (search(node, input) != NULL) {
		TreeNode* testNode = search(node, input);
		TreeNode* deletedNode = deleteNode(tree, testNode);
		returnedValue = deletedNode->key;
		free(deletedNode);
		if (expectedValue != returnedValue) {
			printf("Test_failed:_");
			printf("deleteNode_returned_%d_(expected:_ %d) \n", returnedValue, expectedValue);
		}
		else {
			printf("Nodes in the tree after delete \n");
		}
		inOrderTreeWalk(tree->root);
	}
	else{
		printf("The value you have enterd does not have a predecessor or is not in the tree");
	}
}

void depthAndSizeTest(Tree* tree) {
	int depth = getDepth(tree->root);
	int size = getSize(tree->root);

	printf("Size of the tree: ");
	printf("%d", size);
	printf("\n");
	printf("Depth of the tree: ");
	printf("%d", depth);
}

