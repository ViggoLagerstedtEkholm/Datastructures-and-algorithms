#pragma once
#include "tree.h"

void insertTestDataChar(Tree* tree);
void insertTestData(Tree* tree);
void insertTest(Tree* tree, TreeNode* input);
void searchTest(TreeNode* root, TreeNode* input);
void minimumTest(TreeNode* root);
void maximumTest(TreeNode* root);
void successorTest(TreeNode* node, TreeNode* input);
void predecessorTest(TreeNode* node, TreeNode* input);
void deleteTest(Tree*, TreeNode*, TreeNode* input);
void depthAndSizeTest(Tree* tree);