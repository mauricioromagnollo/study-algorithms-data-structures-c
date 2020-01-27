#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void createLinkedList(LinkedList_t *list) {
  list->first = (nodePtrLinkedList_t)malloc(LINKED_LIST_NODE_SIZE);
  list->last = list->first;
  list->last->next = NULL;
}

bool isEmptyLinkedList(LinkedList_t list) {
  return (list.first == list.last);  
}

void insertItemLinkedList(item_t item, LinkedList_t *list) {
  list->last->next = (nodePtrLinkedList_t)malloc(LINKED_LIST_NODE_SIZE);
  list->last = list->last->next;
  list->last->item = item;
  list->last->next = NULL;
}

void insertOrderedItemLinkedList(item_t item, LinkedList_t *list) {
  if(isEmptyLinkedList(*list)) {
    insertItemList(item, &list);
  } else {
    nodePtrLinkedList_t node = list->first;
    nodePtrLinkedList_t nextNode = NULL;

    while(node != NULL) {
      if(node->next->item.key >= item.key) {
        nextNode = node->next;
        node->next = (nodePtrLinkedList_t)malloc(LINKED_LIST_NODE_SIZE);
        node->next->item = item;
        node->next = nextNode;
        return;
      }
      node = node->next;
    }
    node->next = (nodePtrLinkedList_t)malloc(LINKED_LIST_NODE_SIZE);
    node->next->item = item;
    node->next->next = NULL;
  }
}

bool removeItemLinkedList(nodePtrLinkedList_t previousNode, LinkedList_t *list, item_t *itemRemoved) {
  bool isItemExist = false;

  if(isEmptyLinkedList(*list) || previousNode == NULL || previousNode->next == NULL) {
    itemRemoved = NULL;
  } else {
    nodePtrLinkedList_t nextNode = previousNode->next;
    *itemRemoved = nextNode->item;
    previousNode->next = nextNode->next;

    if(previousNode->next == NULL) {
      list->last = previousNode;
    }
    free(nextNode);
    isItemExist = true;
  }
  return isItemExist;
}

nodePtrLinkedList_t searchItemLinkedList(item_t itemToBeSearched, LinkedList_t *list) {
  nodePtrLinkedList_t node = list->first;
  while(node != NULL) {
    if(node->next->item.key == itemToBeSearched.key) {
      return node;
    }
    node = node->next;
  }
  return NULL;
}

void printLinkedList(LinkedList_t list) {
  nodePtrLinkedList_t node = list.first->next;
  printf("\n\n*************** PRINTING LINKED LIST *************\n");
  while(node) {
    printf("| %d ", node->item.key);
    node = node->next;
  }
  printf("|");
  printf("\n*************************** END ************************\n");
}

void freeLinkedList(LinkedList_t *list) {
  if(isEmptyLinkedList(*list)) {
    printf("\nThe List is already empty!\n");
    return;
  } else {
    nodePtrLinkedList_t currentNode, nextNode;
    currentNode = list->first;   
    while(currentNode) {
      nextNode = currentNode->next;
      free(currentNode);
      currentNode = nextNode;
    }
    printf("\nNow, the list is empty!\n");
  }
}