#ifndef DOUBLY_LINKED_LIST_H_INCLUDED
#define DOUBLY_LINKED_LIST_H_INCLUDED

typedef enum { false, true } bool;

typedef int key_t;
typedef unsigned int counter_t;

typedef struct {
  key_t key;
} item_t;

typedef struct node *nodePtrDLinkedList_t;

typedef struct node {
  item_t item;
  nodePtrDLinkedList_t next, previous;
} nodeDLinkedList_t;

#define DOUBLY_LINKED_LIST_NODE_SIZE sizeof(nodeDLinkedList_t)

typedef struct {
  nodePtrDLinkedList_t first, last;
} DoublyLinkedList_t;

void createDLinkedList(DoublyLinkedList_t *);
bool isDLinkedListEmpty(DoublyLinkedList_t);
void insertItemDLinkedList(item_t, DoublyLinkedList_t *);
bool removeItemDLinkedList(nodePtrDLinkedList_t, DoublyLinkedList_t *, item_t *);
// void printDLinkedList(DoublyLinkedList_t);
void invertedPrintDLinkedList(DoublyLinkedList_t *);
// counter_t countDLinkedListNodes(DoublyLinkedList_t *);
// nodePtrDLinkedList_t searchItemDLinkedList(item_t, DoublyLinkedList_t *);


#endif