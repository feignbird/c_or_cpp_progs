#include<stdio.h>
#include<stdlib.h>

// leftChild < parentNode
// parentNode <= rightChild

struct BinarySearchTree {
    int key;
    struct BinarySearchTree *leftChild;
    struct BinarySearchTree *rightChild;
    struct BinarySearchTree *parent;
};

typedef struct BinarySearchTree* BSTNode;



// createBSTFromArr(int *arr)

// getBSTNode(int value, leftnode, rightnode)
BSTNode getBSTNode(int value, BSTNode parentnode, BSTNode leftnode, BSTNode rightnode){
    BSTNode newnode = (BSTNode)malloc(sizeof(struct BinarySearchTree));
    if (newnode == NULL){
        printf("Memory allocation failed.");
        exit(0);
    }
    newnode->key = value;
    newnode->leftChild = leftnode;
    newnode->rightChild = rightnode;
    newnode->parent = parentnode;
    return newnode;
}


// insert(int value)
void insert(BSTNode *root, int value){
    // printf("\nInserted  : %d \n", value);
    BSTNode tmpNode = *root;
    BSTNode parentTmpNode = NULL;
    while(tmpNode!=NULL){
        // printf("\n\tvalue: %d | Updated tmpNode key  : %d\n", value, tmpNode->key);
        parentTmpNode = tmpNode;
        if (value < tmpNode->key)
            tmpNode = tmpNode->leftChild;
        else
            tmpNode = tmpNode->rightChild;
    }
    // printf("\nparentTmpNode: %x | key: %d\n", parentTmpNode, parentTmpNode->key);
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


BSTNode treeSuccessor(int value){
    BSTNode y = NULL;
    // if ()
}

void deleteBSTNode(BSTNode *root, int value){
    BSTNode tmpNode = *root;
    BSTNode parentTmpNode = NULL;
    while(tmpNode != NULL && tmpNode->key != value ){
        parentTmpNode = tmpNode;
        if (value < tmpNode->key) tmpNode = tmpNode->leftChild;
        else tmpNode = tmpNode->rightChild;
    }
    if (tmpNode == NULL){
        printf("\nNo key found.\n");
    } else if (tmpNode->leftChild == NULL && tmpNode->rightChild == NULL){
        if (tmpNode->key < parentTmpNode->key){
            parentTmpNode->leftChild = NULL;
            free(tmpNode);
        } else {
            parentTmpNode->rightChild = NULL;
            free(tmpNode);
        }
    } else if ((tmpNode->leftChild != NULL && tmpNode->rightChild == NULL)){
        if (tmpNode->key < parentTmpNode->key){
            parentTmpNode->leftChild = tmpNode->leftChild;
            free(tmpNode);
        } else {
            parentTmpNode->rightChild = tmpNode->leftChild;
            free(tmpNode);
        }
    } else if (tmpNode->leftChild == NULL && tmpNode->rightChild != NULL) {
        if (tmpNode->key < parentTmpNode->key){
            parentTmpNode->leftChild = tmpNode->rightChild;
            free(tmpNode);
        } else {
            parentTmpNode->rightChild = tmpNode->rightChild;
            free(tmpNode);
        }
    } else if (tmpNode->leftChild != NULL && tmpNode->rightChild != NULL){

    }
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

// delete 
    // if no child
    // if one child
    // if two child

// Display 
    // make a display function to display at every level till you find 
    // an array such that every element on that level hasn't become NULL.


int main(){
    int arr[] = { 5, 4, 2, 1, 6, 7, 8, 9};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("\narr: %x\n", arr);
    printf("\narrSize: %d\n", arrSize);
    BSTNode root = createBSTFromArr(arr, arrSize);
    printf("\nroot: %x | key: %d\n", root, root->key);
    BSTNode bstArr[] = { root };
    printBST(bstArr, 1);
    return 0;
}