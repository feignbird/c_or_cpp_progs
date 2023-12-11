#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"

// push - insertAt node at zero index
// pop - get value of node at index 0 & delete that node
// isEmpty - check if HEAD is NULL

int isEmpty(Node HEAD){
    return HEAD == NULL;
}

void push(Node *HEAD, int value){
    insertAt(HEAD, value, 0);
}

int pop(Node *HEAD){
    if (isEmpty(*HEAD)){
        printf("\nStack is Empty!\n");
        return -1;
    }
    int val = readAt(*HEAD, 0);
    deleteAt(HEAD, 0);
    return val;
}

void display(Node *HEAD){
    while(isEmpty(*HEAD)!=1 && *HEAD != NULL){
        printf("%d <-- ", pop(HEAD));
    }
}


int main(){
    Node HEAD = NULL;

    int option, value, output;
    while(1){
        printf(
        "\n1. push a value\n"
        "2. pop a value\n"
        "3. Display stack (NOTE: Stack can become empty)\n"
        "4. exit the program\n"
        "\tChoose an option: "
        );
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("\n\tEnter a value to push: ");
                scanf("%d", &value);
                printf("\n");
                push(&HEAD, value);
                break;
            case 2:
                printf("\n\tPopping front value\n");
                output = pop(&HEAD);
                printf("\n\tPopped front value: %d \n", output);
                break;
            case 3:
                printf("\nDisplaying stack\n");
                display(&HEAD);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}