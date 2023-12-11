#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct LinkedNode
{
    int key;
    struct LinkedNode *link;
};

typedef struct LinkedNode* Node;

Node getNode(int value);
int readAt(Node HEAD, int index);
Node getNodeAt(Node HEAD, int index);
void writeAt(Node HEAD, int index, int value);
void insertNodeAt(Node *HEAD, Node node, int index);
void insertAt(Node *HEAD, int value, int index);
void deleteAt(Node *HEAD, int index);
Node createLinkedList(int *arr, int size);
void printLL(Node headNode);

#endif