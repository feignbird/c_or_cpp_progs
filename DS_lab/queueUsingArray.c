#include<stdio.h>
#include<stdlib.h>

int queueSize = 10;
int *QUEUE;
int front = -1, rear = -1;

// prints the array [ a , b , c , ...]
void printArray(int *arr, int arrSize){
    printf("[");
    for(int i=0; i<arrSize; i++)
        printf(" %d %s", arr[i], (i!=arrSize-1?", ":" "));
    printf("]");
}

void enqueue(int value){
    if (rear >= queueSize-1){
        printf("\nQueue Overflow\n");
        return;
    }
    if (front==rear && front == -1){
        ++front;
        ++rear;
        QUEUE[rear] = value;
        return;
    }
    ++rear;
    QUEUE[rear] = value;
    return;
}

int dequeue(){
    if (front <= -1 || front > rear){
        printf("\nQueue Underflow\n");
        return 0;
    }
    int tmp = QUEUE[front];
    front++;
    return tmp;
}


void display(){
    printArray(QUEUE, queueSize);
}

void refreshQueue(){
    front = -1;
    rear = -1;
}

int main(){
    printf("Enter the length of the queue: ");
    scanf("%d", &queueSize);
    
    QUEUE = (int*)calloc(queueSize, sizeof(int));
    int option, value, output;

    while(1){
        printf(
        "\n\n\n1. Enque a value\n"
        "2. Deque a value\n"
        "3. Display queue\n"
        "4. Refresh queue\n"
        "5. exit the program\n"
        "\tChoose an option: "
        );
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("\n\tEnter a value to enque: ");
                scanf("%d", &value);
                printf("\n");
                enqueue(value);
                break;
            case 2:
                printf("\n\tDequeing front value\n");
                output = dequeue();
                printf("\n\tDequed front value: %d \n", output);
                break;
            case 3:
                printf("\nDisplaying queue\n");
                display();
                break;
            case 4:
                printf("\nRefreshing queue\n");
                refreshQueue();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}