#include"linkedList.h"
#include<stdio.h>
#include<stdlib.h>

// enqueue - adding a new node at the end
// dequeue - popping the starting node
// isEmpty - is queue is empty

void enqueue(Node *HEAD, int value){
    insertAt(HEAD, value, -1);
}

int isEmpty(Node HEAD){
    return HEAD == NULL;
}

int dequeue(Node *HEAD){
    if(isEmpty(*HEAD)){
        printf("\nQueue is empty!\n");
        return -1;
    }
    int val = readAt(*HEAD, 0);
    deleteAt(HEAD, 0);
    return val;
}


int main(){
    Node HEAD = NULL;

    int option, value, output;

    while(1){
        printf(
        "\n1. Enqueue a value\n"
        "2. Dequeue a value\n"
        "3. Display queue\n"
        "4. exit the program\n"
        "\tChoose an option: "
        );
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("\n\tEnter a value to enque: ");
                scanf("%d", &value);
                printf("\n");
                enqueue(&HEAD, value);
                break;
            case 2:
                printf("\n\tDequeing front value\n");
                output = dequeue(&HEAD);
                printf("\n\tDequeued front value: %d \n", output);
                break;
            case 3:
                printf("\nDisplaying queue\n");
                printLL(HEAD);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}