#ifndef BST_H
#define BST_H

struct BinarySearchTree {
    int key;
    struct BinarySearchTree *leftChild;
    struct BinarySearchTree *rightChild;
    struct BinarySearchTree *parent;
};

typedef struct BinarySearchTree* BSTNode;


BSTNode getBSTNode(int value, BSTNode parentnode, BSTNode leftnode, BSTNode rightnode);
void insert(BSTNode *root, int value);
BSTNode createBSTFromArr(int *arr, int arrSize);
int any(BSTNode *root, int arrSize);
void printBST(BSTNode *root, int arrSize);
BSTNode treeMinimum(BSTNode q);
BSTNode treeSuccessor(BSTNode p);
BSTNode deleteBSTNode(BSTNode *root, int value);


#endif