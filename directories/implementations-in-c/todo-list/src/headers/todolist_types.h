#ifndef TODOLIST_TYPES_H_INCLUDED
#define TODOLIST_TYPES_H_INCLUDED

#include "date_time_types.h"
#include "boolean_type.h"

typedef char description_t[30];
typedef char name_t[15];
typedef char date_t[12];
typedef unsigned int position_t, id_t;

/**
 * Tipo Tarefa
 */
typedef struct {
  id_t id;
  description_t description;
  date_t dateInit;
  date_t dateEnd;
  bool isDone; // estado
} task_t;

/**
 * Tipo Lista de Tarefas
 */
typedef struct {
  name_t name;
  description_t description;
  task_t *tasks;
} list_t;


#endif // TODOLIST_TYPES_H_INCLUDED
