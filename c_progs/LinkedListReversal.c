#include<stdio.h>


struct Node
{
    int data; // In databases, primary keys are mostly of integer type
    struct Node *link; // size of link will be decided by the compiler
};

typedef struct Node node;

node *HEAD;

node *getNode()
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\n\tEnter the integer data: ");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    return newnode;
}

node *getLinkedList(int len)
{
    node *tempNode = NULL;
    node *newNode = NULL;
    // creating a node, storing the address
    // and setting the value of stored address into next node created.
    node *arr[len];
    for (int i=0; i<len; i++){
        arr[i] = getNode();
    }
    /*
            newNode = getNode();
        newNode->link = tempNode;
        tempNode = newNode;
    */
    for (int i=0; i<len; i++){
        if (i == len - 1)
            arr[i]->link = NULL;
        arr[i]->link = arr[i+1];
        //printf("\t\tarr[%d]->data: %d\n",i, arr[i]->data);
    }
    return arr[0];
}

void printLinkedList(node *head)
{
    node *tempNode = head;
    printf("\n");
    while(tempNode!=NULL)
    {
        printf("%d -> ", tempNode->data);
        tempNode = tempNode->link;
    }
    printf("NULL\n");
}

int linkedListLength(node *head)
{
    int counter = 1;
    node *tempNode = head;
    while(tempNode->link!=NULL){
            counter++;
            tempNode = tempNode->link;
    }
    return counter;
}

void reverseLinkedList(node *head)
{
    node *tempNode = head;
    int linkedListLen = linkedListLength(head);
    int arr[linkedListLen];
    int i=0;
    while(tempNode!=NULL)
    {
        arr[i++]=tempNode->data;
        tempNode = tempNode->link;
    }
    tempNode = head;
    i = linkedListLen-1;
    while(tempNode!=NULL && i >= 0)
    {
        tempNode->data = arr[i--];
        tempNode = tempNode->link;
    }

}


int main()
{
    // node node1; // static allocation

    node *n;
    int option, len;

    while(1){
        printf("\n\t1. create a new node\n");
        printf("\t2. print node\n");
        printf("\t3. create a linkedList\n");
        printf("\t4. reverse the linked list if a linked list exist.\n");
        printf("\t5. print linked list if a linked list exist.\n");
        printf("\t6. exit the program\n");
        printf("\t\tChoose any option: ");
        scanf("%d", &option);
        switch(option){
        case 1:
            n = getNode();
            break;
        case 2:
            printf("\n\tNode data: %d - Node link: %x\n", n->data, n->link);
            break;
        case 3:
            printf("\n\tEnter the length of the linked list: ");
            scanf("%d", &len);
            printf("\n");
            HEAD = getLinkedList(len);
            printLinkedList(HEAD);
            break;
        case 4:
            reverseLinkedList(HEAD);
            printLinkedList(HEAD);
            break;
        case 5:
            printLinkedList(HEAD);
            break;
        case 6:
            printf("\nExiting program...:)");
            exit(0);
            break;
        }
    }

    return 0;
}
