#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"

void queueinit(StaticQueue_t *queue) {
  queue->head = START_QUEUE_ARRANJMENT;
  queue->tail = queue->head;
}

bool isQueueEmpty(StaticQueue_t queue) {
  return (queue.head == queue.tail);
}

void put(data_t data, StaticQueue_t *queue) {
  if(queue->tail % (QUEUE_SIZE_MAX + 1) == queue->head) {
    printf("\nQueue is Full!\n");
  } else {
    queue->data[ queue->tail - 1] = data;
    queue->tail = queue->head % (QUEUE_SIZE_MAX + 1);
  }
}

bool get(StaticQueue_t *queue, data_t *removedData) {
  if(isQueueEmpty(*queue)) {
    removedData = NULL;
    printf("\nQueue is Empty!\n");
    return false;
  } else {
    *removedData = queue->data[ queue->head - 1];
    queue->head = queue->head % (QUEUE_SIZE_MAX + 1);
    return true;
  }
}

void printQueue(StaticQueue_t queue) {
  if(isQueueEmpty(queue)) {
    printf("\nQueue is Empty!\n");
  } else {
    nodeQueuePtr_t queuePosition = queue.head;
    printf("\n\n*********************PRINTING STATIC QUEUE ITEMS*********************\n");
    while(queuePosition != queue.tail) {
      printf("| %d ", queue.data[ queuePosition - 1]);
      queuePosition = queuePosition % (QUEUE_SIZE_MAX + 1);
    }
    printf("\n***************************FINISH PRINT***************************\n\n"); 
  }
}