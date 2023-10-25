#include<iostream>
using namespace std;

int queueSize = 10;
int *DATA;
int front = -1, rear = -1;

// enque, deque

// A queue
// FIFO (First in first out)
// front & rear are our pointers

// assuming zero is 
// not availability of data


// enque ops
// [0, 0, 0, 0, 0] <- item(2) will enter 
// [2, 0, 0, 0, 0]
// front = 0, rear = 0
// [2, 1, 4, 0, 0]
// front = 0, rear = 2

// deque ops
// [2, 1, 4, 0, 0] <- on deque
// front = front + 1 = 1
// rear = 2


void enque(int value){
    if (rear >= queueSize-1){
        cout << "\nQueue Overflow\n";
        return;
    }
    if (front==rear && front == -1){
        ++front;
        ++rear;
        DATA[rear] = value;
        return;
    }
    ++rear;
    DATA[rear] = value;
    // cout << "Front (bye): " << front << endl;
    // cout << "Rear (bye): " << rear << endl;
    return;
}

int deque(){
    if (front <= -1 || front > rear){
        cout << "\nQueue Underflow\n";
        return 0;
    }
    int tmp = DATA[front];
    front++;
    return tmp;
}


void printArray(int *arr, int arrSize){
    cout << "[";
    for(int i=front; i<rear+1; i++)
        cout << " " << arr[i] << (i!=rear?", ":" ");
    cout << "]" << endl;
}

void showQueue(){
    printArray(DATA, queueSize);
}

void refreshQueue(){
    front = -1;
    rear = -1;
}

int main(){

    cout << "Enter the length of the queue: ";
    cin >> queueSize;
    cout << endl;
    
    DATA = new int(queueSize);
    int option, value, output;

    while(true){
        cout << "\n1. Enque a value\n";
        cout << "2. Deque a value\n";
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
                enque(value);
                break;
            case 2:
                cout << "\n\tDequeing front value\n";
                output = deque();
                cout << "\n\tDequed front value: " << output << endl;
                break;
            case 3:
                cout << "\nShowing queue\n";
                showQueue();
                break;
            case 4:
                cout << "\nRefreshing queue\n";
                refreshQueue();
                break;
            case 5:
                exit(0);
        }
    }

    // show options
    // check selected option
    // perform operation
    // show output
    // give gap
    // repeat

    return 0;
}