#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

void createDLinkedList(DoublyLinkedList_t *list) {
  list->first = (nodePtrDLinkedList_t)malloc(DOUBLY_LINKED_LIST_NODE_SIZE);
  list->last = list->first;
  list->first->next = NULL;
  list->last->previous = NULL;
}

bool isDLinkedListEmpty(DoublyLinkedList_t list) {
  return (list.first == list.last);
}

void insertItemDLinkedList(item_t item, DoublyLinkedList_t *list) {
  list->last->next = (nodePtrDLinkedList_t)malloc(DOUBLY_LINKED_LIST_NODE_SIZE);
  list->last->next->item = item;
  list->last->next->previous = list->last;
  list->last = list->last->next;
  list->last->next = NULL;
}

bool removeItemDLinkedList(nodePtrDLinkedList_t nodeReference, DoublyLinkedList_t *list, item_t *itemToBeRemoved) {
  bool isItemExist = false;
  if(isDLinkedListEmpty(*list) || nodeReference == NULL || nodeReference->next == NULL) {
    itemToBeRemoved = NULL;
  } else {
    *itemToBeRemoved = nodeReference->item;
    nodeReference = nodeReference->next->next;
    if(nodeReference->next == NULL) {
      list->last = nodeReference;
    } else {
      nodeReference->next->previous = nodeReference;
    }
    free(nodeReference);
    isItemExist = true;
  }
  return isItemExist;
}

void invertedPrintDLinkedList(DoublyLinkedList_t *list) {
  nodePtrDLinkedList_t node = list->last;
  while(node) {
    printf("| %d", node->item.key);
    node = node->previous;
  }
  printf("|");
}