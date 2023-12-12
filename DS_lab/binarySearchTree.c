#include<stdio.h>
#include<stdlib.h>
#include"binarySearchTree.h"

// leftChild < parentNode
// parentNode <= rightChild

BSTNode getBSTNode(int value, BSTNode parentnode, BSTNode leftnode, BSTNode rightnode){
    BSTNode newnode = (BSTNode)malloc(sizeof(struct BinarySearchTree));
    if (newnode == NULL){
        printf("Memory allocation failed.");
        exit(0);
    }
    newnode->key = value;
    newnode->parent = parentnode;
    newnode->leftChild = leftnode;
    newnode->rightChild = rightnode;
    return newnode;
}

void insert(BSTNode *root, int value){
    BSTNode tmpNode = *root;
    BSTNode parentTmpNode = NULL;
    while(tmpNode!=NULL){
        parentTmpNode = tmpNode;
        if (value < tmpNode->key)
            tmpNode = tmpNode->leftChild;
        else
            tmpNode = tmpNode->rightChild;
    }
    if (value < parentTmpNode->key)
        parentTmpNode->leftChild = getBSTNode(value, parentTmpNode, NULL, NULL);
    else 
        parentTmpNode->rightChild = getBSTNode(value, parentTmpNode, NULL, NULL);
}

BSTNode createBSTFromArr(int *arr, int arrSize){
    BSTNode rootNode = getBSTNode(arr[0], NULL, NULL, NULL);
    for(int i=1; i<arrSize; i++) insert(&rootNode, arr[i]);
    return rootNode;
}



int any(BSTNode *root, int arrSize){
    for (int i = 0; i<arrSize; i++)
        if (root[i] != 0 && root[i] != NULL)
            return 1;
    return 0;
}

void printBST(BSTNode *root, int arrSize){
    if (any(root, arrSize) == 1){
        int nextLevelSize = arrSize*2;
        BSTNode *nextLevel = (BSTNode*)calloc(nextLevelSize, sizeof(BSTNode));
        BSTNode leftChild, rightChild;
        printf("\n");
        for(int i=0; i<arrSize; i++){
            if (root[i]==NULL){
                printf(" N "); // Denoting NULL as N
                continue;
            }
            printf(" %d ", root[i]->key);
            leftChild = root[i]->leftChild;
            rightChild = root[i]->rightChild;
            if (leftChild!=NULL){
                nextLevel[2*i] = leftChild;
            } else {
                nextLevel[2*i] = NULL;
            }
            if (rightChild!=NULL){
                nextLevel[2*i+1] = rightChild;
            } else {
                nextLevel[2*i+1] = NULL;
            }
        }
        printBST(nextLevel, nextLevelSize);
    }
}

BSTNode treeMinimum(BSTNode q){
    if (q==NULL){
        return NULL;
    } else {
        while(q->leftChild!=NULL)
            q = q->leftChild;
        return q;
    }
}

BSTNode treeSuccessor(BSTNode p){
    BSTNode y = NULL;
    if (p->rightChild != NULL)
        return treeMinimum(p->rightChild);
    y = p->parent;
    while(y!=NULL && p==y->rightChild){
        p = y;
        y = y->parent;
    }
    return y;
}

BSTNode deleteBSTNode(BSTNode *root, int value){
    BSTNode tmpNode = *root;
    BSTNode parentTmpNode = NULL;
    while(tmpNode != NULL && tmpNode->key != value ){
        parentTmpNode = tmpNode;
        if (value < tmpNode->key) tmpNode = tmpNode->leftChild;
        else tmpNode = tmpNode->rightChild;
    }
    if (tmpNode == NULL){
        printf("\nNo key found.\n");
        return NULL;
    }
    BSTNode y = NULL;
    BSTNode x = NULL;
    if (tmpNode->leftChild == NULL || tmpNode->rightChild == NULL)
        y = tmpNode;
    else
        y = treeSuccessor(tmpNode);

    if(y->leftChild == NULL)
        x = y->rightChild;
    else 
        x = y->leftChild;

    if (x!=NULL)
        x->parent = y->parent;

    if (y->parent == NULL){
        *root = x;
    }
    else {
        if (y==(y->parent)->leftChild)
            y->parent->leftChild = x;
        else
            y->parent->rightChild = x;
    }

    if (y!=tmpNode)
        tmpNode->key = y->key;

    return y;
}

/*
int main(){
    int arr[] = { 5, 4, 2, 11, 6, 7, 28, 9};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("\narr (address): %x\n", arr);
    printf("\narrSize: %d\n", arrSize);
    BSTNode root = createBSTFromArr(arr, arrSize);
    printf("\nroot: %x | key: %d\n", root, root->key);
    BSTNode bstArr[] = { root };
    printBST(bstArr, 1);

    printf("\n\nDeleting 1");
    deleteBSTNode(&root, 2);
    printBST(bstArr, 1);
    
    printf("\n\nDeleting 7");
    deleteBSTNode(&root, 7);
    printBST(bstArr, 1);

    printf("\n\nDeleting 11");
    deleteBSTNode(&root, 11);
    printBST(bstArr, 1);
    return 0;
}
*/