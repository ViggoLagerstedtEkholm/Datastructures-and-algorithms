#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"

//This method creates a new node with a key value.
//This is used when we want to create a node with a key value.
TreeNode* createTreeNode(int key) {
    TreeNode* newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newTreeNode != NULL) {
        newTreeNode->key = key;
        newTreeNode->left = NULL;
        newTreeNode->right = NULL;
        newTreeNode->type = INT_TYPE;
    }
    return newTreeNode;
}
//This method takes the root and the node it should search for as the argument and then it recursively search the tree.
TreeNode* search(TreeNode* treeNode, TreeNode* searchNode) {
    if (treeNode == NULL || compareNodeEqual(treeNode, searchNode) == 1)
        return treeNode;
    if (compareNodeBiggerThen(treeNode, searchNode) == 1)
        return search(treeNode->left, searchNode);
    else
        return search(treeNode->right, searchNode);
}
//A recursive function that prints all the values of all the treeNodes in a tree in order.
void inOrderTreeWalk(TreeNode* treeNode) {
    if (treeNode != NULL) {
        inOrderTreeWalk(treeNode->left);
        if (treeNode != NULL) {
            if (treeNode->type == CHAR_TYPE) {
                if (checkTypeNow(treeNode) == 1)
                    printf("%c", treeNode->key);
            }
            else
                printf("%d", treeNode->key);
        }
        printf("\n");

        inOrderTreeWalk(treeNode->right);
    }
}
//This function uses a while loop to finds the value that exists to the the left most side in the tree which equals the minimum value in a give tree.
TreeNode* minimum(TreeNode* treeNode) {
    while (treeNode->left != NULL) {
        treeNode = treeNode->left;
    }
    return treeNode;
}
//This function uses a while loop to finds the value that exists to the the right most side in the tree which equals the maximum value in a give tree 
TreeNode* maximum(TreeNode* treeNode) {

    while (treeNode->right != NULL) {
        treeNode = treeNode->right;
    }
    return treeNode;
}

//Finds the successor of a tree node.
//The method uses the minimum method as a subroutine.
TreeNode* successor(TreeNode* treeNode) {
    if (treeNode->right != NULL)
        return minimum(treeNode->right);

    TreeNode* prevNode = treeNode->parent;

    while (prevNode != NULL && treeNode == prevNode->right) {
        treeNode = prevNode;
        prevNode = prevNode->parent;
    }
    return prevNode;
}

//Finds the predecessor of a tree node.
//The method uses the maximum method as a subroutine.
TreeNode* predecessor(TreeNode* treeNode) {
    if (treeNode->left != NULL)
        return maximum(treeNode->left);

    TreeNode* prevNode = treeNode->parent;

    while (prevNode != NULL && treeNode == prevNode->left) {
        treeNode = prevNode;
        prevNode = prevNode->parent;
    }
    return prevNode;
}

//Inserts a tree node into the binary tree.
int insert(Tree* source, TreeNode* insertedTreeNode) {
    TreeNode* x = source->root;
    TreeNode* y = NULL;
    source->size++;
    while (x != NULL) {
        y = x;
        if (compareNodeBiggerThen(x, insertedTreeNode) == 1)
            x = x->left;
        else
            x = x->right;
    }
    insertedTreeNode->parent = y;
    if (y == NULL) {
        source->root = insertedTreeNode;
        return 1;
    }
    else if (compareNodeBiggerThen(y, insertedTreeNode) == 1) {
        y->left = insertedTreeNode;
        return 1;
    }
    else {
        y->right = insertedTreeNode;
        return 1;
    }

    return 0;
}

//This method rearrange the pointers whenever we remove a node.
void transplant(Tree* tree, TreeNode* subtreeRootU, TreeNode* subtreeRootV) {
    if (subtreeRootU->parent == NULL)
        tree->root = subtreeRootV;
    else if (subtreeRootU == subtreeRootU->parent->left)
        subtreeRootU->parent->left = subtreeRootV;
    else
        subtreeRootU->parent->right = subtreeRootV;
    if (subtreeRootV != NULL)
        subtreeRootV->parent = subtreeRootU->parent;
}

//This method removes a node from the binary tree, we have 3 cases (no child node, 1 child node, 2 children nodes).
TreeNode* deleteNode(Tree* tree, TreeNode* deletedTreeNode) {
    assert(deletedTreeNode);
    tree->size--;
    if (deletedTreeNode->left == NULL)
        transplant(tree, deletedTreeNode, deletedTreeNode->right);

    else if (deletedTreeNode->right == NULL)
        transplant(tree, deletedTreeNode, deletedTreeNode->left);
    else {
        TreeNode* y = minimum(deletedTreeNode->right);
        if (y->parent != deletedTreeNode) {
            transplant(tree, y, y->right);
            y->right = deletedTreeNode->right;
            y->right->parent = y;
        }
        transplant(tree, deletedTreeNode, y);
        y->left = deletedTreeNode->left;
        y->left->parent = y;
    }
    return deletedTreeNode;
}

//This method creates a binary tree.
Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    assert(tree != NULL);
    tree->root = NULL;
    tree->size = 0;
    if (tree->root != NULL) {
        tree->root->left = NULL;
        tree->root->right = NULL;
    }
    return tree;
}

//This method calculates the depth of the binary tree.
int getDepth(TreeNode* source)
{
    int i = 1;
    if (source == NULL)
        return -1;
    else
    {
        int leftSideOfTree = getDepth(source->left);
        int rightSideOfTree = getDepth(source->right);
        if (leftSideOfTree > rightSideOfTree)
        {
            return leftSideOfTree + i;
        }
        else
        {
            return rightSideOfTree + i;
        }
    }
}

//This method calculates the size of the binary tree.
int getSize(TreeNode* source)
{
    int i = 1;
    if (source == NULL) {
        return 0;
    }
    else {
        return (i + (getSize(source->right) + getSize(source->left)));
    }
}

//This method compares 2 node values and returns 1 if a->key > b->key
int compareNodeBiggerThen(TreeNode* a, TreeNode* b) {
    if (a->key > b->key)
        return 1;
    else
        return 0;
}

//This method compares 2 node values and returns 1 if a->key == b->key
int compareNodeEqual(TreeNode* a, TreeNode* b) {
    if (a->key == b->key)
        return 1;
    else
        return 0;
}

//Creates a node with char key value.
TreeNode* createTreeNodeChar(char key) {
    TreeNode* newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newTreeNode != NULL) {
        newTreeNode->key = key;
        newTreeNode->left = NULL;
        newTreeNode->right = NULL;
        newTreeNode->type = CHAR_TYPE;
    }
    return newTreeNode;
}

//This method checks if node type is CHAR_TYPE.
int checkTypeNow(TreeNode* node) {
    if (node->type == CHAR_TYPE)
        return 1;
    else
        return 0;
}


