#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

typedef enum { false, true } bool;

typedef int key_t;
typedef unsigned int counter_t;

typedef struct {
  key_t key;
} item_t;

typedef struct node *nodePtrLinkedList_t;

typedef struct node {
  item_t item;
  nodePtrLinkedList_t next;
} nodeLinkedList_t;

#define LINKED_LIST_NODE_SIZE sizeof(nodeLinkedList_t)

typedef struct {
  nodePtrLinkedList_t first, last;
} LinkedList_t;

/** Linked List Interface */
void createLinkedList(LinkedList_t *);
bool isEmptyList(LinkedList_t);
void insertItemLinkedList(item_t, LinkedList_t *);
void insertOrderedItemLinkedList(item_t, LinkedList_t *);
bool removeItemLinkedList(nodePtrLinkedList_t, LinkedList_t *, item_t *);
nodePtrLinkedList_t searchItemLinkedList(item_t, LinkedList_t *);
void printLinkedList(LinkedList_t);
void freeLinkedList(LinkedList_t *);
// counter_t countNodesLinkedList(LinkedList_t);

#endif