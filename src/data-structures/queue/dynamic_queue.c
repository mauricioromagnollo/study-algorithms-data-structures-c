#include <stdio.h>
#include <stdlib.h>
#include "dynamic_queue.h"

void queueinit(DynamicQueue_t *queue) {
  queue->head = (nodeQueuePtr) malloc (QUEUE_NODE_SIZE);
  queue->tail = queue->head;
  queue->head->next = NULL;
}

bool isQueueEmpty(DynamicQueue_t queue) {
  return (queue.head == queue.tail);
}

void put(data_t data, DynamicQueue_t *queue) {
  queue->tail->next = (nodeQueuePtr) malloc (QUEUE_NODE_SIZE);
  queue->tail = queue->tail->next;
  queue->tail->data = data;
  queue->tail->next = NULL;
}

bool get(DynamicQueue_t *queue, data_t *removedData) {
  if(isQueueEmpty(*queue)) {
    removedData = NULL;
    return false;
  } else {
    nodeQueuePtr node = queue->head;
    queue->head = queue->head->next;
    *removedData = queue->head->data;
    free(node);
    return true;
  }
}

void printQueue(DynamicQueue_t *queue) {
  if(isQueueEmpty(*queue)) {
    printf("\nQueue is Empty!\n");
  } else {
    nodeQueuePtr node = queue->head;
    printf("\n\n*********************PRINTING THE QUEUE *********************\n");
    while(node->next != NULL) {
      printf("| %d ", node->next->data.value);
      node = node->next;
    }
    printf(" |");
    printf("\n***************************FINISH PRINT***************************\n\n");
  }
}