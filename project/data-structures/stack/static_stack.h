#ifndef STATIC_STACK_H_INCLUDED
#define STATIC_STACK_H_INCLUDED

typedef enum { false, true } bool;

#define STACK_SIZE_MAX 10

typedef int key_t;
typedef int nodeStack_t;

typedef struct {
  key_t value;
} data_t;

typedef struct {
  data_t data[STACK_SIZE_MAX];
  nodeStack_t head;
} StaticStack_t;

void stackinit(StaticStack_t *);
bool isStackEmpty(StaticStack_t);
bool push(data_t, StaticStack_t *);
bool pop(StaticStack_t *, data_t *);
void printStack(StaticStack_t);

#endif