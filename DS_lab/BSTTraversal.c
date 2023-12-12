#include<stdio.h>
#include<stdlib.h>
#include"binarySearchTree.h"


void preorder(BSTNode root){
    if(root != NULL){
        // ROOT -> L_subtree -> R_subtree
        printf(" %d ", root->key);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}

void inorder(BSTNode root){
    if(root!=NULL){
        // L_subtree -> ROOT -> R_subtree
        inorder(root->leftChild);
        printf(" %d ", root->key);
        inorder(root->rightChild);
    }
}

void postorder(BSTNode root){
    if(root!=NULL){
        // L_subtree -> R_subtree -> ROOT
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf(" %d ", root->key);
    }
}


int main(){
    int arr[] = {43, 82, 91, 62, 18, 75, 72, 1, 4, 81, 43, 29};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("\narr: %x", arr);
    printf("\narrSize: %d", arrSize);
    BSTNode root = createBSTFromArr(arr, arrSize);
    BSTNode bstarr[] = { root };
    printBST(bstarr, 1);

    printf("\n\nPreorder: ");
    preorder(root);

    printf("\n\nInorder: ");
    inorder(root);

    printf("\n\nPostorder: ");
    postorder(root);

    return 0;
}