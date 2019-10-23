#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"


void queueinit(CircularQueue_t *queue) {
  queue->head = START_QUEUE_ARRANJMENT;
  queue->tail = queue->head;
}

bool isQueueEmpty(CircularQueue_t queue) {
  return (queue.head == queue.tail);
}

bool put(data_t data, CircularQueue_t *queue) {
  if(queue->tail % (QUEUE_SIZE_MAX + 1) == queue->head) {
    return false;
  } else {
    queue->data[ queue->tail - 1] = data;
    queue->tail = queue->tail % (QUEUE_SIZE_MAX + 1);
    return true;
  }
}

bool get(CircularQueue_t *queue, data_t *removedData) {
  if(isQueueEmpty(*queue)) {
    return false;
    removedData = NULL;
  } else {
    *removedData = queue->data[ queue->head ];
    queue->head = queue->head % (QUEUE_SIZE_MAX + 1);
    return true;
  }
}

void printQueue(CircularQueue_t queue) {
  if(isQueueEmpty(queue)) {
    printf("\nQueue is Empty!\n");
  } else {
    printf("\n\n*********************PRINTING THE QUEUE ITEMS*********************\n");
    nodeCircularQueuePtr_t queuePosition = queue.head;
    while(queuePosition != queue.tail) {
      printf("| %d ", queue.data[ queuePosition - 1].value);
      queuePosition = queuePosition % (QUEUE_SIZE_MAX + 1);
    }
    printf(" |");
    printf("\n***************************FINISH PRINT***************************\n\n");
  }
}

bool jumpTheQueue(CircularQueue_t *queue, data_t data) {
  bool isPiercedQueue = false;
  if(isQueueEmpty(*queue)) {
    put(data, queue);
    isPiercedQueue = true;
  } else if(queue->tail % QUEUE_SIZE_MAX == queue->head) {
    printf("\nQueue is Full!\n");
  } else {
    queue->head = queue->head % (QUEUE_SIZE_MAX + 1);
    queue->data[ queue->head ] = data;
    isPiercedQueue = true;
  }
  return isPiercedQueue;
}