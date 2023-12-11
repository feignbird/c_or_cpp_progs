#include<stdio.h>
#include<stdlib.h>

struct BinaryTreeNode {
    int key;
    struct BinaryTreeNode *leftChild;
    struct BinaryTreeNode *rightChild;
};

typedef struct BinaryTreeNode* BTNode;

// getBTNode(int value) - creates a binary tree node 
// createBinaryTree(int *arr) - creates a almost complete binary tree

BTNode getBTNode(int value, BTNode leftChild, BTNode rightChild){
    BTNode newNode = (BTNode)malloc(sizeof(struct BinaryTreeNode));
    if (newNode == NULL){
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = value;
    newNode->leftChild = leftChild;
    newNode->rightChild = rightChild;
    return newNode;
}

BTNode createBinaryTree(int *arr, int arrSize){
    arrSize = abs(arrSize);
    BTNode btArr[arrSize];
    int leftChildIndex, rightChildIndex;

    for(int i=0; i<arrSize; i++)
        btArr[i] = getBTNode(arr[i], NULL, NULL);

    for(int i=0; i<arrSize; i++){
        leftChildIndex = 2*i+1;
        rightChildIndex = 2*i+2;
        if (leftChildIndex <= arrSize - 1){
            btArr[i]->leftChild = btArr[leftChildIndex];
        }
        if (rightChildIndex <= arrSize - 1){
            btArr[i]->rightChild = btArr[rightChildIndex];
        }
        // printf("\nKey: %d\n", btArr[i]->key);
    }
    return btArr[0];
}

void printBT(BTNode *root, int arrSize){
    if (root[0] != 0 && root[0] != NULL){
        int nextLevelSize = arrSize*2;
        BTNode *nextLevel = (BTNode*)calloc(nextLevelSize, sizeof(BTNode));
        BTNode leftChild, rightChild;
        printf("\n");
        for(int i=0; i<arrSize; i++){
            if (root[i]==NULL) continue;
            printf("  %d  ", root[i]->key);
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
        printBT(nextLevel, nextLevelSize);
    }
}

int main(){
    int arr[] = {2, 7, 32, 11, 28, 15, 84, 13, 67, 76, 234, 919, 828, 9173, 82, 71};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("\narr: %x \n", arr);
    printf("\narrSize: %d \n", arrSize);
    BTNode root = NULL;
    root = createBinaryTree(arr, arrSize);
    printf("\nroot: %x | key: %d\n", root, root->key);
    BTNode rootArr[]={ root };
    printBT(rootArr, 1);
    return 0;
}