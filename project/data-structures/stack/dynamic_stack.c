#include <stdio.h>
#include <stdlib.h>
#include "dynamic_stack.h"

void stackinit(DynamicStack_t *stack) {
  stack->head = (nodeStackPtr_t)malloc(DYNAMIC_STACK_NODE_SIZE);
  stack->base = stack->head;
  stack->head->next = NULL;
}

bool isStackEmpty(DynamicStack_t stack) {
  return (stack.head == stack.base);
}

void push(data_t data, DynamicStack_t *stack) {
  nodeStackPtr_t node;
  node = (nodeStackPtr_t)malloc(DYNAMIC_STACK_NODE_SIZE);
  stack->head->data = data;
  node->next = stack->head;
  stack->head = node;
} 

bool pop(DynamicStack_t *stack, data_t *removedData) {
  bool isUnwrapped = false;
  
  if(isStackEmpty(*stack)) {
    removedData = NULL;
  } else {
    nodeStackPtr_t node = stack->head;
    stack->head = node->next;
    *removedData = node->data;
    free(node);
    isUnwrapped = true;
  }
  
  return isUnwrapped;
}

void printStack(DynamicStack_t stack) {
  if(isStackEmpty(stack)) {
    printf("\nThe Stack is Empty!\n");
  } else {
    nodeStackPtr_t node = stack.head;
    printf("\n\n*********************PRINTING THE STACK dataS*********************\n");
    while(node->next != NULL) {
      printf("%d\n",node->next->data.value);
      node = node->next;
    }
    printf("***************************FINISH PRINT***************************\n\n");
  }
}

data_t getStackHeadData(DynamicStack_t *stack) {
  if(isStackEmpty(*stack)) {
    printf("\nThe Stack is Empty!\n");
    return;
  }
  return (stack->head->next->data);
}

void printStackBaseAndHead(DynamicStack_t *stack) {
  printf("\nhead -> |%d|\n", stack->head->next->data.value);
  printf("\nBase -> |%d|\n", stack->base->next->data.value);
}

nodeStackPtr_t getStackHeadReference(DynamicStack_t *stack) {
  return (stack->head);
}