#ifndef STATIC_QUEUE_H_INCLUDED
#define STATIC_QUEUE_H_INCLUDED

typedef enum{ false, true} bool;

#define QUEUE_SIZE_MAX 10
#define START_QUEUE_ARRANJMENT 1

typedef int key_t;
typedef int nodeQueuePtr_t;

typedef struct {
  key_t value;
} data_t;

typedef struct {
  data_t data[QUEUE_SIZE_MAX];
  nodeQueuePtr_t head, tail;
} StaticQueue_t;

void queueinit(StaticQueue_t *);
bool isQueueEmpty(StaticQueue_t);
void put(data_t, StaticQueue_t *);
bool get(StaticQueue_t *, data_t *);
void printQueue(StaticQueue_t);

#endif