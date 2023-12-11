#include <iostream>

using namespace std;

//###########################################################
// This Code is incomplete 
//#########################################################


// simple linked list
// For making the linked list,
// we need to make a structure which can support a int value & a pointer variable which will point to the next node
// then we need to make function for doing some actions
//  inserting at specified index if index not given then use the last tail address
//  deleting from specified index if index is not given then deleting the last tail addressed value
//  traversing & getting the node value at specified index if index not given then print out the whole list
//  traversing & setting value at specified index if index not given then give error to the user.

//       0                    1
// |val:5;link:0x1b| -> |val:7;link:NULL|
//       0x2c                  0x1b

struct LinkedNode
{                            // 16 bytes = 8 bytes + 8 bytes
    int key;               // 8 bytes
    struct LinkedNode *link; // 8 bytes
};

typedef (struct LinkedNode*) Node;

void printNode(Node node)
{
    printf("\nNode value:(%d) link:(%x)\n", node->key, node->link);
}

// basic operations of linkedlist
// readAt(HEAD, index) - read a value at given index & return a value
// getNodeAt(HEAD, index) - read a node at given index & return that node
// writeAt(HEAD, index, value) - write a value at given index

// insertNodeAt(*HEAD, node, index) - insert a node at given index
// insertAt(*HEAD, value, index) - create a new node & set the input value at that node & insert that node at given index
    // getNode(value[optional]|default = 0) - create the node by checking the size & allocating that much heap memory dynamically & then type casting it to Node type & assigning the necessary values
// deleteAt(*HEAD, index) - delete a node at given index
// createLinkedList(*arr, size) - returns the HEAD node index

Node getNode(int value = 0){
    Node newNode = (Node)malloc(sizeof(Node));
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


// 23 -> 43 -> 2 -> 32 -> Null
// 0     1     2    3
// Case 1:
    // insert node 3 at index 2 (at middle indexes)
    // 23    43    3    2     32    Null
// Case 2:
    // insert node 3 at index 0 (at start index)
    // 3     23   43    2     43    Null
// Case 3:
    // insert node 3 at index = 3 (at last index)
    // 23    43   2     3    32    Null
// Case 4:
    // insert node 3 at index > 3, let say (4)
    // 23    43   2     32   3 


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
    if (index == 0){
        node->link = tmpNode;
        *HEAD = node;
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

void deleteAt(Node *HEAD, int index){
    Node tmpNode = (*HEAD);
    int count = 0;
    if(index == 0){
        Node newHead = NULL;
        newHead = tmpNode->link;
        free(tmpNode);
        *HEAD = newHead;
    }
    Node prevNode=NULL, deleteNode = NULL;
    while(tmpNode->link!=NULL){
        if (index-1 == count++)
            prevNode = tmpNode;
        else if (index == count++){
            deleteNode = tmpNode;
            break;
        }
            // 3 -> 1 -> 91 -> 45 -> 23 -> NULL 
            // deleteAt(2)
            // 3 -> 1 -> 45 -> 23 -> NULL // 91 delete
    }
    if (deleteNode != NULL){
        Node nextNode = deleteNode->link;
        prevNode->link = nextNode;
        free(deleteNode);
        return;
    }
    return;
}

Node createLinkedList(int *arr, int size){
    Node nodes[];
    for(int i=0; i<size; i++){
        nodes[i] = getNode();
    }
    for(int i=0; i<size-1; i++){
        nodes[i+1]->link = nodes[i];
    }
    return nodes[0]
}


struct LinkedNode *createNodes(int numberOfNodes)
{
    numberOfNodes = abs(numberOfNodes);
    printf("Inside createNodes function ....\n");
    printf("numberOfNodes: %d\n", numberOfNodes);
    struct LinkedNode *tmpNodePointer;
    printf("\nsizeof struct LinkedNode: %d\n", sizeof(struct LinkedNode));
    tmpNodePointer = NULL;

    while (numberOfNodes > 0)
    {
        printf("numberOfNodes: %d\n", numberOfNodes);
        struct LinkedNode *newNode = (struct LinkedNode *)malloc(sizeof(struct LinkedNode));
        newNode->value = 0;
        newNode->link = tmpNodePointer;
        tmpNodePointer = newNode;
        numberOfNodes--;
    }
    return tmpNodePointer;
}

struct LinkedNode *createNodePointer(int value, struct LinkedNode *node)
{
    struct LinkedNode *newNode = (struct LinkedNode *)malloc(sizeof(struct LinkedNode));
    newNode->value = value;
    newNode->link = node != NULL ? node : NULL;
    return newNode;
}

void traverseAll(struct LinkedNode *headNode)
{
    struct LinkedNode *tmp = headNode;
    printf("\n");
    while (tmp->link != NULL)
    {
        // printNode(tmp);
        printf("%d --> ", tmp->value);
        tmp = tmp->link;
    }
    // printNode(tmp);
    printf("%d --> ", tmp->value);
}

void insertAt(struct LinkedNode** headNode, int index, int value)
{
    if (index < 0)
        return;
    struct LinkedNode *tmp = *headNode;
    int count = 0;
    while (tmp->link != NULL && count < index - 1 && index > 0)
    {
        tmp = tmp->link;
        count++;
    }

    if (tmp->link == NULL && count < index - 1 && index > 0)
        printf("Index out of range");
    else if (tmp->link != NULL && count == index - 1 && index > 0)
        tmp->link = createNodePointer(value, tmp->link);
    else if (index == 0)
        *headNode = createNodePointer(value, *headNode);
    else if (tmp->link == NULL && count == index - 1)
        tmp->link = createNodePointer(value, NULL);
}

void deleteAt(struct LinkedNode** headNode, int index)
{
    if (index < 0)
        return;
    struct LinkedNode* tmp = *headNode, *tmp2;
    int count = 0;
    while (tmp->link!=NULL && count < index - 1 && index > 0)
    {
        tmp = tmp->link;
        count++;
    }
    if (tmp->link==NULL && count <= index - 1 && index > 0)
        printf("Index is out of range");
    else if (tmp->link!=NULL && count == index - 1 && index > 0)
    {
        tmp2 = tmp->link;
        tmp->link = tmp2->link;
        free(tmp2);
    }
    else if (tmp->link!=NULL && index == 0)
    {
        *headNode = tmp->link;
        free(tmp);
    }
}

int readAt(struct LinkedNode *headNode, int index)
{
    if (index<0) return 0;
    int count = 0;
    struct LinkedNode *tmp = headNode;
    while(tmp->link!=NULL && count < index)
    {
        tmp = tmp->link;
        count++;
    }
    return tmp->value;
}

void writeAt(struct LinkedNode *headNode, int index, int value)
{
    if (index<0) return;
    int count = 0;
    struct LinkedNode *tmp = headNode;
    while(tmp->link!=NULL && count < index)
    {
        tmp = tmp->link;
        count++;
    }
    tmp->value = value;
}


int main()
{
    /*
    struct LinkedNode l1, l2, l3;
    l1.value = 3;
    l2.value = 4;
    l3.value = 5;

    printf("l1: %d\n", l1.value);
    printf("l2: %d\n", l2.value);
    printf("l3: %d\n", l3.value);
    printf("l1 (address): %x\n", &l1);
    printf("l2 (address): %x\n", &l2);
    printf("l3 (address): %x\n", &l3);
    printf("&l2 - &11 : (hex)%x --- (int)%d\n", &l1-&l2, &l1-&l2);
    printf("sizeof(l1): %d \n", sizeof(l1));
    printf("sizeof(l2): %d \n", sizeof(l2));
    printf("sizeof(l3): %d \n", sizeof(l3));

    l1.link = &l2;
    l2.link = &l3;count < index - 1
    l3.link = NULL;

    int nodeLen = 4;

    struct LinkedNode* head = createNodes(3);
    */
    // printf("heello: %d", abs(-234));

    struct LinkedNode *headNode = createNodes(10);
    printf("\noriginal headNode: %x\n", headNode);

    // original linked list
    traverseAll(headNode);

    // Insertion
    insertAt(&headNode, 0, 14);

    printf("\n(insertAt) headNode: %x", headNode);

    traverseAll(headNode);

    // Deletion
    deleteAt(&headNode, 0);

    printf("\n(deleteAt) headNode: %x", headNode);

    traverseAll(headNode);

    // Writing
    writeAt(headNode, 3, 97);

    printf("\n(writeAt) headNode: %x", headNode);

    traverseAll(headNode);

    // Reading
    int value = readAt(headNode, 3);

    printf("\n(readAt) headNode: %x", headNode);
    printf("\n(readAt) value returned: %d", value);

    traverseAll(headNode);


    return 0;
}