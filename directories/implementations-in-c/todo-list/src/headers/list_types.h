#ifndef LIST_TYPES_H_INCLUDED
#define LIST_TYPES_H_INCLUDED

#include "global_types.h"

typedef char description_t[30];
typedef char name_t[15];
typedef char date_t[12];
typedef unsigned int position_t;

/**
 * Tipo Tarefa
 */
typedef struct {
  position_t position;
  description_t description;
  date_t *dateInit;
  date_t *dateEnd;
  bool isDone; // estado
} task_t;

/**
 * Tipo Lista de Tarefas
 */
typedef struct {
  name_t name;
  description_t description;
  task_t *taskList;
} todolist_t;


#endif
