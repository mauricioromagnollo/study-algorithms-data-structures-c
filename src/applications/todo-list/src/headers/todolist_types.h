#ifndef TODOLIST_TYPES_H_INCLUDED
#define TODOLIST_TYPES_H_INCLUDED

#include "date_time_types.h"
#include "boolean_type.h"

typedef char description_t[30];
typedef char name_t[15];
typedef char date_t[12];
typedef unsigned int position_t, id_t;

typedef struct {
  id_t id;
  description_t description;
  date_t dateInit;
  date_t dateEnd;
  bool isDone;
}task_t;

typedef struct node_task_list *task_list_ptr_t;

typedef struct node_task_list {
  task_t task;
  task_list_ptr_t next;
}node_task_list_t;

typedef struct {
  node_task_list_t first, last;
}task_list_t;

typedef struct {
  name_t name;
  description_t description;
  task_list_t task_list;
}todolist_t;

typedef struct node_todo_list *node_todo_list_ptr_t;

typedef struct node_todo_list {
  todolist_t todolist;
  node_todo_list_ptr_t next;
}node_todo_list_t;

typedef struct {
  node_todo_list_t first, last;
}todolists_t;

#define TASK_LIST_NODE_SIZE sizeof(node_task_list_t)
#define TODO_LIST_NODE_SIZE sizeof(node_todo_list_t)

#endif // TODOLIST_TYPES_H_INCLUDED
