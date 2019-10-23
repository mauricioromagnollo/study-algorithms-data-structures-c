#ifndef STATIC_LIST_H_INCLUDED
#define STATIC_LIST_H_INCLUDED

typedef enum { false, true } bool;

#define STATIC_LIST_SIZE_MAX 10
#define START_OF_ARRANJMENT 1

typedef int key_t;
typedef int staticListNodePtr_t;

typedef struct {
  key_t key;
} item_t;

typedef struct {
  item_t item[STATIC_LIST_SIZE_MAX];
  staticListNodePtr_t first, last;
} StaticList_t;

void createStaticList(StaticList_t *);
bool isStaticListEmpty(StaticList_t);
bool insertItemStaticList(item_t, StaticList_t *);
bool removeItemStaticList(staticListNodePtr_t, StaticList_t *, item_t *);
void printStaticList(StaticList_t);

#endif