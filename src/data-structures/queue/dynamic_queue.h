#ifndef DYNAMIC_QUEUE_H_INCLUDED
#define DYNAMIC_QUEUE_H_INCLUDED

typedef enum{ false, true} bool;

typedef int key_t;

typedef struct {
  key_t value;
} data_t;

typedef struct node *nodeQueuePtr;

typedef struct node {
  data_t data;
  nodeQueuePtr next;
} node_t;

#define QUEUE_NODE_SIZE sizeof(node_t)

typedef struct {
  nodeQueuePtr head, tail;
} DynamicQueue_t;

void queueinit(DynamicQueue_t *);
bool isQueueEmpty(DynamicQueue_t);
void put(data_t, DynamicQueue_t *);
bool get(DynamicQueue_t *, data_t *);
void printQueue(DynamicQueue_t *);

#endif