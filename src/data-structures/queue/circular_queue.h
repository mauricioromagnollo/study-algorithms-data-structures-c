#ifndef CIRCUAR_QUEUE_H_INCLUDED
#define CIRCULAR_QUEUE_H_INCLUDED

typedef enum{ false, true} bool;

#define QUEUE_SIZE_MAX 10
#define START_QUEUE_ARRANJMENT 1

typedef int nodeCircularQueuePtr_t;
typedef int key_t;

typedef struct {
  key_t value;
} data_t;

typedef struct {
  data_t data[ QUEUE_SIZE_MAX ];
  nodeCircularQueuePtr_t head, tail;
} CircularQueue_t;

void queueinit(CircularQueue_t *);
bool isQueueEmpty(CircularQueue_t);
bool put(data_t, CircularQueue_t *);
bool get(CircularQueue_t *, data_t *);
void printQueue(CircularQueue_t);
bool jumpTheQueue(CircularQueue_t *, data_t);

#endif