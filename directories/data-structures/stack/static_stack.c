#include <stdio.h>
#include <stdlib.h>
#include "static_stack.h"

void stackinit(StaticStack_t *stack) {
  stack->head = 0;
}

bool isStackEmpty(StaticStack_t stack) {
  return (stack.head == 0);
} 

bool push(data_t value, StaticStack_t *stack) {
  bool isWasStacked = false;
  
  if(stack->head == STACK_SIZE_MAX) {
    printf("\nThe Stack Is Full!\n");
  } else {
    stack->head++;
    stack->data[ stack->head - 1 ] = value;
    isWasStacked = true;
  }
  return isWasStacked;
}

bool pop(StaticStack_t *stack, data_t *valueRemoved) {
  bool isWasUnstacked = false;

  if(isStackEmpty(*stack)) {
    printf("\nThe Stack Is Empty!\n");    
  } else {
    *valueRemoved = stack->data[ stack->head-- ];
    isWasUnstacked = true;
  }
  return isWasUnstacked;
}

void printStack(StaticStack_t stack) {
  
  if(isStackEmpty(stack)) {
    printf("\nThe Stack Is Empty!\n");    
    return;
  }
  
  nodeStack_t dataPosition = (stack.head - 1);

  printf("\n\n*********************PRINTING THE STACK ITEMS*********************\n");
  while(dataPosition >= 0) {
    printf("%d\n", stack.data[dataPosition]);
    dataPosition--;
  }
  printf("***************************FINISH PRINT***************************\n\n");
}