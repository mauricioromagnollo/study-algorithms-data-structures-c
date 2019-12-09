#include <stdio.h>
#include <stdlib.h>
#include "static_list.h"

void createStaticList(StaticList_t *list) {
  list->first = START_OF_ARRANJMENT;
  list->last = list->first;
}

bool isStaticListEmpty(StaticList_t list) {
  return (list.first == list.last);
}

bool insertItemStaticList(item_t item, StaticList_t *list) {
  if(list->last > STATIC_LIST_SIZE_MAX) {
    return (false);
  } else {
    list->item[ list->last - 1 ] = item;
    list->last++;
    return (true);
  }
}

bool removeItemStaticList(staticListNodePtr_t itemToBeRemovedPosition, StaticList_t *list, item_t *itemRemoved) {
  bool isItemExist = false;
  if(isStaticListEmpty(*list) || itemToBeRemovedPosition >= list->last) {
    itemRemoved = NULL;
  } else {
    *itemRemoved = list->item[ itemToBeRemovedPosition - 1];
    list->last--;
    for(staticListNodePtr_t node = itemToBeRemovedPosition; node < list->last; node++) {
      list->item[ node - 1 ] = list->item[ node ];
    }
    isItemExist = true;
  }
  return isItemExist;
}

void printStaticList(StaticList_t list) {
  printf("\n************* PRINTING STATIC LIST *************\n");
  for(staticListNodePtr_t node = (list.first - 1); node <= (list.last - 2); node++) {
    printf("| %d ",list.item[ node ].key);
  }
  printf("|\n");
  printf("************* END *************\n");
}