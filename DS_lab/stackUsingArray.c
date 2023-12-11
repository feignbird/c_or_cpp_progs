// Write a program in C to stack data structure along with its operation using arrays.

#include<stdio.h>
#include<stdlib.h>

int stackSize = 10;
int *STACK = NULL;
int TOP = -1;

// push
// pop
// isFull
// isEmpty

int isFull(){
    return TOP >= stackSize - 1;
}

int isEmpty(){
    return TOP <= -1;
}

void refreshStack(){
    TOP = -1;
}

int pop(){
    if(isEmpty()){
        printf("\nStack is Empty.\n");
        return -1;
    }
    return STACK[TOP--];
}

void push(int value){
    if(isFull()){
        printf("\nStack is Full.\n");
        return;
    }
    TOP++;
    STACK[TOP] = value;
}

void display(){
    while(isEmpty()!=1 && TOP > -1){
        printf(" %d <-- ", pop());
    }
}


int main(){
    printf("Enter the size of the stack: ");
    scanf("%d", &stackSize);
    
    STACK = (int*)calloc(stackSize, sizeof(int));

    int option, value, output;

    while(1){
        printf(
        "\n\n\n1. push a value\n"
        "2. pop a value\n"
        "3. Display stack (NOTE: stack can become empty)\n"
        "4. Refresh stack\n"
        "5. exit the program\n"
        "\tChoose an option: "
        );
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("\n\tEnter a value to push: ");
                scanf("%d", &value);
                printf("\n");
                push(value);
                break;
            case 2:
                printf("\n\tPopped last value\n");
                output = pop();
                printf("\n\tPopped last value: %d \n", output);
                break;
            case 3:
                printf("\nDisplaying stack\n");
                display();
                break;
            case 4:
                printf("\nRefreshing stack\n");
                refreshStack();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}

