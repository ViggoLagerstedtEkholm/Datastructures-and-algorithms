#pragma once
typedef enum {
    CHAR_TYPE,
    INT_TYPE

}DataType;

typedef struct Node_t {     // we define a treenode element
    //char key;
    int key;
    struct Node_t* parent;
    struct  Node_t* right;
    struct  Node_t* left;
    DataType type;

} TreeNode;


typedef struct tree_element_t { // we define our tree element
    int size;
    int depth;
    TreeNode* root;
} Tree;

int compareNodeBiggerThen(TreeNode* a, TreeNode* b);
int compareNodeEqual(TreeNode* a, TreeNode* b);
Tree* createTree();
int checkTypeNow(TreeNode* s);
TreeNode* createTreeNode(int key);
TreeNode* createTreeNodeChar(char key);
TreeNode* search(TreeNode* root, TreeNode* s);
int insert(Tree* source, TreeNode* insertedTreeNode);
TreeNode* deleteNode(Tree* tree, TreeNode* deletedTreeNode);
TreeNode* minimum(TreeNode* sourceNode);
TreeNode* maximum(TreeNode* sourceNode);
TreeNode* successor(TreeNode* treeNode);
TreeNode* predecessor(TreeNode* treeNode);
int getSize(TreeNode* source);
int getDepth(TreeNode* source);
void transplant(Tree* tree, TreeNode* subtreeRootU, TreeNode* subtreeRootV);
void inOrderTreeWalk(TreeNode* root);