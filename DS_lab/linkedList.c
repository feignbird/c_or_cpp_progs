#include"linkedList.h"
#include <stdio.h>
#include <stdlib.h>

// basic operations of linkedlist
// readAt(HEAD, index) - read a value at given index & return a value
// getNodeAt(HEAD, index) - read a node at given index & return that node
// writeAt(HEAD, index, value) - write a value at given index

// insertNodeAt(*HEAD, node, index) - insert a node at given index
// insertAt(*HEAD, value, index) - create a new node & set the input value at that node & insert that node at given index
    // getNode(value[optional]|default = 0) - create the node by checking the size & allocating that much heap memory dynamically & then type casting it to Node type & assigning the necessary values
// deleteAt(*HEAD, index) - delete a node at given index
// createLinkedList(*arr, size) - returns the HEAD node index
// printLL(*HEAD) - prints the linked list


void printNode(Node node)
{
    printf("\nNode value:(%d) link:(%x)\n", node->key, node->link);
}


Node getNode(int value){
    Node newNode = (Node)malloc(sizeof(struct LinkedNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = value;
    return newNode;
}

int readAt(Node HEAD, int index){
    Node tmpNode = HEAD;
    int data = 0;
    int count = 0;
    while(tmpNode!=NULL){
        if (index == count++) data = tmpNode->key;
        tmpNode = tmpNode->link;
    }
    return data;
}

Node getNodeAt(Node HEAD, int index){
    Node tmpNode = HEAD;
    int count = 0;
    while(tmpNode!=NULL){
        if (index == count++) break;
        tmpNode = tmpNode->link;
    }
    return tmpNode;
}

void writeAt(Node HEAD, int index, int value){
    Node tmpNode = HEAD;
    int count = 0;
    while(tmpNode!=NULL){
        if (index == count++) {
            tmpNode->key = value; 
            break;
        }
        tmpNode = tmpNode->link;
    }
    return;
}


void insertNodeAt(Node *HEAD, Node node, int index){
    Node tmpNode = (*HEAD);
    int count = 0;
    if (index == 0){
        node->link = tmpNode;
        HEAD = &node;
        return;
    }
    Node prevNode=NULL, nextNode=NULL;
    while(tmpNode->link!=NULL){
        if (index-1 == count++)
            prevNode = tmpNode;
        if (index == count++){
            nextNode = tmpNode;
            break;
        }
        tmpNode = tmpNode->link;
    }
    if (prevNode != NULL)
        prevNode->link = node;
    else 
        tmpNode->link = node;
    node->link = nextNode;
    return;
}

void insertAt(Node *HEAD, int value, int index){
    Node tmpNode = (*HEAD);
    int count = 0;
    Node node = getNode(value);
    if (index == 0 || *HEAD == NULL){
        node->link = tmpNode;
        *HEAD = node;
        return;
    }

    Node prevNode=NULL, nextNode=NULL;

    while(tmpNode != NULL && tmpNode->link!=NULL){
        if (index-1 == count)
            prevNode = tmpNode;
        else if (index == count){
            nextNode = tmpNode;
            break;
        }
        tmpNode = tmpNode->link;
        count++;
    }

    if (prevNode != NULL)
        prevNode->link = node;
    else if (tmpNode != NULL)
        tmpNode->link = node;
        
    node->link = nextNode;
    return;
}

void deleteAt(Node *HEAD, int index){
    Node tmpNode = (*HEAD);
    int count = 0;
    if(index == 0){
        Node newHead = tmpNode->link;
        tmpNode->link = NULL;
        free(tmpNode);
        *HEAD = newHead;
        return;
    }

    Node prevNode = NULL;
    Node deleteNode = NULL;

    while(tmpNode!=NULL){
        if (index-1 == count)
            prevNode = tmpNode;
        if (index == count){
            deleteNode = tmpNode;
            break;
        }
        tmpNode = tmpNode->link;
        count++;
    }

    if(prevNode == NULL && deleteNode == NULL) return;

    if (deleteNode != NULL){ 
        Node nextNode = deleteNode->link;
        prevNode->link = nextNode;
        free(deleteNode);
        return;
    }
    return;
}

Node createLinkedList(int *arr, int size){
    Node nodes[size];
    for(int i=0; i<size; i++){
        nodes[i] = getNode(arr[i]);
    }
    for(int i=0; i<size-1; i++){
        nodes[i]->link = nodes[i+1];
    }
    return nodes[0];
}


void printLL(Node headNode)
{
    Node tmp = headNode;
    printf("\n");
    while (tmp != NULL)
    {
        printf("%d --> ", tmp->key);
        tmp = tmp->link;
    }
    printf("NULL\n");
}

/*
int main()
{
    Node HEAD = NULL;


    int arr[] = {2, 53, 82, 81, 7, 11};
    int sizeOfArr = sizeof(arr)/sizeof(arr[0]);
    
    printf("\nSize of Arr: %d\n", sizeOfArr);

    HEAD = createLinkedList(arr, sizeOfArr);

    printf("\nHEAD: %x\n", HEAD);

    // Initial linked list
    printf("\nInitial LL: ");
    printLL(HEAD);

    // Insertion at start
    insertAt(&HEAD, 12, 0);
    printf("\nLL (After insertion at start): ");
    printLL(HEAD);

    // Insertion in between
    insertAt(&HEAD, 22, 3);
    printf("\nLL (After insertion in between): ");
    printLL(HEAD);

    // Insertion in end
    insertAt(&HEAD, 92, -1);
    printf("\nLL (After insertion at end): ");
    printLL(HEAD);

    // reading at 2 index
    printf("\nReading at index 2: %d\n", readAt(HEAD, 2));

    // writing 123 at 4 index
    printf("\nWriting 123 at index 4: ");
    writeAt(HEAD, 4, 123);
    printLL(HEAD);

    // Delete at index 0
    printf("\nDeleting at index 0: ");
    deleteAt(&HEAD, 0);
    printLL(HEAD);

    // Delete at index 3
    printf("\nDeleting at index 3: ");
    deleteAt(&HEAD, 3);
    printLL(HEAD);

    // Delete at index 3
    printf("\nDeleting at index 3: ");
    deleteAt(&HEAD, 3);
    printLL(HEAD);
    return 0;
}
*/