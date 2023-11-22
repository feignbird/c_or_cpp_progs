#include<iostream>
#include"utils.hpp"
using namespace std;


struct CircularQueue {
    int size;
    int first=-1;
    int last=-1;
    int *arr;
};

typedef struct CircularQueue CqNode;

bool isQueueFull(CqNode *node){
    cout << "node->first: " << node->first << "\n";
    cout << "node->last: " << node->last << "\n";
    cout << "node->size: " << node->size << "\n";

    return (node->last-node->first + 1 == node->size || node->last == node->first-1);
}

bool isQueueEmpty(CqNode *node){
    return (node->last-node->first + 1 == 0 || (node->first==-1 && node->last==-1));
}

void enqueue(CqNode *node, int value){
    if (isQueueFull(node)){
        cout << "Queue is full, reset the queue or dequeue it." << "\n";
        return;
    }
    if (node->first == -1)
        ++node->first;
    ++node->last;
    node->arr[node->last % node->size] = value;
}

int dequeue(CqNode *node){
    if (isQueueEmpty(node)){
        cout << "Queue is empty, reset the queue or enqueue it." << "\n";
        return 0;
    }
    ++node->first; // Will goto infinity from -1 | Mod will put the limit & wrap
    return node->arr[(node->first % node->size)-1];
}

void showQueue(CqNode *node){
    printArray(node->arr, node->size);
}

void refreshQueue(CqNode *node){
    node->first = -1;
    node->last = -1;
}

int main(){

    int queueSize;
    cout << "Enter the length of the queue: ";
    cin >> queueSize;
    cout << endl;
    
    int DATA[queueSize];
    int option, value, output;

    CqNode *node1 = (CqNode*)malloc(sizeof(CqNode));
    node1->size = queueSize;
    node1->first = -1;
    node1->last = -1;
    node1->arr = DATA;

    while(true){
        cout << "\n1. Enqueue a value\n";
        cout << "2. Dequeue a value\n";
        cout << "3. Show queue\n";
        cout << "4. Refresh queue\n";
        cout << "5. exit the program\n";
        cout << "\tChoose an option: ";
        cin >> option;
        switch(option){
            case 1:
                cout << "\n\tEnter a value to enque: ";
                cin >> value;
                cout << endl;
                enqueue(node1, value);
                break;
            case 2:
                cout << "\n\tDequeing front value\n";
                output = dequeue(node1);
                cout << "\n\tDequed front value: " << output << endl;
                break;
            case 3:
                cout << "\nShowing queue\n";
                showQueue(node1);
                break;
            case 4:
                cout << "\nRefreshing queue\n";
                refreshQueue(node1);
                break;
            case 5:
                exit(0);
        }
    }

}

/*
    int arr[] = {12, 5, 33};
    CqNode *node1 = (CqNode*)malloc(sizeof(CqNode));
    node1->size = 3;
    node1->first = -1;
    node1->last = -1;
    node1->arr = arr;


    cout << "Intial array with random values: ";
    printArray(node1->arr, node1->size);
    cout << "\n";

    cout << "pushing 3, 4, 5 & 6 : \n";
    enqueue(node1, 3);
    enqueue(node1, 4);
    enqueue(node1, 5);

    cout << "After enqueing three items: ";
    printArray(node1->arr, node1->size);
    cout << "\n";
*/