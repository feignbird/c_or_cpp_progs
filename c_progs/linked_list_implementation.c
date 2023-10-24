#include <stdio.h>
#include <stdlib.h>
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
    int value;               // 8 bytes
    struct LinkedNode *link; // 8 bytes
};

void printNode(struct LinkedNode *node)
{
    printf("\nNode value:(%d) link:(%x)\n", node->value, node->link);
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