#ifndef DYNAMIC_STACK_H_INCLUDED
#define DYNAMIC_STACK_H_INCLUDED

typedef enum { false, true } bool;

typedef int key_t;

typedef struct {
  key_t value;
} data_t;

typedef struct node *nodeStackPtr_t;

typedef struct node {
  data_t data;
  nodeStackPtr_t next;
} nodeDynamicStack_t;

#define DYNAMIC_STACK_NODE_SIZE sizeof(nodeDynamicStack_t)

typedef struct {
  nodeStackPtr_t base, head;
} DynamicStack_t;

void stackinit(DynamicStack_t *);
bool isStackEmpty(DynamicStack_t);
void push(data_t, DynamicStack_t *);
bool pop(DynamicStack_t *, data_t *);
void printStack(DynamicStack_t);
data_t getStackHeadData(DynamicStack_t *);
void printStackBaseAndHead(DynamicStack_t *);
nodeStackPtr_t getStackHeadReference(DynamicStack_t);

#endif